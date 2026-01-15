#include <unordered_map>
#include <map>
#include<set>
#include<unordered_set>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;

//Redundant Connection
//https://leetcode.com/problems/redundant-connection/
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
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind u1(edges.size());
        for(auto edge : edges){
            int e1 = edge[0], e2= edge[1];
            if(!u1.uniond(e1,e2)){
                return edge;
            }
        }
        return {};
    }
};



//Accounts Merge
//https://leetcode.com/problems/accounts-merge/
class UnionFind{
    public:
    unordered_map<int,int> par_;
    unordered_map<int,int> rank_;

    UnionFind(int n){
        for(int i = 1 ; i<= n ; i++){
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
        }else if(rank_[p1] < rank_[p2]){
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind u1(accounts.size());
        unordered_map<string,int> emailToAcc;

        for(int i = 0 ;  i < accounts.size(); i++){
            for(int j = 1 ; j < accounts[i].size(); j++){
                string email = accounts[i][j];
                if(emailToAcc.count(email)){
                    u1.uniond(i, emailToAcc[email]);
                }else{
                    emailToAcc[email] = i;
                }
            }
        }
        map<int, vector<string>> emailGroup; // index of acc -> list of emails
            for (auto [email, accId] : emailToAcc) {
                int leader = u1.find(accId);
                emailGroup[leader].push_back(email);
        }

        // Build result
        vector<vector<string>> res;
        for (auto [accId, emails] : emailGroup) {
            sort(emails.begin(), emails.end());
            vector<string> merged;
            merged.push_back(accounts[accId][0]);
            merged.insert(merged.end(), emails.begin(), emails.end());
            res.push_back(merged);
        }

        return res;
    }
};

//Longest Consecutive Sequence
//https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> set(nums.begin(), nums.end());
       int longest = 0;

       for(int n : set){
        if(!set.count(n - 1)){
            int length = 0;
            while(set.count(n + length)){
                length++;
            }
            longest = max(longest,length);
        }
       }
       return longest;
    }
};



//Number of Connected Components in an Undirected Graph
//https://neetcode.io/problems/count-connected-components/question?list=neetcode250
class UnionFind {
    public:
    unordered_map<int,int> par_;
    unordered_map<int,int> rank_;

    UnionFind(int n){
        for(int i = 1; i < n; i++){
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

    int uniond(int n1, int n2){
        int p1 = find(n1), p2 = find(n2);
        if(p1 == p2){
            return 0;
        }
        if(rank_[p1] > rank_[p2]){
            par_[p2] = p1;
        }else if(rank_[p1] < rank_[p2]){
            par_[p1] = p2;
        }else{
            par_[p1] = p2;
            rank_[p2]++;
        }
        return 1;
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind u1(n);
        int res = n;

        for(auto edge : edges){
            res -= u1.uniond(edge[0],edge[1]);
        }
        return res;
    }
};

