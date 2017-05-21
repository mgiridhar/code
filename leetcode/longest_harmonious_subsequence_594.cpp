/*
We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Note: The length of the input array will not exceed 20,000.
*/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        unordered_map<int, int> hash;
        for(int i=0; i<nums.size(); i++) {
            if(hash.find(nums[i]) == hash.end()) {
                hash[nums[i]] = 1;
            }
            else {
                hash[nums[i]]++;
            }
        }
        int max_seq = 0;
        for(unordered_map<int, int>::iterator it=hash.begin(); it != hash.end(); it++) {
            if(hash.find(it->first - 1) != hash.end()) {
                max_seq = max(max_seq, it->second + hash[it->first - 1]);
            }
            if(hash.find(it->first + 1) != hash.end()) {
                max_seq = max(max_seq, it->second + hash[it->first + 1]);
            }
        }
        return max_seq;
    }
};
