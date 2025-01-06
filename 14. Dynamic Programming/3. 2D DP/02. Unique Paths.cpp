/*
QUESTION:-
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

Example 1:
Input: m = 3, n = 7
Output: 28

Approach:
1. We can solve this problem using dynamic programming with memoization (top-down approach).
2. We define a helper function fmemo(i, j, dp) that calculates the number of unique paths from the top-left corner (0, 0) to the cell (i, j) on the grid.
3. The function checks if the number of unique paths for the cell (i, j) is already calculated and stored in the dp array. If yes, it returns the value from dp.
4. Otherwise, it calculates the number of unique paths for the cell (i, j) by adding the number of unique paths from the cell above (i-1, j) and the cell to the left (i, j-1).
5. The base case is when i or j is less than 0, in which case the function returns 0 as there are no paths to reach those cells.
6. In the main function uniquePaths(m, n), we create a dp array of size m x n initialized with -1 and call the fmemo function for the bottom-right cell (m-1, n-1).
7. Finally, we return the number of unique paths obtained for the bottom-right cell as the result.

Complexity Analysis:
- The time complexity of the fmemo function is O(m x n) because we are calculating the number of unique paths for each cell only once and storing it in the dp array.
- The space complexity is also O(m x n) to store the dp array.

Note: The given test cases are generated such that the answer will be less than or equal to 2 x 10^9.
*/

//Memeoization

def countWaysUtil(i, j, dp):
    # Base case: If we reach the top-left corner (i=0, j=0), there is one way to reach there.
    if i == 0 and j == 0:
        return 1
    # If either i or j goes out of bounds (negative), there is no way to reach that cell.
    if i < 0 or j < 0:
        return 0
    # If we have already calculated the number of ways for this cell, return it from the dp array.
    if dp[i][j] != -1:
        return dp[i][j]
    
    # Recursive calls to count the number of ways to reach the current cell.
    up = countWaysUtil(i - 1, j, dp)    # Moving up one row.
    left = countWaysUtil(i, j - 1, dp)  # Moving left one column.
    
    # Store the result in the dp array and return it.
    dp[i][j] = up + left
    return dp[i][j]

def countWays(m, n):
    # Initialize a memoization (dp) array to store intermediate results.
    dp = [[-1 for j in range(n)] for i in range(m)]
    
    # Call the utility function to compute the number of ways to reach the bottom-right cell (m-1, n-1).
    return countWaysUtil(m - 1, n - 1, dp)

def main():
    m = 3
    n = 2
    # Call the countWays function to calculate and print the number of ways to reach the destination.
    print(countWays(m, n))

if __name__ == '__main__':
    main()



//Tabulation

def countWaysUtil(m, n, dp):
    # Loop through each cell in the grid
    for i in range(m):
        for j in range(n):
            # Base condition: If we are at the top-left corner, there is one way to reach it.
            if i == 0 and j == 0:
                dp[i][j] = 1
                continue
            
            # Initialize variables to store the number of ways from above and from the left.
            up = 0
            left = 0
            
            # Check if moving up is a valid option (not out of bounds).
            if i > 0:
                up = dp[i - 1][j]
            
            # Check if moving left is a valid option (not out of bounds).
            if j > 0:
                left = dp[i][j - 1]
            
            # Calculate and store the number of ways to reach the current cell.
            dp[i][j] = up + left
    
    # The bottom-right cell (m-1, n-1) now contains the total number of ways to reach there.
    return dp[m - 1][n - 1]

def countWays(m, n):
    # Initialize a memoization (dp) array to store intermediate results.
    dp = [[-1 for j in range(n)] for i in range(m)]
    
    # Call the utility function to compute the number of ways to reach the destination.
    return countWaysUtil(m, n, dp)

def main():
    m = 3
    n = 2
    # Call the countWays function to calculate and print the number of ways to reach the destination.
    print(countWays(m, n))

if __name__ == '__main__':
    main()



//Space Optimization

def countWays(m, n):
    # Initialize a previous row to store intermediate results.
    prev = [0] * n

    # Loop through each row of the grid.
    for i in range(m):
        # Initialize a temporary row to store current row results.
        temp = [0] * n
        
        # Loop through each column of the grid.
        for j in range(n):
            # Base case: If we are at the top-left corner, there is one way to reach it.
            if i == 0 and j == 0:
                temp[j] = 1
                continue
            
            # Initialize variables to store the number of ways from above and from the left.
            up = 0
            left = 0
            
            # Check if moving up is a valid option (not out of bounds).
            if i > 0:
                up = prev[j]
            
            # Check if moving left is a valid option (not out of bounds).
            if j > 0:
                left = temp[j - 1]
                
            # Calculate and store the number of ways to reach the current cell.
            temp[j] = up + left
        
        # Update the previous row with the current row results.
        prev = temp
    
    # The last element in the previous row (prev) now contains the total number of ways to reach the destination.
    return prev[n - 1]

def main():
    m = 3
    n = 2
    # Call the countWays function to calculate and print the number of ways to reach the destination.
    print(countWays(m, n))

if __name__ == '__main__':
    main()


