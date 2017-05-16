/*
 * Find <first> subarray with given sum k
 * handles both non-negative and negative numbers
 * solution uses map
 * time - O(n), space - O(n)
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	//code
	int t, n, s;
	cin >> t;
	while(t--) {
	    cin >> n >> s;
	    vector<int> v(n);
	    int sum = 0;
	    unordered_map<int, int> hash;
	    bool flag = false;
	    int start, end;
	    for(int i=0; i<n; i++) {
	        cin >> v[i];
	        sum += v[i];
	        if(!flag) {
    	        if(sum == s) {
    	            start = 1;
    	            end = i + 1;
    	            flag = true;
    	        }
    	        else if(hash.find(sum-s) != hash.end()) {
    	            start = hash[sum-s] + 2;
    	            end = i + 1;
    	            flag = true;
    	        }
    	        hash[sum] = i;
	        }
	    }
	    if(flag)
	        cout << start << " " << end << endl;
	    else
	        cout << "-1" << endl;
	}
	return 0;
}

/*
 * handle only non-negative numbers
 * solution without map: use two pointers, increase size of window if curr_sum < sum, decrease size of window if curr_sum > sum, break if curr_sum == sum
 * O(n) time and O(1) space
 */

