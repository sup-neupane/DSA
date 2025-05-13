//Shortest Path in Binary Matrix
//https://leetcode.com/problems/shortest-path-in-binary-matrix/
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <tuple>


using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<vector<int>> visit(ROWS, vector<int>(COLS, 0));
        queue<tuple<int, int, int>> queue;
        queue.push({0, 0, 1});   //Here we keep distance one as we consider the first cell as distance 1
        visit[0][0] = 1;

        if (grid[0][0] || grid[ROWS - 1][COLS - 1]) {
            return -1;
        }

        int directions[8][2] = {
                {0, 1}, {0, -1}, {1, 0}, {-1, 0},
                {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };

        while (!queue.empty()) {
            auto [r, c, length] = queue.front();
            queue.pop();

            if (r == ROWS - 1 && c == COLS - 1) {
                return length;
            }

            for (int j = 0; j < 8; j++) {
                int newR = r + directions[j][0];
                int newC = c + directions[j][1];

                if (newR < 0 || newC < 0 || newR >= ROWS || newC >= COLS
                    || visit[newR][newC] || grid[newR][newC]) {
                    continue;
                }

                queue.push(make_tuple(newR, newC, length + 1));
                visit[newR][newC] = 1;
            }
        }

        return -1;
    }
};











//Rotting Oranges
//https://leetcode.com/problems/rotting-oranges/
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int time = 0, fresh = 0;
        queue<pair<int,int>> q;

        // Count fresh oranges and add rotten ones to the queue
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(q.size() && fresh > 0) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int newR = r + directions[j][0];
                    int newC = c + directions[j][1];

                    if (newR < 0 || newC < 0 || newR >= ROWS || newC >= COLS || grid[newR][newC] != 1)
                        continue;

                    grid[newR][newC] = 2;
                    q.push({newR, newC});
                    fresh--;
                }
            }
            time++;
        }

        return (fresh == 0) ? time : -1;
    }
};
