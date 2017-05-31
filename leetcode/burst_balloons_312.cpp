/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/
class Solution {
public:
    int burstValue(vector<int> &nums, int i, int j, int k) {
        return ((i < 0) ? 1 : nums[i]) * nums[j] * ((k >= nums.size()) ? 1 : nums[k]);
    }
    pair<int, int> max(pair<int, int> a, pair<int, int> b) {
        return (b.first > a.first) ? b : a;
    }
    // dp - O(n^3)
    int findMaxCoins(vector<int> &nums) {
        if(nums.size() == 0)
            return 0;

        vector<vector<pair<int, int>>> dp(nums.size(), vector<pair<int, int>>(nums.size(), make_pair(0, -1)));
        for(int i=0; i<nums.size(); i++) {
            dp[i][i].first = burstValue(nums, i-1, i, i+1);
            dp[i][i].second = i;
        }
        
        for(int l = 2; l <= nums.size(); l++) {
            for(int i=0; i <= (nums.size() - l); i++) {
                for(int j=i; j < (i+l); j++) {
                    int temp = ( j == 0 ? 0 : dp[i][j-1].first ) + ( j == i+l-1 ? 0 : dp[j+1][i+l-1].first ) + burstValue(nums, i-1, j, i+l);
                    dp[i][i+l-1] = max(dp[i][i+l-1], make_pair(temp, j));
                }
            }
        }
        /*
        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<nums.size(); j++) {
                cout << dp[i][j].first << " ";
            }
            cout << endl;
        }
        */
        return dp[0][nums.size()-1].first;
    }

    // recursive - naive solution O(n^n)
    /*
    int recSol(list<int> l) {
        if(l.size() == 0) return 0;
        if(l.size() == 1) return l.front();
        int maxCoins = 0;
        for(list<int>::iterator it = l.begin(); it != l.end(); it++) {
            int sum = 0;
            if(it == l.begin()) { sum = (*it) * (*next(it)) ; }
            else if(it == prev(l.end())) { sum = (*prev(it)) * (*it); }
            else { sum = (*prev(it)) * (*it) * (*next(it)); }
            int val = *it;
            it = l.erase(it);
            sum += recSol(l);
            l.insert(it, val);
            it = prev(it);
            maxCoins = max(sum, maxCoins);
        }
        return maxCoins;
    }
    */
    
    int maxCoins(vector<int>& nums) {
        //return recSol(list<int>(nums.begin(), nums.end()));
        
        return findMaxCoins(nums);
    }
};