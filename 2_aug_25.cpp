/*2561. Rearranging Fruits
You have two fruit baskets containing n fruits each. You are given two 0-indexed integer arrays basket1 and basket2 representing the cost of fruit in each basket. You want to make both baskets equal. To do so, you can use the following operation as many times as you want:
Choose two indices i and j, and swap the ith fruit of basket1 with the jth fruit of basket2.
The cost of the swap is min(basket1[i], basket2[j]).
Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.

Return the minimum cost to make both the baskets equal or -1 if impossible.
Example 1:
Input: basket1 = [4,2,2,2], basket2 = [1,4,1,2]
Output: 1
Explanation: Swap index 1 of basket1 with index 0 of basket2, which has cost 1. Now basket1 = [4,1,2,2] and basket2 = [2,4,1,2]. Rearranging both the arrays makes them equal.
Example 2:

Input: basket1 = [2,3,4,1], basket2 = [3,2,5,1]
Output: -1
Explanation: It can be shown that it is impossible to make both the baskets equal. */
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>mp;
        int minEl = INT_MAX;
        for(auto ele:basket1){
            mp[ele]++;
            minEl = min(minEl, ele);
        }
        for(auto ele:basket2){
            mp[ele]--;
             minEl = min(minEl, ele);
        }
        vector<int> pos;
        vector<int> neg;
        for(auto p:mp){
            if(p.second%2!=0) return -1;
            else{
                if(p.second>0) 
                {int count=p.second/2;
                while(count--){
                    pos.push_back(p.first);
                }
                }
                else {
                    int count=abs(p.second/2);
                    while(count--){
                        neg.push_back(p.first);
                    }
                }
            }
        }
        sort(pos.begin(),pos.end());
        sort(rbegin(neg),rend(neg));
        long long answer=0;
        for(int i=0;i<pos.size();i++){
            answer += min(min(pos[i],neg[i]), minEl*2);
        }
        return answer;
    }
};
