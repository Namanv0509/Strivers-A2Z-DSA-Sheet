/*
QUESTION:-
Geek is going for n days training program, he can perform any one of these three activities Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Help Geek to maximize his merit points as we were given a 2D array of n*3 points corresponding to each day and activity.

Example:
Input:
n = 3
points = [[1,2,5],[3,1,1],[3,3,3]]
Output:
11
Explanation:
Geek will learn a new move and earn 5 points on the first day,
then on the second day, he will do running and earn 3 points,
and on the third day, he will do fighting and earn 3 points.
So, the maximum points is 11.

Approach:
1. To maximize the merit points, we need to find the maximum sum of points such that the Geek can't perform the same activity on two consecutive days.
2. We can solve this problem using dynamic programming with memoization (top-down approach).
3. We define a helper function fmemo(n, prev, points, memo) that calculates the maximum points the Geek can earn from the nth day onwards, given that on the (n-1)th day, he performed the activity indexed by 'prev'.
4. The function checks if the maximum points for the (n-1)th day and 'prev' activity is already calculated and stored in the memo array. If yes, it returns the value from memo.
5. Otherwise, it calculates the maximum points for the nth day by considering all three activities except the one performed on the (n-1)th day. It then adds the points for the nth day and recursively calls the function for the (n-1)th day with the new activity and updates the maximum points.
6. The base case is when n is less than 0, in which case the function returns 0 as there are no days to earn points.
7. In the main function maximumPoints(points, n), we create a dp (memo) array of size n initialized with -1 and call the fmemo function for the nth day with the initial activity as -1 (since no activity is performed on the first day).
8. Finally, we return the maximum points obtained for all three possible starting activities (running, fighting, learning practice) as the result.

Complexity Analysis:
- The time complexity of the fmemo function is O(n) because we are calculating the maximum points for each day only once and storing it in the memo array.
- The space complexity is also O(n) to store the memo array.

*/

// Memotization
def f(day, last, points, dp):
    # Check if the result for this day and last
activity is already computed.
    if dp[day][last] != -1:
        return dp[day][last]

    # Base case: When we reach day 0, return the maximum point for the last day.
    if day == 0:
        maxi = 0
        for i in range(3):
            if i != last:
                maxi = max(maxi, points[0][i])
        dp[day][last] = maxi
        return dp[day][last]

    maxi = 0
    # Iterate through all activities for the current day.
    for i in range(3):
        if i != last:
            # Calculate the total points for the current day's activity and recursively call for the previous day.
            activity = points[day][i] + f(day - 1, i, points, dp)
            maxi = max(maxi, activity)

    # Store the maximum points in the DP table and return it.
    dp[day][last] = maxi
    return dp[day][last]

def ninjaTraining(n, points):
    # Initialize a DP table to store the computed results.
    dp = [[-1 for j in range(4)] for i in range(n)]
    # Start the recursive function from the last day with no previous activity.
    return f(n - 1, 3, points, dp)

def main():
    # Define the points matrix for each day.
    points = [[10, 40, 70],
              [20, 50, 80],
              [30, 60, 90]]

    n = len(points)  # Get the number of days.
    # Call the ninjaTraining function to find the maximum points.
    print(ninjaTraining(n, points))

if __name__ == '__main__':
    main()

// Tabulation

def ninjaTraining(n, points):
    # Initialize a DP table with dimensions (n x 4) to store the maximum points.
    dp = [[0 for j in range(4)] for i in range(n)]

    # Initialize the DP table for day 0 with base cases.
    dp[0][0] = max(points[0][1], points[0][2])
    dp[0][1] = max(points[0][0], points[0][2])
    dp[0][2] = max(points[0][0], points[0][1])
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]))

    # Loop through the days starting from the second day.
    for day in range(1, n):
        for last in range(4):
            dp[day][last] = 0  # Initialize the maximum points for the current day and last activity.
            for task in range(3):
                if task != last:
                    # Calculate the total points for the current day's activity and the previous day's maximum points.
                    activity = points[day][task] + dp[day - 1][task]
                    dp[day][last] = max(dp[day][last], activity)

    # Return the maximum points achievable after the last day with any activity.
    return dp[n - 1][3]

def main():
    # Define the points matrix for each day.
    points = [[10, 40, 70],
              [20, 50, 80],
              [30, 60, 90]]
    n = len(points)  # Get the number of days.
    # Call the ninjaTraining function to find the maximum points.
    print(ninjaTraining(n, points))

if __name__ == '__main__':
    main()

// Space Optimization

def ninjaTraining(n, points):
    # Initialize a list 'prev' to store the maximum points for each possible last activity on the previous day.
    prev = [0] * 4

    # Initialize 'prev' with the maximum points for the first day's activities.
    prev[0] = max(points[0][1], points[0][2])
    prev[1] = max(points[0][0], points[0][2])
    prev[2] = max(points[0][0], points[0][1])
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]))

    # Loop through the days starting from the second day.
    for day in range(1, n):
        # Initialize a temporary list 'temp' to store the maximum points for each possible last activity on the current day.
        temp = [0] * 4

        for last in range(4):
            # Initialize 'temp' for the current last activity.
            temp[last] = 0

            for task in range(3):
                if task != last:
                    # Calculate the total points for the current day's activity and the previous day's maximum points.
                    activity = points[day][task] + prev[task]
                    # Update 'temp' with the maximum points for the current last activity.
                    temp[last] = max(temp[last], activity)

        # Update 'prev' with 'temp' for the next iteration.
        prev = temp

    # Return the maximum points achievable after the last day with any activity.
    return prev[3]

def main():
    # Define the points matrix for each day.
    points = [[10, 40, 70],
              [20, 50, 80],
              [30, 60, 90]]
    n = len(points)  # Get the number of days.
    # Call the ninjaTraining function to find and print the maximum points.
    print(ninjaTraining(n, points))

if __name__ == '__main__':
    main()

