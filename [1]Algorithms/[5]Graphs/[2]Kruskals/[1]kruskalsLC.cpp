#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>
#include<algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>

using namespace std;

class UnionFind{
    public:
    unordered_map<int,int> par_;
    unordered_map<int,int> rank_;
    UnionFind(int n){
        for(int i = 1; i <= n; i++){
            par_[i] = i;
            rank_[i] = 0;
        }
    }
    int find(int n){
        if(n != par_[n]){
            par_[n] = find(par_[n]);
        }
        return par_[n];
    }

    bool uniond(int n1, int n2){
        int p1 = find(n1), p2 = find(n2);

        if(p1 == p2){
            return false;
        }
        if(rank_[p1] > rank_[p2]){
            par_[p2] = p1;
        } else if(rank_[p1] < rank_[p2]){
            par_[p1] = p2;
        }else{
            par_[p1] = p2;
            rank_[p2]++;
        }
        return true;
    }
};
//Min Cost to Connect All Points
//https://leetcode.com/problems/min-cost-to-connect-all-points/
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<array<int, 3>> edges;
        int N = points.size();

        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> minHeap;

        for(auto edge: edges){
            int weight = edge[0], n1 = edge[1], n2 = edge[2];
            minHeap.push({weight,n1,n2});
        }
        UnionFind unionFind(N);
        int res = 0;
        int used = 0;

        while(!minHeap.empty() && used < N-1){
            tuple<int, int, int> cur = minHeap.top();
            minHeap.pop();
            int w1 = get<0>(cur), n1 = get<1>(cur), n2 = get<2>(cur);

            if(!unionFind.uniond(n1,n2)){
                continue;
            }
            res += w1;
            used++;
        }
        return res;
    }
};




//Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
//https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
class UnionFind{
    public:
    unordered_map<int,int> par_;
    unordered_map<int,int> rank_;
    UnionFind(int n){
        for(int i = 0; i < n; i++){
            par_[i] = i;
            rank_[i] = 0;
        }
    }
    int find(int n){
        if(n != par_[n]){
            par_[n] = find(par_[n]);
        }
        return par_[n];
    }

    bool uniond(int n1, int n2){
        int p1 = find(n1), p2 = find(n2);

        if(p1 == p2){
            return false;
        }
        if(rank_[p1] > rank_[p2]){
            par_[p2] = p1;
        } else if(rank_[p1] < rank_[p2]){
            par_[p1] = p2;
        }else{
            par_[p1] = p2;
            rank_[p2]++;
        }
        return true;
    }
};
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<array<int,4>> edgeList;
        for(int i = 0 ; i <edges.size() ; i++){
            edgeList.push_back({edges[i][0] , edges[i][1] , edges[i][2], i});
        }

        sort(edgeList.begin(), edgeList.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });

        int mst_weight = 0;
        UnionFind uf(n);

        for(auto [v1,v2,w,i] : edgeList){
            if(uf.uniond(v1,v2)){
                mst_weight += w;
            }
        }

        vector<int> critical, pseudo;
        for(auto [n1, n2, e_weight, i] : edgeList){
            UnionFind uf1(n);
            int weight = 0;
            int count = 0;
            for(auto [v1,v2,w,j] : edgeList){
            if(i!=j && uf1.uniond(v1,v2)){
                weight += w;
                count++;
            }
            }
            if(count != n-1 || weight > mst_weight){
                critical.push_back(i);
                continue;
            }

            UnionFind uf2(n);
            uf2.uniond(n1,n2);
            weight = e_weight;
            int count2 = 1;

            for(auto [v1,v2,w,j] : edgeList){
            if(uf2.uniond(v1,v2)){
                weight += w;
                count2++;
            }
            }
            if(count2 == n-1 && weight == mst_weight){
                pseudo.push_back(i);
            }
    }
    return {critical, pseudo};
    }
};
