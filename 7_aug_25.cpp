/*3363. Find the Maximum Number of Fruits Collected
There is a game dungeon comprised of n x n rooms arranged in a grid.
You are given a 2D array fruits of size n x n, where fruits[i][j] represents the number of fruits in the room (i, j). Three children will play in the game dungeon, with initial positions at the corner rooms (0, 0), (0, n - 1), and (n - 1, 0).
The children will make exactly n - 1 moves according to the following rules to reach the room (n - 1, n - 1):

The child starting from (0, 0) must move from their current room (i, j) to one of the rooms (i + 1, j + 1), (i + 1, j), and (i, j + 1) if the target room exists.
The child starting from (0, n - 1) must move from their current room (i, j) to one of the rooms (i + 1, j - 1), (i + 1, j), and (i + 1, j + 1) if the target room exists.
The child starting from (n - 1, 0) must move from their current room (i, j) to one of the rooms (i - 1, j + 1), (i, j + 1), and (i + 1, j + 1) if the target room exists.
When a child enters a room, they will collect all the fruits there. If two or more children enter the same room, only one child will collect the fruits, and the room will be emptied after they leave.

Return the maximum number of fruits the children can collect from the dungeon.
Example 1:
Input: fruits = [[1,2,3,4],[5,6,8,7],[9,10,11,12],[13,14,15,16]]
Output: 100*/
class Solution {
public:
    int n;
    int solve_first(vector<vector<int>>& fruits,vector<vector<int>>& dp) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += fruits[i][i];
            fruits[i][i] = 0;
            dp[i][i] = 0;
        }
        return ans;
    }
    int solve_second(int i,int j,vector<vector<int>>& fruits,vector<vector<int>>& dp){   
        if(i>n-1 || j>n-1 || i<0 || j<0){
            return 0;
        }
        if(i==n-1 && j==n-1){
            return 0;
        }
        if (i == j || i > j) {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int leftcorner = fruits[i][j] + solve_second(i + 1, j - 1, fruits,dp);
        int middle = fruits[i][j] + solve_second(i + 1, j, fruits,dp);
        int rightcorner = fruits[i][j] + solve_second(i + 1, j + 1, fruits,dp);

        return dp[i][j] = max({middle, rightcorner, leftcorner});
    }
    int solve_third(int i,int j,vector<vector<int>>& fruits,vector<vector<int>>& dp){   
        if(i>n-1 || j>n-1 || i<0 || j<0){
            return 0;
        }
        if(i==n-1 && j==n-1){
            return 0;
        }
        if (i == j || i < j) {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int topcorner   = fruits[i][j] + solve_third(i - 1, j + 1, fruits,dp);
        int right       = fruits[i][j] + solve_third(i, j + 1, fruits,dp);
        int rightcorner = fruits[i][j] + solve_third(i + 1, j + 1, fruits,dp);

        return dp[i][j] = max({topcorner, right,rightcorner});
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n=fruits.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int first_child=solve_first(fruits,dp);
        int second_child=solve_second(0,n-1,fruits,dp);
        int third_child=solve_third(n-1,0,fruits,dp);
        return first_child+second_child+third_child;
    }
};
