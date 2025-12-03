#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

// Shortest path from top left to bottom right
int bfs(vector<vector<int>>& grid) {
    int ROWS = grid.size(), COLS = grid[0].size();
    vector<vector<int>> visit(ROWS, vector<int>(COLS, 0));
    queue<pair<int, int>> queue;
    queue.push({0, 0});
    visit[0][0] = 1;

    int length = 0;

    while (!queue.empty()) {
        for (int i = 0; i < queue.size(); i++) {
            auto [r, c] = queue.front()  ; 
            queue.pop();

            if (r == ROWS - 1 && c == COLS - 1) {
                return length;
            }

            int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (int j = 0; j < 4; j++) {
                int newR = r + directions[j][0];
                int newC = c + directions[j][1];

                if (min(newR, newC) < 0 || newR == ROWS || newC == COLS
                    || visit[newR][newC] || grid[newR][newC]) {
                    continue;
                }

                queue.push({newR, newC});
                visit[newR][newC] = 1;
            }
        }

        length++;
    }

    // Destination was unreachable
    return -1;
}
