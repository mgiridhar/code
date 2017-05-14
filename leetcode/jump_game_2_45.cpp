/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        int curr_reach = 0, max_reach = 0, steps = 0;
        for(int i=0; i<nums.size() && i<=max_reach && curr_reach<(nums.size()-1); i++) {
            if(curr_reach < i) {
                steps++;
                curr_reach = max_reach;
            }
            max_reach = max(max_reach, i+nums[i]);
        }
        return steps;
    }
};
