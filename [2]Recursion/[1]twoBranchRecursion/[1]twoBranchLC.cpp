// 1. Fibonacci Number
// https://leetcode.com/problems/fibonacci-number/
class Solution {
public:
    int fib(int n) {
        if(n<=1){
            return n;
        }
        return fib(n-1) + fib(n-2);
    }
};







//Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/
//This is the solution but you need to use memoization for efficiency:
class Solution {
public:
    int climbStairs(int n) {
      if (n == 0 || n == 1) {
        return 1;
      } 
       return climbStairs(n-1) + climbStairs(n-2);
    }
};


//There are better ways to solve this problem for larger numbers

#include <vector>
using namespace std;
//With memoization:
class Solution {
public:
    int climbStairs(int n) {
        // Create a memoization array initialized with -1
        vector<int> memo(n + 1, -1);
        return climb(n, memo);
    }
    
    int climb(int n, vector<int>& memo) {
        // Base cases
        if (n == 0) return 1; // 1 way to stay at step 0
        if (n == 1) return 1; // 1 way to reach step 1
        
        // Check if already computed
        if (memo[n] != -1) return memo[n];
        
        // Recurrence relation
        memo[n] = climb(n - 1, memo) + climb(n - 2, memo);
        return memo[n];
    }
};






