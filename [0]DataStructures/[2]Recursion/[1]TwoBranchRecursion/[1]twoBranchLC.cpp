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

#include <unordered_map>
using namespace std;

//There are better ways to solve this problem for larger numbers
class Solution {
public:
    int helper(int n, unordered_map<int, int>& memo) {
        if (n <= 1) {
            return 1;
        }

        if (memo.count(n)) {
            return memo[n];
        }

        memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
        return memo[n];
    }

    int climbStairs(int n) {
        unordered_map<int, int> memo;
        return helper(n, memo);
    }
};






