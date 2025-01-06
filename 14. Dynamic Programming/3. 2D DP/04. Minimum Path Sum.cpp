/*
QUESTION:-
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Approach:
1. We can solve this problem using dynamic programming with memoization (top-down approach).
2. We define a helper function fmemo(i, j, grid, dp) that calculates the minimum sum path to reach the cell (i, j) on the grid.
3. The function checks if the minimum sum path for the cell (i, j) is already calculated and stored in the dp array. If yes, it returns the value from dp.
4. If i or j is less than 0 (out of bounds), the function returns a large value (e.g., 1e9) to represent an invalid path.
5. The base case is when i and j are both 0, in which case the function returns the value in the cell (0, 0) as the minimum sum path.
6. Otherwise, it calculates the minimum sum path for the cell (i, j) by taking the minimum of the minimum sum paths from the cell above (i-1, j) and the cell to the left (i, j-1), and then adding the value in the current cell (grid[i][j]).
7. The result is stored in the dp array to avoid recomputation when the function is called with the same parameters again.

Complexity Analysis:
- The time complexity of the fmemo function is O(m x n) because we are calculating the minimum sum path for each cell only once and storing it in the dp array.
- The space complexity is also O(m x n) to store the dp array.

*/

// Memoization

def minSumPathUtil(i, j, matrix, dp):
    # Base case: If we are at the top-left corner, return the value of that cell.
    if i == 0 and j == 0:
        return matrix[0][0]
    
    # Base case: If we are out of bounds (negative indices), return a very large value.
    if i < 0 or j < 0:
        return int(1e9)
    
    # If we have already calculated the minimum sum for this cell, return it.
    if dp[i][j] != -1:
        return dp[i][j]

    # Calculate the minimum sum path recursively by considering both up and left moves.
    up = matrix[i][j] + minSumPathUtil(i-1, j, matrix, dp)
    left = matrix[i][j] + minSumPathUtil(i, j-1, matrix, dp)

    # Store the minimum of the two possible paths in the DP table.
    dp[i][j] = min(up, left)
    return dp[i][j]


def minSumPath(n, m, matrix):
    # Create a DP table initialized with -1 values.
    dp = [[-1 for j in range(m)] for i in range(n)]
    
    # Call the utility function to find the minimum sum path.
    return minSumPathUtil(n-1, m-1, matrix, dp)


def main():
    # Example matrix with values representing cell costs.
    matrix = [[5, 9, 6],
              [11, 5, 2]]

    n = len(matrix)
    m = len(matrix[0])

    # Call the minSumPath function and print the result.
    print(minSumPath(n, m, matrix))


if __name__ == '__main__':
    main()



// Tabulation

def minSumPath(n, m, matrix):
    # Create a DP table initialized with zeros.
    dp = [[0 for j in range(m)] for i in range(n)]
    
    # Loop through each cell in the matrix.
    for i in range(n):
        for j in range(m):
            if i == 0 and j == 0:
                # Base case: If we are at the top-left corner, set dp[i][j] to the value of that cell.
                dp[i][j] = matrix[i][j]
            else:
                # Calculate the cost of moving up from the cell (i, j).
                up = matrix[i][j]
                if i > 0:
                    up += dp[i-1][j]
                else:
                    # If we are at the top row and can't move up, set 'up' to a large value.
                    up += int(1e9)
                
                # Calculate the cost of moving left from the cell (i, j).
                left = matrix[i][j]
                if j > 0:
                    left += dp[i][j-1]
                else:
                    # If we are at the leftmost column and can't move left, set 'left' to a large value.
                    left += int(1e9)
                
                # Store the minimum cost of reaching the current cell in dp[i][j].
                dp[i][j] = min(up, left)
    
    # The result is stored in the bottom-right corner of the DP table.
    return dp[n-1][m-1]

def main():
    # Example matrix with values representing cell costs.
    matrix = [[5, 9, 6], [11, 5, 2]]
    n = len(matrix)
    m = len(matrix[0])
    
    # Call the minSumPath function and print the result.
    print(minSumPath(n, m, matrix))

if __name__ == "__main__":
    main()



// Space Optimization

def minSumPath(n, m, matrix):
    # Initialize the 'prev' list to keep track of the minimum cost in the previous row.
    prev = [0] * m
    
    # Loop through each row of the matrix.
    for i in range(n):
        # Initialize a temporary list to store the minimum cost for the current row.
        temp = [0] * m
        
        # Loop through each cell in the current row.
        for j in range(m):
            if i == 0 and j == 0:
                # Base case: If we are at the top-left corner, set 'temp[j]' to the value of that cell.
                temp[j] = matrix[i][j]
            else:
                # Calculate the cost of moving up from the cell (i, j).
                up = matrix[i][j]
                if i > 0:
                    up += prev[j]
                else:
                    # If we are at the top row and can't move up, set 'up' to a large value.
                    up = int(1e9)
                
                # Calculate the cost of moving left from the cell (i, j).
                left = matrix[i][j]
                if j > 0:
                    left += temp[j-1]
                else:
                    # If we are at the leftmost column and can't move left, set 'left' to a large value.
                    left = int(1e9)
                
                # Store the minimum cost of reaching the current cell in 'temp[j]'.
                temp[j] = min(up, left)
        
        # Update 'prev' with the 'temp' list for the next iteration.
        prev = temp
    
    # The result is stored in the last element of the 'prev' list (bottom-right corner).
    return prev[m - 1]

def main():
    # Example matrix with values representing cell costs.
    matrix = [[5, 9, 6], [11, 5, 2]]
    n = len(matrix)
    m = len(matrix[0])
    
    # Call the minSumPath function and print the result.
    print(minSumPath(n, m, matrix))

if __name__ == '__main__':
    main()


