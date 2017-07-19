#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
#if 0
    const string lines[] = {"Roses are #ff0000",
        "violets are #0000ff",
        "all of my base are belong to you"};
    regex color_regex("#([a-f0-9]{2})([a-f0-9]*)");//([a-f0-9]{2})");
    smatch color_match;
    for (auto line:lines) {
        if (regex_search(line, color_match, color_regex)) {
            cout << "line: " << line << endl << "prefix: " << color_match.prefix() <<endl;
            for (size_t i = 0; i < color_match.size(); i++) {
                cout << i << ": " << color_match[i] << endl;
            }
            cout << color_match.suffix() << endl;
        }
    }
#endif

#if 0
    [0] topology/pod-{id}/protpaths-{nodeAId}-{nodeBId}/extprotpaths-{extChAId}-{extChBId}/pathep-{[name]}
    [1] topology/pod-{id}/paths-{nodeId}/extpaths-{extChId}/pathep-{[name]}
    [2] topology/pod-{id}/protpaths-{nodeAId}-{nodeBId}/pathep-{[name]}
    [3] topology/pod-{id}/paths-{nodeId}/pathep-{[name]}

#endif
    string lines[] = {"uni/tn-mgmt/ap-esx-mgmt-anp/epg-esx-mgmt-01-epg/rspathAtt-[topology/pod-1/protpaths-1031-1032/pathep-[aci-ucs-B-IfPolGrp]]",
                      "uni/tn-mgmt/ap-esx-mgmt-anp/epg-esx-mgmt-01-epg/rspathAtt-[topology/pod-1/protpaths-1031-1032/extprotpaths-1031-1032/pathep-[aci-ucs-B-IfPolGrp]]",
                      "uni/tn-mgmt/ap-esx-mgmt-anp/epg-esx-mgmt-01-epg/rspathAtt-[topology/pod-1/paths-1021/pathep-[eth1/29]]",
                      "uni/tn-mgmt/ap-esx-mgmt-anp/epg-esx-mgmt-01-epg/rspathAtt-[topology/pod-1/paths-1021/extpaths-1021/pathep-[eth1/29]]",
                      "topology/pod-1/paths-1018-1019/pathep-[eth1/1]-[eth1/2]", 
                      "topology/pod-1/paths-1018-1019/pathep-[eth1/1]-[eth1/2]"};
                      //Parses tDn like 'topology/pod-1/paths-1018-1019/pathep-[eth1/1]-[eth1/2]' into [1018, 1019]
                      //Parses tDn like 'topology/pod-1/paths-1018-1019/pathep-[eth1/1]-[eth1/2]' into [eth1/1, eth1/2]
    //regex paths_regex("pathep-\[([a-zA-Z\-]*)\]");
    cout << "Start\n";
    for (auto line: lines) {
        //regex paths_regex("pathep-\\[(.*)\\]\\]");
        //regex paths_regex("paths-([0-9]*)-?([0-9]*)?.*pathep-\\[(.*)\\]\\]?");
        //regex paths_regex("(/protpaths-([0-9]*)-([0-9]*)/)?(/paths-([0-9]*))?.*pathep-\\[(.*)\\]\\]?");
        regex paths_regex("/protpaths-([0-9]+)-([0-9]+)/" "|" "/paths-([0-9]+)-?([0-9]+)?/");
        smatch paths_match;
        vector<string> nodes, intfs;
        if (regex_search(line, paths_match, paths_regex)) {
            //cout << "\n***************************\n" << paths_match.size() << endl;
            for (size_t i = 1; i < paths_match.size(); i++) {
                string pathsStr = paths_match[i].str();
                //cout << i << ": " << paths_match[i] << " length: " << pathsStr.length() << endl;
                //if (pathsStr.length() && pathsStr.find("paths") == string::npos) {
                if (pathsStr.length()) {
                    //cout << "\t\t\tFound: " << pathsStr << endl;
                    nodes.push_back(pathsStr);
                }
            }
            //regex pathEpSearch("/pathep-\\[eth([0-9]+)/([0-9]+)\\]-?\\[?(eth([0-9]+)/([0-9]+))?\\]?");
            regex pathEpSearch("/pathep-\\[eth([0-9]+)/([0-9]+)\\](-\\[eth([0-9]+)/([0-9]+)\\])?");
            smatch pathEpMatch;
            if (regex_search(line, pathEpMatch, pathEpSearch)) {
                int idx = 0;
                string card;
                // 3rd match is "(-\\[eth([0-9]+)/([0-9]+)\\])"
                for (size_t i = 1; i < pathEpMatch.size(); i++) {
                    if (i == 3) continue;
                    string pathEpStr = pathEpMatch[i].str();
                    if (pathEpStr.length()) {  
                        if (!(idx%2)) { 
                            card = pathEpStr;
                        } else {
                            string intf = card + "/" + pathEpStr;
                            intfs.push_back(intf);
                        }
                        idx++;
                    }
                    //cout << "\t" << i << " : " << pathEpMatch[i] << endl; 
                }
            }
        }
        cout << "\n------- Nodes: " << nodes.size() << " ------------------------------\n";
        for (auto s: nodes) {
               cout << s << " "; 
        }
        cout << "\n------- Intfs: " << intfs.size() << " ------------------------------\n";
        for (auto s: intfs) {
               cout << s << " "; 
        }
        cout << "\n-----------------------------------------------\n";
    }
}
