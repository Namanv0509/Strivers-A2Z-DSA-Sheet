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

# Function to calculate the maximum points
def sub(points, last, index, dp):
    # Return if all work is done
    if index == len(points):
        return 0

    # If state has been explored previously, return the answer
    if dp[index][last] != -1:
        return dp[index][last]

    # Store the optimal answer for the current index and last activity
    ans = 0

    # If this is the first activity
    if last == 0:
        ans = max(
            ans,
            max(
                points[index][0] + sub(points, 1, index + 1, dp),
                points[index][1] + sub(points, 2, index + 1, dp),
                points[index][2] + sub(points, 3, index + 1, dp),
            ),
        )

    # If the first activity was selected last time
    elif last == 1:
        ans = max(
            ans,
            max(
                points[index][1] + sub(points, 2, index + 1, dp),
                points[index][2] + sub(points, 3, index + 1, dp),
            ),
        )

    # If the second activity was selected last time
    elif last == 2:
        ans = max(
            ans,
            max(
                points[index][0] + sub(points, 1, index + 1, dp),
                points[index][2] + sub(points, 3, index + 1, dp),
            ),
        )

    # If the third activity was selected last time
    else:
        ans = max(
            ans,
            max(
                points[index][1] + sub(points, 2, index + 1, dp),
                points[index][0] + sub(points, 1, index + 1, dp),
            ),
        )

    # Save the maximum possible points for this index with this last activity
    dp[index][last] = ans
    return ans


# Driver code
if __name__ == "__main__":
    n = 3
    points = [[1, 2, 5], [3, 1, 1], [3, 3, 3]]

    # Initialize all states of dp with -1
    dp = [[-1 for _ in range(4)] for _ in range(len(points))]

    # Function Call
    print("Maximum Points We Can Make:", sub(points, 0, 0, dp))
