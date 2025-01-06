/*
QUESTION:-
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Approach:
1. We can solve this problem using dynamic programming with memoization (top-down approach).
2. We define a helper function fmemo(i, j, mat, dp) that calculates the minimum sum of any falling path starting from cell (i, j).
3. The function checks if the minimum sum for the current cell (i, j) is already calculated and stored in the dp array. If yes, it returns the value from dp.
4. If i is 0, it means we are at the first row, so the minimum sum starting from this cell is the value in the current cell (mat[i][j]).
5. Otherwise, the function calculates the minimum sum for the current cell by taking the minimum of the minimum sums of the cells above it (i-1, j-1), (i-1, j), and (i-1, j+1), and then adding the value in the current cell (mat[i][j]).
6. The result is stored in the dp array to avoid recomputation when the function is called with the same parameters again.
7. Finally, we find the minimum falling path sum for all cells in the first row and return the smallest value.

Complexity Analysis:
- The time complexity of the fmemo function is O(n^2) since we are calculating the minimum sum for each cell only once and storing it in the dp array.
- The space complexity is also O(n^2) to store the dp array.

Solution : https://takeuforward.org/data-structure/minimum-maximum-falling-path-sum-dp-12/

*/

// Memoization

import sys

# Recursive function to find the maximum path sum starting from cell (i, j)
def getMaxUtil(i, j, m, matrix, dp):
    # Base case: If j is out of bounds, return a large negative value
    if j < 0 or j >= m:
        return -int(1e9)
    
    # Base case: If we are at the top row (i == 0), return the value in the current cell
    if i == 0:
        return matrix[0][j]
    
    # Check if the maximum path sum for this cell has already been computed
    if dp[i][j] != -1:
        return dp[i][j]
    
    # Calculate three possible moves: going up, going up-left, and going up-right
    up = matrix[i][j] + getMaxUtil(i - 1, j, m, matrix, dp)
    leftDiagonal = matrix[i][j] + getMaxUtil(i - 1, j - 1, m, matrix, dp)
    rightDiagonal = matrix[i][j] + getMaxUtil(i - 1, j + 1, m, matrix, dp)
    
    # Store the maximum of the three moves in the memoization table
    dp[i][j] = max(up, max(leftDiagonal, rightDiagonal))
    return dp[i][j]

# Function to find the maximum path sum in the matrix
def getMaxPathSum(matrix):
    n = len(matrix)  # Number of rows
    m = len(matrix[0])  # Number of columns
    dp = [[-1 for j in range(m)] for i in range(n)]  # Initialize a memoization table
    maxi = -sys.maxsize  # Initialize the maximum sum to a large negative value
    
    # Iterate through the first row and find the maximum path sum starting from each cell
    for j in range(m):
        ans = getMaxUtil(n - 1, j, m, matrix, dp)
        maxi = max(maxi, ans)
    
    return maxi  # Return the maximum path sum

def main():
    # Define the input matrix
    matrix = [[1, 2, 10, 4], [100, 3, 2, 1], [1, 1, 20, 2], [1, 2, 2, 1]]
    
    # Call the getMaxPathSum function and print the result
    print(getMaxPathSum(matrix))

if __name__ == "__main__":
    main()



// Tabulation

import sys

# Function to find the maximum path sum in the matrix
def getMaxPathSum(matrix):
    n = len(matrix)  # Number of rows
    m = len(matrix[0])  # Number of columns
    
    # Initialize a dynamic programming table (dp) with zeros
    dp = [[0 for j in range(m)] for i in range(n)]
    
    # Initializing the first row of dp as the base condition
    for j in range(m):
        dp[0][j] = matrix[0][j]
    
    # Iterate through the matrix to compute the maximum path sum
    for i in range(1, n):
        for j in range(m):
            # Calculate the three possible moves: up, left diagonal, and right diagonal
            up = matrix[i][j] + dp[i - 1][j]
            
            # Handle left diagonal
            left_diagonal = matrix[i][j]
            if j - 1 >= 0:
                left_diagonal += dp[i - 1][j - 1]
            else:
                left_diagonal += -int(1e9)  # A large negative value if out of bounds
            
            # Handle right diagonal
            right_diagonal = matrix[i][j]
            if j + 1 < m:
                right_diagonal += dp[i - 1][j + 1]
            else:
                right_diagonal += -int(1e9)  # A large negative value if out of bounds
            
            # Store the maximum of the three moves in dp
            dp[i][j] = max(up, left_diagonal, right_diagonal)
    
    # Find the maximum path sum in the last row of dp
    maxi = -sys.maxsize
    for j in range(m):
        maxi = max(maxi, dp[n - 1][j])
    
    return maxi  # Return the maximum path sum

def main():
    # Define the input matrix
    matrix = [[1, 2, 10, 4], [100, 3, 2, 1], [1, 1, 20, 2], [1, 2, 2, 1]]
    
    # Call the getMaxPathSum function and print the result
    print(getMaxPathSum(matrix))

if __name__ == "__main__":
    main()



// Space Optmization

import sys

# Function to find the maximum path sum in the matrix
def getMaxPathSum(matrix):
    n = len(matrix)  # Number of rows
    m = len(matrix[0])  # Number of columns

    # Initialize two lists: prev (previous row) and cur (current row)
    prev = [0] * m
    cur = [0] * m

    # Initializing the first row of prev as the base condition
    for j in range(m):
        prev[j] = matrix[0][j]

    # Iterate through the matrix to compute the maximum path sum
    for i in range(1, n):
        for j in range(m):
            # Calculate the three possible moves: up, left diagonal, and right diagonal
            up = matrix[i][j] + prev[j]

            leftDiagonal = matrix[i][j]
            if j - 1 >= 0:
                leftDiagonal += prev[j - 1]
            else:
                leftDiagonal += -int(1e9)  # A large negative value if out of bounds

            rightDiagonal = matrix[i][j]
            if j + 1 < m:
                rightDiagonal += prev[j + 1]
            else:
                rightDiagonal += -int(1e9)  # A large negative value if out of bounds

            # Store the maximum of the three moves in the current row (cur)
            cur[j] = max(up, max(leftDiagonal, rightDiagonal))

        # Update prev with the values of cur for the next iteration
        prev = cur[:]

    # Find the maximum path sum in the last row of prev
    maxi = -sys.maxsize
    for j in range(m):
        maxi = max(maxi, prev[j])

    return maxi  # Return the maximum path sum

def main():
    # Define the input matrix
    matrix = [[1, 2, 10, 4], [100, 3, 2, 1], [1, 1, 20, 2], [1, 2, 2, 1]]

    # Call the getMaxPathSum function and print the result
    print(getMaxPathSum(matrix))

if __name__ == '__main__':
    main()


