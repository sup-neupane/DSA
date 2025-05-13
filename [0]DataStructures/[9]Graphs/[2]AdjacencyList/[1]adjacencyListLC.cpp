//Clone Graph
//https://leetcode.com/problems/clone-graph/
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& oldToNew) {
        if (oldToNew.count(node)) {
            return oldToNew[node];
        }

        Node* copy = new Node(node->val);
        oldToNew[node] = copy;

        for (Node* nei : node->neighbors) {
            copy->neighbors.push_back(dfs(nei, oldToNew));
        }

        return copy;
    }

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> oldToNew;
        return dfs(node, oldToNew);
    }
};










//Course Schedule
//https://leetcode.com/problems/course-schedule/
class Solution {
public:
    bool dfs(int course, unordered_map<int, vector<int>>& preMap, unordered_set<int>& visitSet, unordered_set<int>& path) {
        if (path.count(course)) return false; // cycle detected
        if (visitSet.count(course)) return true; // already processed and safe

        path.insert(course);
        for (int pre : preMap[course]) {
            if (!dfs(pre, preMap, visitSet, path)) return false;
        }
        path.erase(course);
        visitSet.insert(course); // mark course as processed
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preMap;
        for (int i = 0; i < numCourses; ++i) {
            preMap[i] = {};
        }
        for (auto& pre : prerequisites) {
            preMap[pre[0]].push_back(pre[1]);
        }

        unordered_set<int> visitSet; // permanently visited nodes
        unordered_set<int> path;     // current DFS path for cycle detection

        for (int course = 0; course < numCourses; ++course) {
            if (!dfs(course, preMap, visitSet, path)) return false;
        }
        return true;
    }
};
