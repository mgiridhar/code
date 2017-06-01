/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/
/*** Iterative binary search - O(log n) solution ***/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1) return 0;
        if(nums.size() == 2) {
            if(nums[0] > nums[1])
                return 0;
            else if(nums[1] > nums[0])
                return 1;
            else
                return -1;
        }
        
        int low = 0, high = nums.size()-1, mid;
        
        while(low < high) {
            
            if( (low == 0 || nums[low-1] < nums[low]) && nums[low] > nums[low+1])
                return low;
            if( (high == nums.size()-1 || nums[high] > nums[high+1]) && nums[high-1] < nums[high])
                return high;

            mid = low + (high - low)/2;
            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])
                return mid;
            if((mid - low && abs(nums[low] - nums[mid])) && ((nums[low] < nums[low+1] && nums[mid-1] < nums[mid]) || (nums[low] > nums[low+1] && nums[mid-1] > nums[mid])))
                low = mid+1;
            else
                high = mid-1;
        }
        
        return -1;
    }
};