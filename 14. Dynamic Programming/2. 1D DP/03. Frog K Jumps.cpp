/*
QUESTION:-
Geek wants to climb from the 0th stair to the (n-1)th stair. At a time, the Geek can climb k steps.
A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is abs(height[i] - height[j]), where abs() means the absolute difference.
Return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.

Example:
Input:
4 2
10 40 30 10
Output:
40

Explanation:
For 'n' = 4, 'k' = 2, height = {10, 40, 30, 10}

Initially, we are present at stone 1 having height 10. We can reach stone 3 as 'k' is 2. So, the cost incurred is |10 - 30| = 20.

Now, we are present at stone 3, we can reach stone 4 as 'k' is 2. So, the cost incurred is |30 - 10| = 20. So, the total cost is 40. We can show any other path will lead to greater cost.

Approach:
1. We can use dynamic programming with memoization to find the minimum energy required to jump from the 0th stair to the (n-1)th stair.
2. We define a helper function fmemo(i, k, h, dp) that calculates the minimum energy required to jump from the 0th stair to the ith stair using memoization.
3. The function checks if the minimum energy for the ith stair is already calculated and stored in the dp array. If yes, it returns the value from dp.
4. Otherwise, it calculates the minimum energy by considering all possible jumps from i-j (where j varies from 1 to k) and stores the result in dp[i].
5. The base case is when i is 0, in which case the function returns 0 as the Geek is already at the 0th stair.
6. In the main function minimizeCost(n, k, height), we create a dp array of size n initialized with -1 and call the fmemo function passing n-1 (last stair), k, the height array, and the dp array as arguments.

Complexity Analysis:
- The time complexity of the fmemo function is O(n*k) because we are calculating and storing the minimum energy for each stair and considering k possible jumps at each stair.
- The space complexity is also O(n) to store the dp array.
*/

// Memoization

import sys
import math

def solve(ind, height, dp):
    if ind == 0:
        return 0
    if dp[ind] != -1:
        return dp[ind]
    jumpTwo = sys.maxsize
    jumpOne = solve(ind-1, height, dp) + abs(height[ind] - height[ind-1])
    if ind > 1:
        jumpTwo = solve(ind-2, height, dp) + abs(height[ind] - height[ind-2])
    dp[ind] = min(jumpOne, jumpTwo)
    return dp[ind]

if __name__ == "__main__":
    height = [30, 10, 60, 10, 60, 50]
    n = len(height)
    dp = [-1] * n
    print(solve(n-1, height, dp))



// Tabulation

def main():
    height = [30, 10, 60, 10, 60, 50]
    n = len(height)
    dp = [-1 for _ in range(n)]
    dp[0] = 0
    for ind in range(1, n):
        jumpTwo = float('inf')
        jumpOne = dp[ind-1] + abs(height[ind]-height[ind-1])
        if ind > 1:
            jumpTwo = dp[ind-2] + abs(height[ind]-height[ind-2])
        dp[ind] = min(jumpOne, jumpTwo)
    print(dp[n-1])

if __name__ == "__main__":
    main()


