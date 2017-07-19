//https://leetcode.com/problems/number-of-islands/
/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void conquerIsland(vector<vector<char>>& grid, int r, int c) {
            grid[r][c] = '0';
            if ((r > 0) && (grid[r-1][c] == '1')) conquerIsland(grid, r-1, c);
            if ((r+1 < grid.size()) && (grid[r+1][c] == '1')) conquerIsland(grid, r+1, c);
            if ((c > 0) && (grid[r][c-1] == '1')) conquerIsland(grid, r, c-1);
            if ((c+1 < grid[0].size()) && (grid[r][c+1] == '1')) conquerIsland(grid, r, c+1);
        }
        int numIslands(vector<vector<char>>& grid) {
            if (!grid.size()) return 0;
            int num = 0;
            int row = grid.size();
            int col = grid[0].size();
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (grid[i][j] == '1') { 
                        num++;
                        conquerIsland(grid, i,  j);
                    }
                }
            }
            return num;
        }
};

int main()
{
    Solution s;
    vector<vector<char>> grid = {
        {'1','1','1','1','0'}, 
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
        /*
        {'1','1','0','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','1','0'},
        */
    };
    cout << s.numIslands(grid) << endl;
}
