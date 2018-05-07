// https://leetcode.com/problems/subdomain-visit-count/description/

#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>

using namespace std;

class Solution {
  struct node {
    //list<node *> children;
    unordered_map<string, node*> children;
    string dom;
    int count;
    node() : count(0) {}
  };

  public:
  /*
     void testFn(string url) {
     size_t pos = 0;
     vector<string> res;
     cout << "-------------------------- \n";
     while((pos = url.find('.', pos+1)) != string::npos) {
     res.insert(res.begin(), url.substr(0, pos));
     }
     res.insert(res.begin(), url.substr(pos+1, string::npos));
     for (auto s : res) cout << s << " ";
     cout << "\n";
     cout << "-------------------------- \n";
     }
     */

    vector<string> parseUrl(string url) {
      vector<string> subdoms;
      size_t pos = 0;
      while ((pos = url.find_last_of('.')) != string::npos) {
        string ent = url.substr(pos+1, string::npos);
        if (subdoms.size()) {
          ent += '.';
          ent += subdoms[0];
        }
        subdoms.insert(subdoms.begin(), ent);
        url.erase(pos, string::npos);
      }

      if (url.size()) { 
        if (subdoms.size()) {
          url += '.';
          url += subdoms[0];
        }
        subdoms.insert(subdoms.begin(), url);
      }
      return subdoms;
    }

    vector<pair<vector<string>, int>> parseInput(vector<string> cpdomains) {
      vector<pair<vector<string>, int>> res;
      for (auto entry : cpdomains) {
        size_t pos = 0;
        if ((pos = entry.find(' ')) == string::npos) continue;
        int count = atoi(entry.substr(0, pos).c_str());
        string url = entry.substr(pos+1, string::npos);
        cout << "url " << url << ": " << count << "\n";
        vector<string> subdoms = parseUrl(url);
        res.push_back(make_pair(subdoms, count));
      }
      return res;
    }

    /*
    void buildTree(node *root, pair<vector<string>, int> entry) {
      auto v = entry.first;
      auto count = entry.second;
      for (int i = v.size()-1; i >= 0; --i) {
        string subdom = v[i];
        node *n = new node;
        n->dom = subdom; n->count = count;
        root->children.push_back(n);
      }
    }
    */

    vector<string> subdomainVisits(vector<string>& cpdomains) {
      /*
      node *root = new node();
      node *curr_node = root;
      vector<string> res;
      auto parsed = parseInput(cpdomains);
      printSubDoms(parsed);
      */

      vector<string> res;
      unordered_map<string, int> token_count;
      size_t pos = 0;
      for (string entry : cpdomains) {
        if ((pos = entry.find(' ')) == string::npos) continue;
        int count = atoi(entry.substr(0, pos).c_str());
        string url = entry.substr(pos+1);
        //cout << url << " : " << count << "\n";
        pos = string::npos;
        while((pos = url.find_last_of('.', pos-1)) != string::npos) {
          string e = url.substr(pos+1);
          token_count[e] += count;
          //cout << "Adding for " << e << " count " << token_count[e] << "\n";
          //url.erase(0, pos+1);
        }
        token_count[url] += count;
        //cout << "..Adding for " << url << " count " << token_count[url] << "\n";
      }
      for (auto t : token_count) {
        res.push_back(to_string(t.second) + ' ' + t.first);
      }

      return res;
    }

    void printSubDoms(vector<pair<vector<string>, int>> parsed) {
      for (auto entry : parsed) {
        auto v = entry.first;
        auto count = entry.second;
        for (auto subdoms : v) cout << subdoms << " ";
        cout << " : " << count << "\n";
      }
    }
};

int main() {
  Solution s;
  vector<string> cpdomains = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
  for (auto s : s.subdomainVisits(cpdomains)) {
    cout << s << ", ";
  }
  cout << "\n";

  return 0;
}
