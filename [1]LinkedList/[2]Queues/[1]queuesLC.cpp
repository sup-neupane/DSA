//Number of Students Unable to Eat Lunch
//https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studentQueue;
        for (int student : students) {
            studentQueue.push(student);
        }

        int sandwichIndex = 0;
        int rotations = 0;

        // Iterate until all sandwiches are served or no student can eat the top sandwich
        while (!studentQueue.empty() && rotations < studentQueue.size()) {
            if (studentQueue.front() == sandwiches[sandwichIndex]) {
                studentQueue.pop();
                sandwichIndex++;
                rotations = 0; // Reset the counter
            } else {
                studentQueue.push(studentQueue.front());
                studentQueue.pop();
                rotations++;
            }
        }

        // The remaining students in the queue are unable to eat
        return studentQueue.size();
    }
};

//Hash is better to solve this problem

//Implement Stack using Queues
//https://leetcode.com/problems/implement-stack-using-queues/
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
    }

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int topElement = q1.front();
        q1.pop();
        swap(q1, q2);
        return topElement;
    }

    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int topElement = q1.front();
        q2.push(topElement);
        q1.pop();
        swap(q1, q2);
        return topElement;
    }

    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
