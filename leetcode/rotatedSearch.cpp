#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

  int bSearch(vector<int>& nums, int start, int end, int t) {

    if (start == end) {
      cout << "start == end " << nums[start] << " " << nums[end] << "\n";
      if (t == nums[start]) {
        cout << "nnnnn " << start << "\n";
        return start;
      } else {
        return -1;
      }
    }

    auto numElems = [&]()->int{
      for (int i = start, count = 0;;i=(i+1)%nums.size(), ++count) {
        cout << "i " << i << " count " << count << "\n";
        if (i == end) return count+1;
      }
    };

    int n = numElems();
    int m = (n % 2) ? (n / 2 + 1):(n / 2);
    cout << start << " : " << end << " numElems " << n << " :: " << m << "\n";
    auto midIndex = [&](int m)->int {
      int count = 0, i = start;
      for (; count < m; ++count, i=(i+1)%nums.size()) {
        cout << "...count " << count << " i " << i << "\n";
        if (count == m-1) return i;
      }
      return 0;
    };
    int mid = midIndex(m);
    cout << "midIndex: " <<  mid << " midElem:" << nums[mid] << "\n";
    if (nums[mid] == t) {
      cout << "Found entry at " << mid << "\n";
      return mid;
    }
    if (nums[mid] < t) {
      if (end == mid) return -1;
      cout << " Target greater. Trying " << (mid+1)%nums.size() << " : " << end << "\n";
      return bSearch(nums, (mid+1)%nums.size(), end, t);
    } else {
      if (start == mid) return -1;
      int e = mid-1;
      if (mid == 0) {
        e = nums.size()-1;
      }
      cout << " Target smaller. Trying " << start << " : " << e << "\n";
      return bSearch(nums, start, e, t);
    }
    return -1;
  }

  int search(vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;
    if (nums.size() == 1) {
      if (nums[0] == target) return 0;
      else return -1;
    }
    //int i = find_edge(nums);
    auto findEdge = [&]()->int {
      for (int i = 0; i < nums.size()-1; ++i) {
        if (nums[i] > nums[i+1]) return i;
      }
      return -1;
    };
    int edge = findEdge();
    if (edge < 0)
      return bSearch(nums, 0, nums.size()-1, target);
    cout << "Edge at " << edge << " " << edge + 1 << "\n";
    int found = bSearch(nums, edge+1, edge, target);
    return found;
  }
};

int main()
{
	Solution s;
    //vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    vector<int> nums = {1, 3};
    int r = s.search(nums, 3);
    string res = (r >=0) ? "Found\n" : "Not Found\n";
    cout << " Res " << r << "\n";
    cout << res;
    return 0;
}
