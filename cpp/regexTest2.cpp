#include <iostream>
#include <string>
#include <regex>

using namespace std;

using uint32_t = unsigned int;
using TopoNodeId = uint32_t;

struct rsPathIntfInfo {
    uint32_t card;
    uint32_t port;
};

struct epgRsPathAttInfo {
    vector<uint32_t> nodes;
    vector<rsPathIntfInfo> intfInfos;
};

void scanNodeIfs(string fvRsPathAttTDn, epgRsPathAttInfo& rsPathAttInfo) {
    regex paths_regex("/protpaths-([0-9]+)-([0-9]+)/" "|" "/paths-([0-9]+)-?([0-9]+)?/");
    smatch paths_match;
    if (regex_search(fvRsPathAttTDn, paths_match, paths_regex)) {
        for (size_t i = 1; i < paths_match.size(); i++) {
            string pathsStr = paths_match[i].str();
            if (pathsStr.length()) {
                rsPathAttInfo.nodes.push_back(stoi(pathsStr));
            }
        }
        regex pathEpSearch("/pathep-\\[eth([0-9]+)/([0-9]+)\\](-\\[eth([0-9]+)/([0-9]+)\\])?");
        smatch pathEpMatch;
        if (regex_search(fvRsPathAttTDn, pathEpMatch, pathEpSearch)) {
            int idx = 0;
            rsPathIntfInfo intfInfo;
            for (size_t i = 1; i < pathEpMatch.size(); i++) {
                if (i == 3) continue;
                string pathEpStr = pathEpMatch[i].str();
                if (pathEpStr.length()) {  
                    if (!(idx%2)) { 
                        intfInfo.card = stoi(pathEpStr);
                    } else {
                        intfInfo.port = stoi(pathEpStr);
                    }
                    idx++;
                }
            }
            rsPathAttInfo.intfInfos.push_back(intfInfo);
        }
    }
}

int main()
{
    string lines[] = {"uni/tn-mgmt/ap-esx-mgmt-anp/epg-esx-mgmt-01-epg/rspathAtt-[topology/pod-1/protpaths-1031-1032/pathep-[aci-ucs-B-IfPolGrp]]",
                      "uni/tn-mgmt/ap-esx-mgmt-anp/epg-esx-mgmt-01-epg/rspathAtt-[topology/pod-1/protpaths-1031-1032/extprotpaths-1031-1032/pathep-[aci-ucs-B-IfPolGrp]]",
                      "uni/tn-mgmt/ap-esx-mgmt-anp/epg-esx-mgmt-01-epg/rspathAtt-[topology/pod-1/paths-1021/pathep-[eth1/29]]",
                      "uni/tn-mgmt/ap-esx-mgmt-anp/epg-esx-mgmt-01-epg/rspathAtt-[topology/pod-1/paths-1021/extpaths-1021/pathep-[eth1/29]]",
                      "topology/pod-1/paths-1018-1019/pathep-[eth1/1]-[eth1/2]", 
                      "topology/pod-1/paths-1018-1019/pathep-[eth1/1]-[eth1/2]"};
    for (auto line: lines) {
        epgRsPathAttInfo rsPathAttInfo;
        scanNodeIfs(line, rsPathAttInfo);
        cout << "\n------- Nodes: " << rsPathAttInfo.nodes.size() << " ------------------------------\n";
        for (auto s: rsPathAttInfo.nodes) {
               cout << s << " "; 
        }
        cout << "\n------- Intfs: " << rsPathAttInfo.intfInfos.size() << " ------------------------------\n";
        for (auto s: rsPathAttInfo.intfInfos) {
               cout << s.card << "/" << s.port << " "; 
        }
        cout << "\n-----------------------------------------------\n";
    }
}
