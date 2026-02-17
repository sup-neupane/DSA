#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

//Course Schedule
//https://leetcode.com/problems/course-schedule/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (auto& pre : prerequisites) {
            indegree[pre[1]]++;
            adj[pre[0]].push_back(pre[1]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int finish = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            finish++;
            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return finish == numCourses;
    }
};


//Course Schedule II
//https://leetcode.com/problems/course-schedule-ii/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (auto& pre : prerequisites) {
            indegree[pre[1]]++;
            adj[pre[0]].push_back(pre[1]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int finish = 0;
        vector<int> output(numCourses);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            output[numCourses - finish - 1] = node;
            finish++;
            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        if (finish != numCourses) {
            return {};
        }
        return output;
    }
};


//Course Schedule IV
//https://leetcode.com/problems/course-schedule-iv/
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        vector<unordered_set<int>> isPrereq(numCourses);

        for(auto& pre :  prerequisites){
            indegree[pre[1]]++;
            adj[pre[0]].push_back(pre[1]);

        }
        
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0 ){
                
                q.push(i);

            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int neighbor : adj[node]){
                isPrereq[neighbor].insert(node);
                isPrereq[neighbor].insert(
                isPrereq[node].begin(),
                isPrereq[node].end()
            );
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) q.push(neighbor);
            }
        }
                vector<bool> res;
        for (auto& query : queries) {
            res.push_back(isPrereq[query[1]].count(query[0]));
        }

        return res;
    }
};



//Sort Items by Groups Respecting Dependencies
//https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
//https://youtu.be/--ZX-B0_hBA?si=ht9V9_mf67rwxjqx

class Solution {
public:
    vector<int> topologicalSort(vector<vector<int>>& adj, vector<int>& indegree){
        vector<int> res;
        queue<int> q;

        for (int i = 0; i < indegree.size(); ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front(); 
            q.pop();
            res.push_back(node);

            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        if (res.size() != adj.size()) {
            return {};   //cycle
        }
        return res;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int new_group_id = m;

        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = new_group_id;
                new_group_id++;
            }
        }

        vector<vector<int>> itemAdj(n);
        vector<vector<int>> groupAdj(new_group_id);

        vector<int> itemIndegree(n, 0);
        vector<int> groupIndegree(new_group_id, 0);

        for (int i = 0; i < n; i++) {
            for (auto pre : beforeItems[i]) {
                itemAdj[pre].push_back(i);
                itemIndegree[i]++;

                if (group[pre] != group[i]) {
                    groupAdj[group[pre]].push_back(group[i]);
                    groupIndegree[group[i]]++;
                }
            }
        }

        vector<int> groupOrder = topologicalSort(groupAdj, groupIndegree);
        vector<int> itemOrder = topologicalSort(itemAdj, itemIndegree);

        if (groupOrder.empty() || itemOrder.empty()) {
            return {};
        }

        unordered_map<int, vector<int>> itemsByGroup;

        for (int item : itemOrder) {
            itemsByGroup[group[item]].push_back(item);
        }

        vector<int> finalOrder;

        for (int g : groupOrder) {
            for (int item : itemsByGroup[g]) {
                finalOrder.push_back(item);
            }
        }

        return finalOrder;
    }
};




//Alien Dictionary
//https://neetcode.io/problems/foreign-dictionary/question
//https://youtu.be/0nI8_RbVeb4?si=gi6QU5MHhJJIFX95
class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        for (auto &w : words) {
            for (char c : w) {
                indegree[c] = 0;
            }
        }

        for(int i = 0; i < words.size() - 1; i++){
            string w1 = words[i] , w2 = words[i + 1];
            bool broke = false;  

            for(int j = 0 ; j < min(w1.size(), w2.size()) ; j++){
                if(w1[j] != w2[j]){
                    if (adj[w1[j]].insert(w2[j]).second) {
                        indegree[w2[j]]++;
                        // Increase indegree only if edge is newly inserted to avoid counting duplicate dependencies.

                    }
                    broke = true;
                    break;
                }
               
            }

            if(!broke && w1.size() > w2.size()){
                return "";
            }
        }

        queue<char> q;

        for (auto &[c, deg] : indegree) {
            if (deg == 0) {
                q.push(c);
            }
        }

        string res;
        while (!q.empty()) {
            char char_ = q.front();
            q.pop();
            res += char_;
            for (char neighbor : adj[char_]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return res.size() == indegree.size() ? res : "";
    }
};



