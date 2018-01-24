/*
In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.

Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

Example:
Input: [1,2,1,2,6,7,5,1], 2
Output: [0, 3, 5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
Note:
nums.length will be between 1 and 20000.
nums[i] will be between 1 and 65535.
k will be between 1 and floor(nums.length / 3).
*/

/*
DP solution:
Time Complexity - O(n)
Space Complexity - O(n)
*/

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> sum(nums.size() + 1);
        sum[0] = 0;
        for(int i=0; i<nums.size(); i++)
            sum[i+1] = sum[i] + nums[i];
        
        vector<int> sum1(nums.size(), 0), sum2(nums.size(), 0), sum3(nums.size(), 0);
        vector<vector<int>> result1(nums.size()), result2(nums.size()), result3(nums.size());
        
        for(int i=k-1; i < (nums.size() - (2 * k)); i++) {
            if(sum1[i-1] < sum[i+1] - sum[i-k+1]) {
                sum1[i] = sum[i+1] - sum[i-k+1];
                result1[i].push_back(i-k+1);
            }
            else {
                sum1[i] = sum1[i-1];
                result1[i] = result1[i-1];
            }
            //sum1[i] = max(sum1[i-1], sum[i+1] - sum[i-k+1]);
        }
        for(int i=(2*k)-1; i < (nums.size() - k); i++) {
            if(sum2[i-1] < sum1[i-k] + sum[i+1] - sum[i-k+1]) {
                sum2[i] = sum1[i-k] + sum[i+1] - sum[i-k+1];
                result2[i] = result1[i-k];
                result2[i].push_back(i-k+1);
            }
            else {
                sum2[i] = sum2[i-1];
                result2[i] = result2[i-1];
            }
            //sum2[i] = max(sum2[i-1], sum1[i-k] + sum[i+1] - sum[i-k+1]);
        }
        for(int i=(3*k)-1; i < nums.size(); i++) {
            if(sum3[i-1] < sum2[i-k] + sum[i+1] - sum[i-k+1]) {
                sum3[i] = sum2[i-k] + sum[i+1] - sum[i-k+1];
                result3[i] = result2[i-k];
                result3[i].push_back(i-k+1);
            }
            else {
                sum3[i] = sum3[i-1];
                result3[i] = result3[i-1];
            }
            //sum3[i] = max(sum3[i-1], sum2[i-k] + sum[i+1] - sum[i-k+1]);
        }
        
        return result3[nums.size()-1];
    }
};
