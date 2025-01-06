/*
QUESTION:-
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Approach:
1. We can solve this problem using dynamic programming with memoization (top-down approach).
2. We define a helper function fmemo(i, j, n, tri, dp) that calculates the minimum path sum from the current cell (i, j) to the bottom of the triangle.
3. The function checks if the minimum path sum for the current cell is already calculated and stored in the dp array. If yes, it returns the value from dp.
4. If i is equal to n-1, it means we are at the last row of the triangle, so the minimum path sum is the value in the current cell (tri[i][j]).
5. Otherwise, the function calculates the minimum path sum for the current cell by taking the minimum of the minimum path sums from the cells directly below (i+1, j) and (i+1, j+1), and then adding the value in the current cell (tri[i][j]).
6. The result is stored in the dp array to avoid recomputation when the function is called with the same parameters again.

Complexity Analysis:
- The time complexity of the fmemo function is O(n^2) because we are calculating the minimum path sum for each cell only once and storing it in the dp array.
- The space complexity is also O(n^2) to store the dp array.

*/

// Memoization

def minimumPathSumUtil(i, j, triangle, n, dp):
    # Check if we have already computed the minimum path sum for this cell
    if dp[i][j] != -1:
        return dp[i][j]

    # If we are at the bottom of the triangle, return the value in the current cell
    if i == n - 1:
        return triangle[i][j]

    # Calculate the minimum path sum by considering two possible moves: down and diagonal
    down = triangle[i][j] + minimumPathSumUtil(i + 1, j, triangle, n, dp)
    diagonal = triangle[i][j] + minimumPathSumUtil(i + 1, j + 1, triangle, n, dp)

    # Store the computed minimum path sum in the memoization table
    dp[i][j] = min(down, diagonal)
    return dp[i][j]

# Define a wrapper function to initialize memoization table and start the computation
def minimumPathSum(triangle, n):
    dp = [[-1 for j in range(n)] for i in range(n)]  # Initialize a memoization table with -1
    return minimumPathSumUtil(0, 0, triangle, n, dp)  # Start the recursive computation

# Define the main function where you set up the triangle and call the minimumPathSum function
def main():
    triangle = [[1], [2, 3], [3, 6, 7], [8, 9, 6, 10]]
    n = len(triangle)

    # Call the minimumPathSum function and print the result
    print(minimumPathSum(triangle, n))

# Check if this script is the main program entry point
if __name__ == "__main__":
    main()  # Call the main function to start the program


// Tabulation

def minimum_path_sum(triangle, n):
    # Create a 2D array dp to store minimum path sums
    dp = [[0 for j in range(n)] for i in range(n)]
    
    # Initialize the bottom row of dp with the values from the last row of the triangle
    for j in range(n):
        dp[n - 1][j] = triangle[n - 1][j]
    
    # Start from the second-to-last row and work upwards
    for i in range(n - 2, -1, -1):
        for j in range(i, -1, -1):
            # Calculate the minimum path sum for the current cell by considering two possible moves: down and diagonal
            down = triangle[i][j] + dp[i + 1][j]
            diagonal = triangle[i][j] + dp[i + 1][j + 1]
            
            # Store the minimum of the two possible moves in dp
            dp[i][j] = min(down, diagonal)
    
    # The minimum path sum will be stored in dp[0][0] after the loops
    return dp[0][0]

def main():
    # Define the input triangle and its size
    triangle = [[1], [2, 3], [3, 6, 7], [8, 9, 6, 10]]
    n = len(triangle)
    
    # Call the minimum_path_sum function and print the result
    print(minimum_path_sum(triangle, n))

if __name__ == '__main__':
    main()



// Space Optimization

def minimumPathSum(triangle, n):
    # Initialize two lists: front and cur to represent the current and previous rows in dp
    front = [0] * n  # This represents the previous row
    cur = [0] * n    # This represents the current row
    
    # Initialize the bottom row of dp (front) with the values from the last row of the triangle
    for j in range(n):
        front[j] = triangle[n - 1][j]
    
    # Start from the second-to-last row and work upwards
    for i in range(n - 2, -1, -1):
        for j in range(i, -1, -1):
            # Calculate the minimum path sum for the current cell by considering two possible moves: down and diagonal
            down = triangle[i][j] + front[j]
            diagonal = triangle[i][j] + front[j + 1]
            
            # Store the minimum of the two possible moves in the current row (cur)
            cur[j] = min(down, diagonal)
        
        # Update the previous row (front) with the current row (cur) for the next iteration
        front = cur
        
    # The minimum path sum will be stored in the first element of the front list after the loops
    return front[0]

def main():
    # Define the input triangle and its size
    triangle = [[1], [2, 3], [3, 6, 7], [8, 9, 6, 10]]
    n = len(triangle)
    
    # Call the minimumPathSum function and print the result
    print(minimumPathSum(triangle, n))

if __name__ == '__main__':
    main()


