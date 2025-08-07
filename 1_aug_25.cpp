/*118. Pascal's Triangle
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]] */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int m=numRows;
       vector< vector<int> > v;
       //generate
       for(int i=0;i<m;i++)
       {
        vector<int> a(i+1);
        v.push_back(a);
        for(int j=0;j<=i;j++)
        {
            if(j==0||j==i)
            {
                v[i][j]=1;
            }
            else
            v[i][j]=v[i-1][j]+v[i-1][j-1];
        }
       }
       return v;
    }
};
