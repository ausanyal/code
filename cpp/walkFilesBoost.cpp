#include <iostream>
#include <boost/regex.hpp>
#include <boost/filesystem.hpp>

using namespace std;

void getMatchingFiles(const string& target_path, const string& filePattern, vector<string>& matchingFiles) {
    //const boost::regex my_filter( "somefiles.*\.txt" );
    //string regexPattern = ".*" + filePattern + ".*\";
    string regexPattern = filePattern;
    const boost::regex my_filter(filePattern);
    boost::filesystem::directory_iterator end_itr; // Default ctor yields past-the-end
    for( boost::filesystem::directory_iterator i( target_path ); i != end_itr; ++i )
    {
        // Skip if not a file
        if( !boost::filesystem::is_regular_file( i->status() ) ) continue;

        boost::smatch what;

        // Skip if no match for V2:
        //if( !boost::regex_match( i->lmeeaf(), what, my_filter ) ) continue;
        //if( !boost::regex_match( i->filename(), what, my_filter ) ) continue;
        string current_file = i->path().string();
        if( !boost::regex_match( current_file, what, my_filter ) ) continue;
        // For V3:
        //if( !boost::regex_match( i->path().filename(), what, my_filter ) ) continue;

        // File matches, store it
        //matchingFiles.push_back( i->leaf() );
        matchingFiles.push_back( current_file );
    }
}

int main()
{
    return 0;
}
