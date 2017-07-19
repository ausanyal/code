#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    //string s = "topology/pod-1/protpaths-1021-1022/pathep-[aci-ucs-A-IfPolGrp]";
    string s = "pathep-[aci-ucs-A-IfPolGrp]";
    cout << s << endl;
    
    string pattern = "pathep-[";
    auto a = s.find(pattern);
    auto b = s.find("]", a);
    string ss = s.substr(a + pattern.length(), b - a - pattern.length());

    cout << a << " -> " <<  ss << endl;
    string infrAccBndlGrp = "uni/infra/funcprof/accbundle-" + ss;
    cout << infrAccBndlGrp << endl;

    string intf = "eth1/2";
    string ethPattern = "eth";
    auto c = intf.find(ethPattern);
    auto d = intf.find("/", c);
    string ss1 = intf.substr(c + ethPattern.length(), d - c - ethPattern.length());
    string ss2 = intf.substr(d + 1, intf.length() - d - 1);
    cout << ss1 << "/" << ss2 << endl;

    return 0;
}
