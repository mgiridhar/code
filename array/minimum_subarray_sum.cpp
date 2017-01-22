class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return (nums[0] >= s) ? 1 : 0;
        int start = 0, end = INT_MAX, i=0, j=1, curr = nums[0];
        while(j <= nums.size())
        {
            if(curr >= s)
            {
                if((end-start) > (j-i)) {
                    start = i;
                    end = j;
                }
                curr -= nums[i];
                i++;
            }
            else
            {
                if(j<nums.size())
                    curr += nums[j];
                j++;
            }
            if(j<=i)
                j = i+1;
        }
        return (end != INT_MAX) ? (end-start) : 0;
    }
};