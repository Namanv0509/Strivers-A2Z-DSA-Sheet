/*
QUESTION:-
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

Example:
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Approach:
1. We can solve this problem using dynamic programming with memoization (top-down approach).
2. We define a helper function fmemo(i, j, grid, dp) that calculates the number of unique paths from the top-left corner (0, 0) to the cell (i, j) on the grid.
3. The function checks if the number of unique paths for the cell (i, j) is already calculated and stored in the dp array. If yes, it returns the value from dp.
4. If the cell (i, j) contains an obstacle (i.e., grid[i][j] == 1), then there is no possible path through that cell, so the function returns 0.
5. Otherwise, it calculates the number of unique paths for the cell (i, j) by adding the number of unique paths from the cell above (i-1, j) and the cell to the left (i, j-1).
6. The base case is when i or j is less than 0, in which case the function returns 0 as there are no paths to reach those cells.
7. In the main function uniquePathsWithObstacles(obstacleGrid), we create a dp array of size m x n initialized with -1 and call the fmemo function for the bottom-right cell (m-1, n-1).
8. Finally, we return the number of unique paths obtained for the bottom-right cell as the result.

Complexity Analysis:
- The time complexity of the fmemo function is O(m x n) because we are calculating the number of unique paths for each cell only once and storing it in the dp array.
- The space complexity is also O(m x n) to store the dp array.

Note: The given test cases are generated such that the answer will be less than or equal to 2 x 10^9.

Solution : https://takeuforward.org/data-structure/grid-unique-paths-2-dp-9/
*/

// Memoization

def mazeObstaclesUtil(i, j, maze, dp):
    # Base case: If we are out of bounds or at an obstacle, return 0.
    if i < 0 or j < 0 or maze[i][j] == -1:
        return 0

    # Base case: If we reach the starting point, return 1 (we found a path).
    if i == 0 and j == 0:
        return 1

    # If we've already computed the number of paths for this position, return it.
    if dp[i][j] != -1:
        return dp[i][j]

    # Move up and left in the maze, and recursively calculate the number of paths.
    up = mazeObstaclesUtil(i - 1, j, maze, dp)
    left = mazeObstaclesUtil(i, j - 1, maze, dp)

    # Store the result in the DP table and return it.
    dp[i][j] = up + left
    return dp[i][j]

def mazeObstacles(n, m, maze):
    # Create a DP table initialized with -1 values.
    dp = [[-1 for j in range(m)] for i in range(n)]
    
    # Call the utility function to find the number of paths.
    return mazeObstaclesUtil(n - 1, m - 1, maze, dp)

def main():
    # Example maze with 0s representing open paths and -1 representing obstacles.
    maze = [[0, 0, 0], [0, -1, 0], [0, 0, 0]]
    n = len(maze)
    m = len(maze[0])

    # Call the mazeObstacles function and print the result.
    print(mazeObstacles(n, m, maze))

if __name__ == '__main__':
    main()



// Tabulation

def mazeObstaclesUtil(n, m, maze, dp):
    # Loop through each cell in the maze
    for i in range(n):
        for j in range(m):
            # Base conditions:
            # If we encounter an obstacle or we are out of bounds, set dp[i][j] to 0.
            if i > 0 and j > 0 and maze[i][j] == -1:
                dp[i][j] = 0
                continue
            # If we are at the starting point, set dp[i][j] to 1.
            if i == 0 and j == 0:
                dp[i][j] = 1
                continue
            
            # Initialize variables to store the number of paths coming from up and left.
            up = 0
            left = 0
            
            # If we can move up (i > 0), update 'up' with the value from the cell above.
            if i > 0:
                up = dp[i - 1][j]
            
            # If we can move left (j > 0), update 'left' with the value from the cell to the left.
            if j > 0:
                left = dp[i][j - 1]
            
            # Calculate the total number of paths to reach this cell and store it in dp[i][j].
            dp[i][j] = up + left
    
    # The result is stored in the bottom-right corner of the DP table.
    return dp[n - 1][m - 1]

def mazeObstacles(n, m, maze):
    # Create a DP table initialized with -1 values.
    dp = [[-1 for j in range(m)] for i in range(n)]
    
    # Call the utility function to find the number of paths.
    return mazeObstaclesUtil(n, m, maze, dp)

def main():
    # Example maze with 0s representing open paths and -1 representing obstacles.
    maze = [[0, 0, 0],
            [0, -1, 0],
            [0, 0, 0]]
    n = len(maze)
    m = len(maze[0])
    
    # Call the mazeObstacles function and print the result.
    print(mazeObstacles(n, m, maze))

if __name__ == "__main__":
    main()



// Space Optimization

def mazeObstacles(n, m, maze):
    # Initialize the 'prev' list to keep track of the number of paths in the previous row.
    prev = [0] * m
    
    # Loop through each row of the maze.
    for i in range(n):
        # Initialize a temporary list to store the number of paths for the current row.
        temp = [0] * m
        
        # Loop through each cell in the current row.
        for j in range(m):
            # Base conditions:
            # If we encounter an obstacle or we are out of bounds, set 'temp[j]' to 0.
            if i > 0 and j > 0 and maze[i][j] == -1:
                temp[j] = 0
                continue
            # If we are at the starting point, set 'temp[j]' to 1.
            if i == 0 and j == 0:
                temp[j] = 1
                continue
            
            # Initialize variables to store the number of paths coming from up and left.
            up = 0
            left = 0
            
            # If we can move up (i > 0), update 'up' with the value from the previous row.
            if i > 0:
                up = prev[j]
            
            # If we can move left (j > 0), update 'left' with the value from the current row.
            if j > 0:
                left = temp[j - 1]
            
            # Calculate the total number of paths to reach this cell and store it in 'temp[j]'.
            temp[j] = up + left
        
        # Update 'prev' with the 'temp' list for the next iteration.
        prev = temp
    
    # The result is stored in the last element of the 'prev' list (bottom-right corner).
    return prev[m - 1]

def main():
    # Example maze with 0s representing open paths and -1 representing obstacles.
    maze = [[0, 0, 0],
            [0, -1, 0],
            [0, 0, 0]]
    n = len(maze)
    m = len(maze[0])
    
    # Call the mazeObstacles function and print the result.
    print(mazeObstacles(n, m, maze))

if __name__ == "__main__":
    main()

