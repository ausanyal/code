// https://leetcode.com/problems/4sum/description/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
class Solution {
  unordered_set<int> hashes;
  public:
    int computeHash(vector<int> nums) {
      int myHash = 201326611; // big prime
      for (int i = 1; i <= nums.size(); ++i) {
        myHash ^= i*nums[i];
      }
      return myHash;
    }
    int saveHash(int myHash) {
      if (hashes.find(myHash) != hashes.end()) {
        //cout << "Error... conflict\n";
        return -1;
      } else {
        hashes.insert(myHash);
        return 0;
      }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      vector<vector<int>> res; 
      if (nums.size() < 4) return res;

      for (int i = 0; i < nums.size()-3; ++i) {
        for (int j = i+1; j < nums.size()-2; ++j) {
          for (int k = j+1; k < nums.size()-1; ++k) {
            for (int l = k+1; l < nums.size(); ++l) {
              if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                int myHash = computeHash({nums[i], nums[j], nums[k], nums[l]});
                if (saveHash(myHash) == 0) { 
                  res.push_back({nums[i], nums[j], nums[k], nums[l]});
                }
              }
            }
          }
        }
      }
      return res;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      vector<vector<int>> res;
      if (nums.size() < 4) return res;
      int n = nums.size();
      sort(nums.begin(), nums.end());
      cout << "Aubin.. sorted \n";
      for (int i = 0; i < n-3; ++i) {
        cout << "1 \n";
        if (i > 0 && nums[i] == nums[i-1]) continue;
        // Make sure the first/smallest in this win are smaller or
        // equal to target as the vector is now sorted.
        if ((nums[i] + nums[i+1] + nums[i+2] + nums[i+3]) > target) break;
        cout << "2 \n";
        // If ekement at i along with the last set of elements do not add up
        // to the target then move on to the next element.
        if ((nums[i] + nums[n-1] + nums[n-2] + nums[n-2]) < target) continue;
        for (int j = i+1; j < n-2; ++j) {
          if (j > i+1 && nums[j] == nums[j-1]) continue;
          // Same logic in previous break.
          if ((nums[i] + nums[j] + nums[j+1] + nums[j+2]) > target) break;
          // Same logic in previous continue.
          if ((nums[i] + nums[j] + nums[n-2] + nums[n-1]) < target) continue;
          int l = j+1;
          int r = n-1;
          cout << "Trying with " << i << j << l << r << "\n";
          while(l < r) {
            int sum = nums[i] + nums[j] + nums[l] + nums[r];
            if (sum < target) ++l;
            else if (sum > target) --r;
            else {
              res.push_back(vector<int>({nums[i], nums[j], nums[l], nums[r]}));
              ++l; while(nums[l] == nums[l-1]) l++;
              --r; while(nums[r] == nums[r+1]) r--;
            }
          }
        }
      }
      return res;
    }
};

int main() {
  Solution s;
  vector<int> nums = {1, 0, -1, 0, -2, 2};
  auto res = s.fourSum(nums, 0);
  for (auto v : res) {
    for (auto n : v) cout << n << " ";
    cout << "\n";
  }
}
