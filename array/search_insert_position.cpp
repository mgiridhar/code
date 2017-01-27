class Solution {
public:
    int searchInsert(vector<int>& nums, int i, int j, int t)
    {
        if(i>j)
            return -1;
        else if(i == j)
        {
            if(nums[i] >= t)
                return i;
            else if(nums[i] < t)
                return i+1;
        }
        int mid = i + ((j-i)/2);
        if(nums[mid] == t)
            return mid;
        else if(nums[mid] < t)
            return searchInsert(nums, mid+1, j, t);
        else if(nums[mid] > t)
            return searchInsert(nums, i, mid, t);
    }
    int searchInsert(vector<int>& nums, int target) {
        return searchInsert(nums, 0, nums.size()-1, target);
    }
};