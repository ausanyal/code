//https://www.hackerrank.com/challenges/saveprincess?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign

#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> point;

void moveStep(vector<string>& grid) {
    
}

void locateMandP(vector<string>& grid, point& mLoc, point& pLoc) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid.size(); j++) {
            if (grid[i][j] == 'm') { 
                mLoc.first = i;
                mLoc.second = j;
            }
            if (grid[i][j] == 'p') { 
                pLoc.first = i;
                pLoc.second = j;
            }
        }
    }     
}

void printPath(const vector<point>& path) {
  cout << "Path: \n";
  for (const auto& point : path) {
    cout << point.first << ":" << point.second << " ";
  }
  cout << "\n";
}

vector<point> shortestPath(vector<point>& v1, vector<point>& v2,
                 vector<point>& v3, vector<point>& v4) {
  int s1 = v1.size();
  int s2 = v2.size();
  int s3 = v3.size();
  int s4 = v4.size();
  if (s1 > 0 && s1 <= s2 && s1 <= s3 && s1 <= s4) return v1;
  else if (s2 > 0 && s2 <= s1 && s2 <= s3 && s2 <= s4) return v2;
  else if (s3 > 0 && s3 <= s1 && s3 <= s2 && s1 <= s4) return v3;
  else if (s4 > 0 && s4 <= s1 && s4 <= s2 && s4 <= s3) return v4;
  else return vector<point>();
}


bool pointInPathOrpointOutOfRange(vector<string>& grid, const point& p,
                                  const vector<point>& path) {
  if (p.first >= grid.size() || p.second >= grid.size()) {
    cout << "Reached end of grid \n";
    printPath(path);
    return true;
  }
  for (const point& pt : path) {
    if (pt == p) return true;
  }
  return false;
}

vector<point> searchPath(vector<string>& grid, point mLoc, point pLoc,
                         int pathSz, vector<point> path) {
  if (mLoc.first >= grid.size() || mLoc.second >= grid.size()) {
    cout << "Reached end of grid \n";
    printPath(path);
    return vector<point>();
  }
  if (mLoc == pLoc) {
    cout << "Found princess. Path sz: " << pathSz << "\n";
    printPath(path);
    return path;
  }
  cout << "I am at : " << mLoc.first << ":" << mLoc.second << "\n";
  point nextMLocUp = make_pair(mLoc.first - 1, mLoc.second);
  point nextMLocLeft = make_pair(mLoc.first, mLoc.second - 1);
  point nextMLocDown = make_pair(mLoc.first + 1, mLoc.second);
  point nextMLocRight = make_pair(mLoc.first, mLoc.second + 1);

  vector<point> pathAppendedUp, pathAppendedDown, pathAppendedRight,
                pathAppendedLeft;

  if (!pointInPathOrpointOutOfRange(grid, nextMLocUp, path)) {
    pathAppendedUp = path;
    pathAppendedUp.push_back(nextMLocUp);
    pathAppendedUp = searchPath(grid, nextMLocUp, pLoc, pathSz + 1,
                                pathAppendedUp);
  }

  if (!pointInPathOrpointOutOfRange(grid, nextMLocDown, path)) {
    pathAppendedDown = path;
    pathAppendedDown.push_back(nextMLocDown);
    pathAppendedDown = searchPath(grid, nextMLocDown, pLoc, pathSz + 1,
                                  pathAppendedDown);
  }

  if (!pointInPathOrpointOutOfRange(grid, nextMLocRight, path)) {
    pathAppendedRight = path;
    pathAppendedRight.push_back(nextMLocRight);
    pathAppendedRight = searchPath(grid, nextMLocRight, pLoc, pathSz + 1,
                                   pathAppendedRight);
  }

  if (!pointInPathOrpointOutOfRange(grid, nextMLocLeft, path)) {
    pathAppendedLeft = path;
    pathAppendedLeft.push_back(nextMLocLeft);
    pathAppendedLeft = searchPath(grid, nextMLocLeft, pLoc, pathSz + 1,
                                  pathAppendedLeft);
  }

  return shortestPath(pathAppendedUp, pathAppendedDown,
                      pathAppendedRight, pathAppendedLeft);
}

void displayPathtoPrincess(int n, vector <string> grid){
    //your logic here
    point mLoc = make_pair(-1, -1);
    point pLoc = make_pair(-1, -1);
    locateMandP(grid, mLoc, pLoc);
    cout << "m is at: " << mLoc.first << ":" << mLoc.second << "\n";
    cout << "p is at: " << pLoc.first << ":" << pLoc.second << "\n";
    vector<point> path;
    int pathSz = 0;
    searchPath(grid, mLoc, pLoc, pathSz, path);
}
int main(void) {

    int m;
    vector <string> grid;

    /*
    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }
    */
    grid = {"---", "-m-", "p--"};
    displayPathtoPrincess(m,grid);

    return 0;
}

