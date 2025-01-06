/*
QUESTION:-
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

Example:
Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1
Explanation: Here there exists a subset with sum = 9, 4+3+2 = 9.

Approach:
1. We can solve this problem using dynamic programming with memoization (top-down approach).
2. We define a helper function fmemo(i, sum, arr, dp) that checks if there is a subset of elements up to index i whose sum is equal to the given sum.
3. The function checks if the target sum is 0. If yes, it means we have found a subset with the given sum and returns true.
4. If i is 0, it means we are at the first element, so the function checks if the first element is equal to the target sum.
5. If the dp value for the current index and sum is already calculated, it returns the stored value.
6. If the current element (arr[i]) is less than or equal to the target sum, the function recursively checks for two cases: including the current element in the subset (by reducing the sum) or excluding it (by not changing the sum).
7. If any of the above cases returns true, the dp value for the current index and sum is updated to true.
8. Finally, we return the dp value for the last index and the given sum.

Complexity Analysis:
- The time complexity of the fmemo function is O(n * sum), where n is the number of elements in the array and sum is the target sum. This is because the function calculates the result for each index and sum only once and stores it in the dp array.
- The space complexity is also O(n * sum) to store the dp array.

*/


// Memoization

def subsetSumUtil(ind, target, arr, dp):
    # Check if the target sum has been achieved.
    if target == 0:
        return True

    # If we have reached the first element in the array.
    if ind == 0:
        return arr[0] == target

    # Check if the result for this combination of 'ind' and 'target' has already been computed.
    if dp[ind][target] != -1:
        return dp[ind][target]

    # Recursively try not taking the current element.
    notTaken = subsetSumUtil(ind - 1, target, arr, dp)

    taken = False
    # Check if the current element can be taken without exceeding the target.
    if arr[ind] <= target:
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp)

    # Store the result in the dp array to avoid recomputation.
    dp[ind][target] = notTaken or taken
    return dp[ind][target]

def subsetSumToK(n, k, arr):
    # Initialize a memoization table with -1.
    dp = [[-1 for j in range(k + 1)] for i in range(n)]

    # Call the utility function to find if a subset with the given target sum exists.
    return subsetSumUtil(n - 1, k, arr, dp)

def main():
    arr = [1, 2, 3, 4]
    k = 4
    n = len(arr)

    if subsetSumToK(n, k, arr):
        print("Subset with the given target found")
    else:
        print("Subset with the given target not found")

if __name__ == "__main__":
    main()

// Tabulation

def subsetSumToK(n, k, arr):
    # Initialize a 2D DP table with False values.
    dp = [[False for j in range(k + 1)] for i in range(n)]
    
    # Set the first column to True since a sum of 0 is always possible with an empty subset.
    for i in range(n):
        dp[i][0] = True
    
    # Check if the first element of the array can be used to make the target sum.
    if arr[0] <= k:
        dp[0][arr[0]] = True
    
    # Fill in the DP table iteratively.
    for ind in range(1, n):
        for target in range(1, k + 1):
            notTaken = dp[ind - 1][target]  # Not taking the current element.
            taken = False
            # Check if taking the current element is possible without exceeding the target.
            if arr[ind] <= target:
                taken = dp[ind - 1][target - arr[ind]]
            dp[ind][target] = notTaken or taken  # Update the DP table with the result.
    
    # The final result is stored in the bottom-right cell of the DP table.
    return dp[n - 1][k]

def main():
    arr = [1, 2, 3, 4]
    k = 4
    n = len(arr)

    if subsetSumToK(n, k, arr):
        print("Subset with the given target found")
    else:
        print("Subset with the given target not found")

if __name__ == '__main__':
    main()



// Space Optimization

def subset_sum_to_k(n, k, arr):
    # Initialize a boolean array 'prev' with size (k + 1).
    prev = [False] * (k + 1)
    
    # Set the first element of 'prev' to True since an empty subset can sum up to 0.
    prev[0] = True
    
    # Check if the first element of 'arr' can directly contribute to the target sum 'k'.
    if arr[0] <= k:
        prev[arr[0]] = True

    # Loop through the elements of 'arr' and update 'prev' using dynamic programming.
    for ind in range(1, n):
        # Initialize a new boolean array 'cur' for the current element.
        cur = [False] * (k + 1)
        
        # An empty subset can always sum up to 0.
        cur[0] = True
        
        for target in range(1, k + 1):
            not_taken = prev[target]  # Previous result without including the current element.
            taken = False
            
            # Check if including the current element is possible without exceeding the target.
            if arr[ind] <= target:
                taken = prev[target - arr[ind]]
            
            # Update 'cur' with the result for the current 'target'.
            cur[target] = not_taken or taken
        
        # Update 'prev' with the results for the current element 'ind'.
        prev = cur

    # The final result is stored in 'prev[k]'.
    return prev[k]

def main():
    arr = [1, 2, 3, 4]
    k = 4
    n = len(arr)

    if subset_sum_to_k(n, k, arr):
        print("Subset with the given target found")
    else:
        print("Subset with the given target not found")

if __name__ == "__main__":
    main()


