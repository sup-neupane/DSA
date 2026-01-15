#include <unordered_map>

using std::unordered_map;

class UnionFind {
public:
    unordered_map<int, int> par_;
    unordered_map<int, int> rank_;

    UnionFind(int n) {
        for (int i = 1; i <= n; i++) {
            par_[i] = i;
            rank_[i] = 0;
        }
    }

    // Find parent of n, with path compression.
    int find(int n){
        if(n != par_[n]){
            par_[n] = find(par_[n]);
        }
        return par_[n];
    }

    // Union by height / rank.
    // Return false if already connected, true otherwise.
    bool uniond(int n1, int n2) {
        int p1 = find(n1), p2 = find(n2);
        if (p1 == p2) {
            return false;
        }

        if (rank_[p1] > rank_[p2]) {
            par_[p2] = p1;
        } else if (rank_[p1] < rank_[p2]) {
            par_[p1] = p2;
        } else {
            par_[p1] = p2;
            rank_[p2] += 1;
        }
        return true;
    }
};