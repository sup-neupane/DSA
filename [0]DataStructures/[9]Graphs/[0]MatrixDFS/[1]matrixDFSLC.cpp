//Number of Islands
//https://leetcode.com/problems/number-of-islands/
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
    public:
        void dfs(int i, int j, int ROWS, int COLS, vector<vector<char>>& grid){
            if (min(i,j) < 0 || i == ROWS || j == COLS || grid[i][j] != '1'){
                return;
            }
            grid[i][j] = '0';
            dfs(i + 1, j, ROWS, COLS, grid);
            dfs(i - 1, j, ROWS, COLS, grid);
            dfs(i, j + 1, ROWS, COLS, grid);
            dfs(i, j - 1, ROWS, COLS, grid);
        }
    
        int numIslands(vector<vector<char>>& grid) {
            int ROWS = grid.size(), COLS = grid[0].size();
            int num_of_islands = 0;
            
            for(int i = 0; i < ROWS; i++){
                for(int j = 0; j < COLS; j++){
                    if(grid[i][j] == '1'){
                        num_of_islands++;
                        dfs(i, j, ROWS, COLS, grid);
                    }
                }
            }
            return num_of_islands;
        }
    };
    








//Max Area of Island
//https://leetcode.com/problems/max-area-of-island/
class Solution {
    public:
        int dfs(int i, int j, int ROWS, int COLS, vector<vector<int>>& grid) {
            if (min(i, j) < 0 || i == ROWS || j == COLS || grid[i][j] != 1) {
                return 0;
            } else {
                grid[i][j] = 0;
                return 1 + dfs(i + 1, j, ROWS, COLS, grid)
                         + dfs(i - 1, j, ROWS, COLS, grid)
                         + dfs(i, j + 1, ROWS, COLS, grid)
                         + dfs(i, j - 1, ROWS, COLS, grid);
            }
        }
    
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int ROWS = grid.size(), COLS = grid[0].size();
            int max_area = 0;
    
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (grid[i][j] == 1) {
                        max_area = max(max_area, dfs(i, j, ROWS, COLS, grid));
                    }
                }
            }
    
            return max_area;
        }
    };
    


