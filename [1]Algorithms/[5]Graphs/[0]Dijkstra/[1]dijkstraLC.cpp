#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>
#include <set>

using namespace std;
//Network Delay Time
//https://leetcode.com/problems/network-delay-time/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;

        for (int i = 1; i < n; i++) {
            adj[i] = vector<pair<int,int>>();
        }

        for (vector<int> time : times) {
            int s = time[0], d = time[1], w = time[2];
            adj[s].push_back(make_pair(d, w));
        }

        set<int> visited;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        minHeap.push({0, k});
        int t = 0;  // max delay time

        while (!minHeap.empty()) {
            pair<int,int> p = minHeap.top();
            minHeap.pop();
            int w1 = p.first, n1 = p.second;

            if (visited.count(n1) > 0) {
                continue;
            }

            visited.insert(n1);
            t = w1;

            for (pair<int, int> p : adj[n1]) {
                int n2 = p.first, w2 = p.second;
                if (visited.count(n2) == 0) {
                    minHeap.push({w1 + w2, n2});
                }
            }
        }

        return visited.size() == n ? t : -1;
    }
};



//Swim in Rising Water
//https://leetcode.com/problems/swim-in-rising-water/
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        set<pair<int, int>> visit;
        priority_queue<vector<int>,
                       vector<vector<int>>, greater<>> minHeap;
        vector<vector<int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };

        minHeap.push({grid[0][0], 0, 0});
        visit.insert({0, 0});

        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            int t = curr[0], r = curr[1], c = curr[2];
            if (r == N - 1 && c == N - 1) {
                return t;
            }
            for (auto dir : directions) {
                int neiR = r + dir[0], neiC = c + dir[1];
                if (neiR < 0 || neiC < 0 || neiR == N ||
                    neiC == N || visit.count({neiR, neiC})) {
                    continue;
                }
                visit.insert({neiR, neiC});
                minHeap.push({
                    max(t, grid[neiR][neiC]), neiR, neiC
                });
            }
        }

        return N * N;
    }
};


//Path with Maximum Probability
//https://leetcode.com/problems/path-with-maximum-probability/
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

    vector<vector<pair<int, double>>> adj(n);
    for(int i = 0 ; i < edges.size() ; i ++){
            int src = edges[i][0], dst = edges[i][1];
            adj[src].emplace_back(dst, succProb[i]);
            adj[dst].emplace_back(src, succProb[i]);
    }

    vector<double> maxProb(n , 0.0);
    maxProb[start_node] = 1.0;
    priority_queue<pair<double,int>> pq;
    pq.emplace(1.0 , start_node);

    while(!pq.empty()){
        auto [cur_prob, node] = pq.top();
        pq.pop();

        if(node == end_node) return cur_prob; 
        if(cur_prob > maxProb[node]) continue;

        for(auto [nei, edge_prob] : adj[node]){
            double new_prob = cur_prob * edge_prob;
                if (new_prob > maxProb[nei]) {
                    maxProb[nei] = new_prob;
                    pq.emplace(new_prob, nei);
                }
        } 
    }
    return 0.0;
    }
};