#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;
typedef pair<int, int> pt;

float get_eucledian_dist(pt a, pt b) {
    float xd = b.first - a.first; 
    float yd = b.second - a.second;
    float d = sqrt((xd*xd) + (yd*yd));
    cout << "a: " << a.first << ":" << a.second << 
        "\t b: " << b.first << ":" << b.second << " d: " << d << endl;
    return d;
}

pt find_closest(vector<pt> pts, pt test) {
    pt a;
    float temp = 0, min = INT_MAX;

    for (int i = 0; i < pts.size(); i++) {
        temp = get_eucledian_dist(pts[i], test);
        if (temp < min) {
            min = temp;
            a.first = pts[i].first;
            a.second = pts[i].second;
        }
    }


    return a;
}

int main()
{
    //vector<pair<int, int>> 
    vector<pt> pts = {
            make_pair(1,2), 
            make_pair(2,2),
            make_pair(3,2), 
            make_pair(4,2), 
            make_pair(5,2), 
            make_pair(6,2),
            make_pair(7,2),
            make_pair(8,2)
            };

    pt a = find_closest(pts, make_pair(9, 4));
    cout << "x: " << a.first << " y: " << a.second << endl;
    return 0;
}
