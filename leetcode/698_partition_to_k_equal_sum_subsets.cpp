/*
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

Note:
1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.
*/
class Solution {
public:
    static bool mycomp(int a, int b) {
        return a > b;
    }
    bool canPartitionUtil(vector<int>& nums, int k, int ind, int j, int curr_sum, int part_sum) {
        if(j == k) return true;
        if(curr_sum == 0)
            return canPartitionUtil(nums, k, 0, j+1, part_sum, part_sum);
        int t;
        for(int i=ind; i < nums.size(); i++) {
            if(nums[i] < 0 || nums[i] > curr_sum)
                continue;
            t = nums[i];
            nums[i] = -1;
            if(canPartitionUtil(nums, k, i + 1, j, curr_sum - t, part_sum))
                return true;
            nums[i] = t;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0)
            return false;
        sort(nums.begin(), nums.end(), mycomp);
        return canPartitionUtil(nums, k, 0, 0, sum / k, sum / k);
    }
};
