/*
Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in range [1, n] inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.

Example 1:
nums = [1, 3], n = 6
Return 1.

Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.

Example 2:
nums = [1, 5, 10], n = 20
Return 2.
The two patches can be [2, 4].

Example 3:
nums = [1, 2, 2], n = 5
Return 0.

Example 4:
nums = [], n = 5
Return 3

Example 5:
nums = [1,2,31,33], n = 2147483647
Return 28
*/

/***
let nums=[1 2 5 6 20], n = 50.
Initial value: with 0 nums, we can only get 0 maximumly.
Then we need to get 1, since nums[0]=1, then we can get 1 using [1]. now the maximum number we can get is 1. (actually, we can get all number no greater than the maximum number)
number used [1], number added []
can achieve 1~1

Then we need to get 2 (maximum number +1). Since nums[1]=2, we can get 2. Now we can get all number between 1 ~ 3 (3=previous maximum value + the new number 2). and 3 is current maximum number we can get.
number used [1 2], number added []
can achieve 1~3

Then we need to get 4 (3+1). Since nums[2]=5>4; we need to add a new number to get 4. The optimal solution is to add 4 directly. In this case, we could achieve maximumly 7, using [1,2,4].
number used [1 2], number added [4]
can achieve 1~7

Then we need to get 8 (7+1). Since nums[2]=5<8, we can first try to use 5. Now the maximum number we can get is 7+5=12. Since 12>8, we successfully get 8.
number used [1 2 5], number added [4]
can achieve 1~12

Then we need to get 13 (12+1), Since nums[3]=6<13, we can first try to use 6. Now the maximum number we can get is 12+6=18. Since 18>13, we successfully get 13.
number used [1 2 5 6], number added [4]
can achieve 1~18

Then we need to get 19 (18+1), Since nums[4]=20>19, we need to add a new number to get 19. The optimal solution is to add 19 directly. In this case, we could achieve maximumly 37.
number used [1 2 5 6], number added [4 19]
can achieve 1~37

Then we need to get 38(37+1), Since nums[4]=20<38, we can first try to use 20. Now the maximum number we can get is 37+20=57. Since 57>38, we successfully get 38.
number used [1 2 5 6 20], number added [4 19]
can achieve 1~57

Since 57>n=50, we can all number no greater than 50.
The extra number we added are 4 and 19, so we return 2.
***/

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0;
        long int i=1, j=0, curr_max = 0;
        while(i <= n) {
            if(j < nums.size() && nums[j] <= i) {
                curr_max += nums[j];
                j++;
            }
            else {
                patches++;
                curr_max += i;
            }
            i = curr_max + 1;
        }
        return patches;
    }
    
    /*** BRUTE FORCE Timed out ***/
    /*
    int minPatches(vector<int>& nums, int n) {
    vector<int> sums(nums.size());
        for(int i=0; i<nums.size(); i++) {
            sums[i] = nums[i] + ((i>0)?sums[i-1]:0);
        }
        unordered_set<int> sumSet;
        for(int i=0; i<nums.size(); i++) {
            sumSet.insert(nums[i]);
            for(int j=i+1; j<nums.size(); j++) {
                for(int k=j; k<nums.size(); k++) {
                    int temp = nums[i] + sums[k] - sums[j-1];
                    if(sumSet.find(temp) == sumSet.end())
                        sumSet.insert(temp);
                }
            }
        }
        
        int patches = 0;
        for(int i=1; i<=n; i++) {
            if(sumSet.find(i) == sumSet.end()) {
                patches++;
                //cout << "not found " << i <<endl;
                unordered_set<int> temp;
                for(unordered_set<int>::iterator it=sumSet.begin(); it!=sumSet.end(); it++) {
                    temp.insert(i + *it);
                }
                sumSet.insert(temp.begin(), temp.end());
                sumSet.insert(i);
            }
        }
        return patches;
    }*/
};

    