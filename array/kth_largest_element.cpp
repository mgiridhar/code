class Solution {
public:
    // solution based on quick sort - median of three approach
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    int quickSortSelect(vector<int>& nums, int l, int h, int k) {
        if(l == h)
            return nums[k-1];
        else if(l == h-1) {
            if(nums[l] > nums[h])
                swap(nums, l, h);
            return nums[k-1];
        }
        //median of three - to find pivot
        int m = l + ((h-l)/2);
        if(nums[l] > nums[m])
            swap(nums, l, m);
        if(nums[m] > nums[h])
            swap(nums, m, h);
        if(nums[l] > nums[h])
            swap(nums, l, h);
        //place pivot rightmost end
        swap(nums, m, h);
        int pivot = h, i=l, j = h-1;
        while(i<j) {
            while(i<h && nums[i]<=nums[pivot])
                i++;
            while(j>l && nums[j]>nums[pivot])
                j--;
            if(i<j)
                swap(nums, i, j);
        }
        swap(nums, i, pivot);
        
        if(i == k-1)
            return nums[k-1];
        else if(k-1 > i)
            return quickSortSelect(nums, i+1, h, k);
        else
            return quickSortSelect(nums, l, i-1, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty() || k<1 || k>nums.size())
            return INT_MAX;
        //finding n-k+1 minimum == kth maximum element
        return quickSortSelect(nums, 0, nums.size()-1, nums.size() - k + 1);
    }
};