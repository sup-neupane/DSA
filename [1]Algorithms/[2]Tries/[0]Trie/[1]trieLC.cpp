#include <unordered_map>
#include<set>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;

//Implement Trie (Prefix Tree)
//https://leetcode.com/problems/implement-trie-prefix-tree/
class TrieNode{
    public:
    unordered_map<char, TrieNode*> children_;
    bool word = false;
};
class Trie {
public:
    Trie() {}
    TrieNode root_;
    
    void insert(string word) {
        TrieNode *curr = &root_;
        for(char c: word){
            if(curr -> children_.count(c) == 0){
                curr -> children_[c] = new TrieNode();
            }
            curr = curr -> children_[c];
        }
        curr -> word = true;
    }
    
    bool search(string word) {
        TrieNode *curr = &root_;

        for (char c: word) {
            if (curr->children_.count(c) == 0) {
                return false;
            }
            curr = curr->children_[c];
        }
        return curr->word;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = &root_;
        for (char c: prefix) {
            if (curr->children_.count(c) == 0) {
                return false;
            }
            curr = curr->children_[c];
        }
        return true;
    }
};


//Design Add and Search Words Data Structure
//https://leetcode.com/problems/design-add-and-search-words-data-structure/
class TrieNode{
    public:
    unordered_map<char, TrieNode*>children_;
    bool word = false;
};
class WordDictionary {
public:
    WordDictionary() {}
    TrieNode root_;
    
    void addWord(string word) {
        TrieNode *curr = &root_;
        for(char c: word){
            if(curr -> children_.count(c) == 0){
                curr -> children_[c] = new TrieNode();
            }
            curr = curr -> children_[c];
        }
        curr -> word = true;
    }

    bool dfs(int j, TrieNode* node, string& word){
        TrieNode* curr = node;

        for (int i = j; i < word.size(); i++) {
            char c = word[i];

            if (c == '.') {
                for (auto p : curr->children_) {
                    if (dfs(i + 1, p.second, word)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (curr->children_.count(c) == 0) {
                    return false;
                }
                curr = curr->children_[c];
            }
        }
        return curr->word;
        
    }
    
    bool search(string word) {
         return dfs(0, &root_, word);;
    }
};


//Word Search II
//https://leetcode.com/problems/word-search-ii/
class TrieNode {
public:
    unordered_map<char, TrieNode*> children_;
    bool word = false;
};

class Trie {
public:
    TrieNode root_;

    void addWord(string word) {
        TrieNode* curr = &root_;
        for (char c : word) {
            if (curr->children_.count(c) == 0) {
                curr->children_[c] = new TrieNode();
            }
            curr = curr->children_[c];
        }
        curr->word = true;
    }
};

class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board, TrieNode* node, string& word,
             set<string>& res, vector<vector<bool>>& visited) {

        int ROWS = board.size(), COLS = board[0].size();

        if (r < 0 || c < 0  || r == ROWS || c == COLS || visited[r][c] || node->children_.count(board[r][c]) == 0) {
            return;
        }

        visited[r][c] = true;
        node = node->children_[board[r][c]];
        word.push_back(board[r][c]);

        if (node->word) {
            res.insert(word);
        }

        dfs(r + 1, c, board, node, word, res, visited);
        dfs(r - 1, c, board, node, word, res, visited);
        dfs(r, c + 1, board, node, word, res, visited);
        dfs(r, c - 1, board, node, word, res, visited);

        word.pop_back();
        visited[r][c] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie root;
        int ROWS = board.size(), COLS = board[0].size();

        set<string> res;
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        string word;

        for (auto word : words) {
            root.addWord(word);
        }

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                dfs(i, j, board, &root.root_, word, res, visited);
            }
        }

        return vector<string>(res.begin(), res.end());
    }
};


//Prefix and Suffix Search
//https://leetcode.com/problems/prefix-and-suffix-search/
/*
class TrieNode {
    public:
    unordered_map<char, TrieNode*> children_;
    int maxIndex = -1;
};
class Trie{
    public:
    TrieNode root_;

    void addWord(string word, int index){
        TrieNode* curr = &root_;
        for (char c : word){
            if(curr->children_.count(c) == 0){
                curr -> children_[c] = new TrieNode();
            }
            curr = curr -> children_[c];
            curr->maxIndex = max(curr->maxIndex, index);
        }
    }

    int search(const string& word) {
        TrieNode* curr = &root_;
        for (char c : word) {
            if (curr->children_.count(c) == 0) {
                return -1;
            }
            curr = curr->children_[c];
        }
        return curr->maxIndex;
}
};
class WordFilter {
public:
    Trie trie;
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            int n = word.size();

            for (int j = 0; j <= n; j++) {
                string newWord = word.substr(j) + "#" + word;
                trie.addWord(newWord, i);
            }
        }
    }

    int f(string pref, string suff) {
        string searchWord = suff + "#" + pref;
        return trie.search(searchWord);
    }
};
*/