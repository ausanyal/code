// https://leetcode.com/problems/reconstruct-itinerary/
/*
Given a list of airline tickets represented by pairs of departure and arrival
airports [from, to], reconstruct the itinerary in order. All of the tickets
belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that
has the smallest lexical order when read as a single string. For example, the
itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets =
[["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it
is larger in lexical order.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
  void printTickets(unordered_map<string, vector<string>> adjListDests) {
    for (auto it = adjListDests.cbegin(); it != adjListDests.cend(); it++) {
      cout << it->first;

      for (auto dests : it->second) {
        cout << "=>" << dests;
      }
      cout << endl;
    }
  }

  void getItinerary(unordered_map<string, vector<string>> &adjListDests,
                    unordered_map<string, string> visited, string visitAirport,
                    vector<string> &itinerary, int size) {
    auto f = adjListDests.find(visitAirport);
    if (f == adjListDests.end()) {
      cout << "Pushing " << visitAirport << endl;
      itinerary.push_back(visitAirport);
      return;
    }
    vector<string> &dests = f->second;
    // sort(dests.begin(), dests.end());
    for (auto &dest : dests) {
      // Skip if visited
      if (visited[dest] == visitAirport) {
        cout << "Skipping " << dest << " from " << visitAirport << endl;
        continue;
      }
      // itinerary.push_back(dest);
      visited[dest] = visitAirport;
      // dests.erase(dests.begin() + i);
      getItinerary(adjListDests, visited, dest, itinerary, size);
    }
    cout << "Pushing " << visitAirport << endl;
    itinerary.push_back(visitAirport);
  }

  vector<string> findItinerary2(vector<pair<string, string>> tickets) {
    vector<string> itinerary;
    unordered_map<string, vector<string>> adjListDests;
    unordered_map<string, string> visited;
    if (!tickets.size()) {
      return itinerary;
    }
    for (auto &ticket : tickets) {
      adjListDests[ticket.first].push_back(ticket.second);
    }
    // printTickets(adjListDests);
    itinerary.push_back("JFK");
    visited["JFK"] = "Begin";
    getItinerary(adjListDests, visited, "JFK", itinerary, tickets.size());
    return itinerary;
  }

  unordered_map<string, multiset<string>> targets;
  vector<string> route;

  void visit(string airport) {
    cout << "Visiting " << airport << endl;
    while (targets[airport].size()) {
      string next = *targets[airport].begin();
      targets[airport].erase(targets[airport].begin());
      visit(next);
    }
    route.push_back(airport);
  }

  vector<string> findItinerary(vector<pair<string, string>> tickets) {
    for (auto t : tickets) {
      targets[t.first].insert(t.second);
    }
    visit("JFK");
    return vector<string>(route.rbegin(), route.rend());
  }
};

int main() {
  Solution s;

  vector<pair<string, string>> tickets = {
      /*
            make_pair("MUC", "LHR"), make_pair("JFK", "MUC"), make_pair("SFO",
         "SJC"),
            make_pair("LHR", "SFO")};

      make_pair("JFK", "SFO"), make_pair("JFK", "ATL"),
      make_pair("SFO", "ATL"), make_pair("ATL", "JFK"),
      make_pair("ATL", "SFO"), make_pair("ATL", "XXX")};
      */

      make_pair("JFK", "KUL"), make_pair("JFK", "NRT"),
      make_pair("NRT", "JFK")};

  vector<string> itinerary = s.findItinerary(tickets);
  for (auto &t : itinerary)
    cout << t << "->";
  cout << endl;
  return 0;
}
