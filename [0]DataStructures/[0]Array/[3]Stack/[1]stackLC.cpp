//Baseball Game
//https://leetcode.com/problems/baseball-game/
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record; // Vector to simulate stack behavior
        for (string op : operations) {
            if (op == "+") {
                // Sum of the last two scores
                int n = record.size();
                record.push_back(record[n - 1] + record[n - 2]);
            } else if (op == "D") {
                // Double the last score
                record.push_back(2 * record.back());
            } else if (op == "C") {
                // Remove the last score
                record.pop_back();
            } else {
                // Add a new integer score
                record.push_back(stoi(op));
            }
        }

        // Sum up all the scores
        int sum = 0;
        for (int score : record) {
            sum += score;
        }
        return sum;
    }
};

//We used vector instead of stack because we need to access the last two elements of the 
//stack to calculate the sum of the last two scores.












//Valid Parentheses
//https://leetcode.com/problems/valid-parentheses/
#include <string>
#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '{' || ch == '[' || ch == '(') {
                st.push(ch);
            } else {
                if (st.empty() || 
                    (ch == '}' && st.top() != '{') || 
                    (ch == ')' && st.top() != '(') || 
                    (ch == ']' && st.top() != '[')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

//There is alternate solution using hashmap to store the mapping of the closing and opening brackets.








//Min Stack
//https://leetcode.com/problems/min-stack/
class MinStack {
public:
    vector<int> stack;
    vector<int> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val); // Push the value to the main stack
        // Push the smaller of the current value or the last minimum value onto minStack
        if (minStack.empty() || val <= minStack.back()) {
            minStack.push_back(val);
        } else {
            minStack.push_back(minStack.back());
        }
    }
    
    void pop() {
        stack.pop_back();
        minStack.pop_back();
    }
    
    int top() {
         return stack.back();
    }
    
    int getMin() {
        return minStack.back(); 
    }
};

