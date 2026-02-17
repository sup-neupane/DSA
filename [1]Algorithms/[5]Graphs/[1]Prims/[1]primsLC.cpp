#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>

using namespace std;

//Min Cost to Connect All Points
//https://leetcode.com/problems/min-cost-to-connect-all-points/
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();
        unordered_map<int, vector<pair<int,int>>> adj;
//Didnt build adjacency list for optimal solution
        for (int i = 0; i < N ; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < N; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }
        int res = 0;
        unordered_set<int> visit;
        visit.insert(0);

priority_queue<tuple<int,int, int>, vector<tuple<int,int, int>>, greater<tuple<int, int, int>>> minHeap; 
        for(pair<int,int> neighbor : adj[0]){
            int weight = neighbor.first, node = neighbor.second;
            minHeap.push({weight,0,node});
        }

        while(visit.size() < N){
        tuple<int, int, int> cur = minHeap.top();
        minHeap.pop();
        int w1 = get<0>(cur), n1 = get<1>(cur), n2 = get<2>(cur);

            if(visit.count(n2) > 0){
                continue;
            }

            res += w1;
            visit.insert(n2);

            for(pair<int,int> p : adj[n2]){
                int weight = p.first, neighbor = p.second;
                if(visit.count(neighbor) == 0){
                    minHeap.push({weight,n2,neighbor});
                }
            }
        }
        return res;
    }
};



