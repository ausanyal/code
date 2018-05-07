#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define READ_SIZE 8

class MyRead {
  private:
    string filename;
    int readSoFar = 0;
  public:
    MyRead(string f) : filename(f) {}
    int ReadFixed(char *buf);
    int Read(char* buf, int n);
};

// Caller to allocate memory for buffer.
int MyRead::ReadFixed(char *buffer) {
  ifstream ifs(filename, ifstream::in | ifstream::binary);

  //ifs.seekg(0, ifs.end);
  //cout << "file size " << ifs.tellg() << " bytes \n";
  cout << "Seeking to " << readSoFar << "\n";
  ifs.seekg(readSoFar, ifs.beg);

  ifs.read(buffer, READ_SIZE);
  int len = ifs.gcount();
  if (len == 0) return -1;

  // Keep track of bytes reads.
  readSoFar += len;

  buffer[len+1] = '\0';
  //cout << buffer << " size " << strlen(buffer) << "\n";
  //memcpy(buf, buffer, len);
  return len;
}

int MyRead::Read(char* buf, int n) {
  static int readSoFar = 0;
  static char readBuff[READ_SIZE] = {'\0'};

  int read_this_time = 0;
  int to_read = n + readSoFar;

  cout << "to_read " << to_read << "\n";

  // Before reading from file, lets see if anything in cache.
  if (readBuff[0] != '\0') {
    int left = n;
    int rb_len = strlen(readBuff);

    cout << "readBuff " << readBuff << " len " << rb_len
      << " left " << left << "\n";

    // There is more data to be read than there is in cache.
    if (rb_len < left) {
     memcpy(buf + readSoFar, readBuff, rb_len);
     readSoFar += rb_len;
     read_this_time += rb_len;
     memset(readBuff, 0, rb_len);
     cout << __LINE__ << ": Buf " << buf << "\n";
    } else {
     int delta = rb_len - left;
     memcpy(buf + readSoFar, readBuff, left);
     readSoFar += left;
     read_this_time += left;
     memcpy(readBuff, readBuff + left, delta);
     memset(readBuff + delta, 0, left);
     cout << __LINE__ << ": Buf " << buf << "\n";
    }
  }

  char buffer[READ_SIZE];
  while(readSoFar < to_read) {
    int len = ReadFixed(buffer);
    if (len == -1) break;

    // Read the min of data returned or data left to be read.
    // If we read more data than we needed, then cache it.
    int m = min(len, to_read - readSoFar);
    cout << "to_read - readSoFar " << to_read - readSoFar << "\n";

    memcpy(buf + readSoFar, buffer, m);
    readSoFar += m;
    read_this_time += m;

    // If we couldnt collect all data returned, then cache it.
    if (len > m) {
      memcpy(readBuff, buffer + m, len - m);
      cout << "Cached " << readBuff << "\n";;
    }

    cout << "read_this_time " << read_this_time 
      << " readSoFar " << readSoFar << "\n";
  }
  cout << __LINE__ << ": Buf " << buf << "\n";
  return read_this_time;
}

int main() {
  MyRead r("file2");
  char *s = new char[20000];
  int t = r.Read(s, 18);
  //memset(s, 0, 20000);
  cout << "main s " << s << "\n";
  r.Read(s, 12);
  cout << "main s " << s << "\n";
  r.Read(s, 1);
  cout << "main s " << s << "\n";
  return 0;
}
