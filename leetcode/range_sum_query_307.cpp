/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/

/*
    Segment tree solution
    update - O(log n)
    range query - O(log n)
    building time - O(n)
    space - O(n)
*/
    
class NumArray {
public:
    vector<long int> segTree;
    unsigned long int n;
    
    NumArray(vector<int> nums) {
        n = nums.size();
        if(nums.size() == 0)
            return;
        
        if( n & (n-1) ) {
            n = pow( 2, log2(n) + 1);
        }
        segTree.resize((n * 2) - 1);
        this->buildSegTree(nums, 0, nums.size()-1, 0);
        n = nums.size();
        
        for(int i=0; i<segTree.size(); i++) {
            cout << segTree[i] << " ";
        }
        cout << endl;
    }
    
    long int buildSegTree(vector<int> &nums, int i, int j, int si) {
        //cout << i << " " << j << " " << si << " " << segTree.size() << endl;
        if(nums.size() == 0 || i>j || si >= segTree.size()) return 0;
        if(i == j) {
            segTree[si] = nums[i];
            //cout << i << ' ' << si << " " << segTree[si] << endl;
            return segTree[si];
        }
        int mid = i + (j-i)/2;
        long int l = buildSegTree(nums, i, mid, (2*si) + 1);
        long int r = buildSegTree(nums, mid+1, j, (2*si) + 2);
        segTree[si] = l + r;
        //cout << l << " " << r << " " << si << " " << segTree[si] << endl;
        return segTree[si];
    }
    
    long int update(int i, int val,int low, int high, unsigned long int seg_i) {
        if(low > high || i>=n)
            return 0;
        if(i < low || i > high)
            return segTree[seg_i];
        if(low == high && low == i) {
            segTree[seg_i] = val;
            return segTree[seg_i];
        }
        int mid = low + (high - low)/2;
        long int l = update(i, val, low, mid, (2*seg_i) + 1);
        long int r = update(i, val, mid+1, high, (2*seg_i) + 2);
        segTree[seg_i] = l + r;
        return segTree[seg_i];
    }
    
    void update(int i, int val) {
        if(segTree.size() == 0)
            return;
        update(i, val, 0, n-1, 0);
    }
    
    long int sumRange(int i, int j, int low, int high, unsigned long int seg_i) {
        //cout << low << " " << high << endl;
        if(i > j || low > high || low > j || high < i)
            return 0;
        if(i <= low && high <= j)
            return segTree[seg_i];
        
        int mid = low + (high-low)/2;
        long int l = sumRange(i, j, low, mid, (2*seg_i) + 1);
        long int r = sumRange(i, j, mid+1, high, (2*seg_i) + 2);
        return l + r;
    }
    
    int sumRange(int i, int j) {
        if(segTree.size() == 0)
            return  0;
        return sumRange(i, j, 0, n-1, 0);
    }
    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */