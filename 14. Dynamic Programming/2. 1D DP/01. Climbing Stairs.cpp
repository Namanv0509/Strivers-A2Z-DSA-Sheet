/*
QUESTION:-
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Approach:
1. We can use dynamic programming with memoization to calculate the number of distinct ways to climb the staircase.
2. We define a helper function fmemo(n, dp) that calculates the number of distinct ways to climb n steps using memoization.
3. The function checks if the number of ways to climb n steps is already calculated and stored in the dp array. If yes, it returns the value from dp.
4. Otherwise, it calculates the number of ways to climb n steps by recursively calling fmemo(n-1, dp) and fmemo(n-2, dp) and stores the result in dp.
5. The base cases are when n is 1 or 2, in which case the function returns n.
6. In the main function climbStairs(n), we check if n is 1 or 2. If yes, we directly return n as the number of distinct ways to climb.
7. Otherwise, we create a dp array of size n+1 initialized with -1 and call the fmemo function passing n and the dp array as arguments.

Complexity Analysis:
- The time complexity of the fmemo function is O(n) because we are calculating and storing the number of ways to climb n steps.
- The space complexity is also O(n) to store the dp array.
*/


// Memoization
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0 or n == 1:
            return 1

        dp = [0] * (n+1)
        dp[0] = dp[1] = 1
        
        for i in range(2, n+1):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n]
