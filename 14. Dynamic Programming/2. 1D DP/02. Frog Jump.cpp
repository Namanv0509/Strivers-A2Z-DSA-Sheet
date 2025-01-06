/*
QUESTION:-
Geek wants to climb from the 0th stair to the (n-1)th stair. At a time, the Geek can climb either one or two steps.
A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is abs(height[i] - height[j]), where abs() means the absolute difference.
Return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.

Approach:
1. We can use dynamic programming with memoization to find the minimum energy required to jump from the 0th stair to the (n-1)th stair.
2. We define a helper function fmemo(i, h, dp) that calculates the minimum energy required to jump from the 0th stair to the ith stair using memoization.
3. The function checks if the minimum energy for the ith stair is already calculated and stored in the dp array. If yes, it returns the value from dp.
4. Otherwise, it calculates the minimum energy by taking two possible jumps - either from (i-1)th stair or from (i-2)th stair - and stores the result in dp[i].
5. The base case is when i is 0, in which case the function returns 0 as the Geek is already at the 0th stair.
6. In the main function minimumEnergy(height, n), we create a dp array of size n initialized with -1 and call the fmemo function passing n-1 (last stair), the height array, and the dp array as arguments.

Complexity Analysis:
- The time complexity of the fmemo function is O(n) because we are calculating and storing the minimum energy for each stair.
- The space complexity is also O(n) to store the dp array.
*/

// Memoization
class Solution:
#MEMOIZATION
    # def helper(self,height,i,dp):
    #     if i<1:return 0
        
    #     if dp[i] != -1: return dp[i]
        
    #     jump_one = self.helper(height,i-1,dp) + abs(height[i] - height[i-1])
        
    #     jump_two = float('inf')
    #     if (i>1):
    #         jump_two = self.helper(height,i-2,dp) + abs(height[i] - height[i-2])
            
    #     dp[i] = min(jump_one,jump_two)
    #     return dp[i]
        
    # def minimumEnergy(self, height, n):
    #     dp = [-1] * (n+1)
    #     return self.helper(height,n-1,dp)
    
    
#TABULATION
    def minimumEnergy(self,height,i):
        n = len(height)
        dp = [-1] * (n+1)
        dp[0] = 0
        for ind in range(1, n):
            jumpTwo = float('inf')
            jumpOne = dp[ind-1] + abs(height[ind]-height[ind-1])
            if ind > 1:
                jumpTwo = dp[ind-2] + abs(height[ind]-height[ind-2])
            dp[ind] = min(jumpOne, jumpTwo)
        return(dp[n-1])
