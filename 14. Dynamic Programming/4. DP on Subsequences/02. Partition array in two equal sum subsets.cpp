/*
QUESTION:

Given an integer array `nums`, return `true` if you can partition the array into two subsets such that the sum of the elements in both subsets is equal, or `false` otherwise.

Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

APPROACH:

- To solve this problem, we can use dynamic programming.
- We'll create a 2D DP array where `dp[i][j]` represents whether it's possible to select a subset from the first `i` elements of the `nums` array that sums up to `j`.
- The base case is when `j` is 0, in which case it's always possible to select an empty subset.
- For each element in the `nums` array, we have two choices: include it in the subset or exclude it.
- So, the recurrence relation becomes:
  dp[i][j] = dp[i - 1][j] (exclude nums[i]) || dp[i - 1][j - nums[i]] (include nums[i])

COMPLEXITY ANALYSIS:

- The time complexity of this approach is O(n * sum), where `n` is the number of elements in the `nums` array and `sum` is the sum of all elements.

CODE:
*/
// Memoization

def subsetSumUtil(ind, target, arr, dp):
    # Base case: If the target sum is 0, we have found a subset that sums to the target.
    if target == 0:
        return True
    
    # Base case: If we have reached the first element of the array, check if it equals the target.
    if ind == 0:
        return arr[0] == target
    
    # Check if the result for this combination of 'ind' and 'target' has already been computed.
    if dp[ind][target] != -1:
        return dp[ind][target]
    
    # Recursive cases:
    # 1. Try not taking the current element.
    notTaken = subsetSumUtil(ind - 1, target, arr, dp)
    
    # 2. Try taking the current element if it is less than or equal to the target.
    taken = False
    if arr[ind] <= target:
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp)
        
    # Update the DP table and return the result.
    dp[ind][target] = notTaken or taken
    return dp[ind][target]

def canPartition(n, arr):
    # Calculate the total sum of the array elements.
    totSum = sum(arr)
    
    # If the total sum is odd, it cannot be partitioned into two equal subsets.
    if totSum % 2 == 1:
        return False
    else:
        # Calculate the target sum for each subset.
        k = totSum // 2
        
        # Initialize a memoization table for dynamic programming.
        dp = [[-1 for i in range(k + 1)] for j in range(n)]
        
        # Call the subsetSumUtil function to check if a subset with sum 'k' exists.
        return subsetSumUtil(n - 1, k, arr, dp)

def main():
    arr = [2, 3, 3, 3, 4, 5]
    n = len(arr)
    
    # Check if the array can be partitioned into two equal subsets and print the result.
    if canPartition(n, arr):
        print("The Array can be partitioned into two equal subsets")
    else:
        print("The Array cannot be partitioned into two equal subsets")

if __name__ == "__main__":
    main()



// Tabulation

def canPartition(n, arr):
    # Calculate the total sum of the array elements.
    totSum = sum(arr)
    
    # If the total sum is odd, it cannot be partitioned into two equal subsets.
    if totSum % 2 == 1:
        return False
    else:
        # Calculate the target sum for each subset.
        k = totSum // 2
        
        # Initialize a dynamic programming table (dp) to store subproblem results.
        dp = [[False for j in range(k + 1)] for i in range(n)]

        # Initialize the base case: An empty subset can always achieve a sum of 0.
        for i in range(n):
            dp[i][0] = True

        # Initialize the base case for the first element in the array.
        if arr[0] <= k:
            dp[0][arr[0]] = True

        # Fill in the DP table using a bottom-up approach.
        for ind in range(1, n):
            for target in range(1, k + 1):
                # If the current element is not taken, the result is the same as the previous row.
                notTaken = dp[ind - 1][target]
                
                # If the current element is taken, subtract its value from the target and check the previous row.
                taken = False
                if arr[ind] <= target:
                    taken = dp[ind - 1][target - arr[ind]]
                
                # Update the DP table with the result of taking or not taking the current element.
                dp[ind][target] = notTaken or taken
        
        # The final result is stored in the bottom-right cell of the DP table.
        return dp[n - 1][k]

def main():
    arr = [2, 3, 3, 3, 4, 5]
    n = len(arr)
    
    # Check if the array can be partitioned into two equal subsets and print the result.
    if canPartition(n, arr):
        print("The Array can be partitioned into two equal subsets")
    else:
        print("The Array cannot be partitioned into two equal subsets")

if __name__ == '__main__':
    main()


// Space Optimization

def canPartition(n, arr):
    # Calculate the total sum of the array elements.
    totSum = sum(arr)
    
    # If the total sum is odd, it cannot be partitioned into two equal subsets.
    if totSum % 2 == 1:
        return False
    else:
        # Calculate the target sum for each subset.
        k = totSum // 2
        
        # Initialize a boolean array 'prev' to store the results for the previous row.
        prev = [False] * (k + 1)
        prev[0] = True  # Base case: An empty subset can always achieve a sum of 0.
        
        # Handle the base case for the first element in the array.
        if arr[0] <= k:
            prev[arr[0]] = True

        # Iterate through the elements in the array.
        for ind in range(1, n):
            # Initialize a new boolean array 'cur' for the current row.
            cur = [False] * (k + 1)
            cur[0] = True  # An empty subset can always achieve a sum of 0.

            # Fill in the 'cur' array using dynamic programming.
            for target in range(1, k + 1):
                # If the current element is not taken, the result is the same as the previous row.
                notTaken = prev[target]
                
                # If the current element is taken, subtract its value from the target and check the previous row.
                taken = False
                if arr[ind] <= target:
                    taken = prev[target - arr[ind]]
                
                # Update the 'cur' array with the result of taking or not taking the current element.
                cur[target] = notTaken or taken
            
            # Update 'prev' to 'cur' for the next iteration.
            prev = cur
        
        # The final result is stored in 'prev[k]', indicating whether a subset with sum 'k' is possible.
        return prev[k]

def main():
    arr = [2, 3, 3, 3, 4, 5]
    n = len(arr)
    
    # Check if the array can be partitioned into two equal subsets and print the result.
    if canPartition(n, arr):
        print("The Array can be partitioned into two equal subsets")
    else:
        print("The Array cannot be partitioned into two equal subsets")

if __name__ == "__main__":
    main()

