class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long int sum = 0;
        for(int i=0; i < nums.size(); i++)
            sum += nums[i];
        if(sum&1)
            return false;
        
        long int expectedSum = sum / 2;
        bool dp[nums.size()][expectedSum + 1];
        for(int i=0; i<nums.size(); i++)
            dp[i][0] = true;
        for(int j=1; j<=expectedSum; j++)
            if(j == nums[0])
                dp[0][j] = true;
            else
                dp[0][j] = false;
        
        for(int i=1; i<nums.size(); i++)
        {
            for(int j=1; j<=expectedSum; j++)
            {
                if(j<nums[i])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
            }
        }
        return dp[nums.size()-1][expectedSum];
    }
};