#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countSubArraysK(vector<int> arr, int k) {
    if(arr.size() == 0)
        return 0;
    unordered_map<int, int> hash;
    int count = 0, sum = 0;
    for(int i=0; i<arr.size(); i++) {
        sum = (sum + (abs(arr[i]) % k)) % k;
        if(sum == 0)
            count++;
        if(hash.find(sum) != hash.end()) {
            count += hash[sum];
            hash[sum]++;
        }
        else {
            hash[sum] = 1;
        }
        //cout << sum << " " << hash[sum] << " " << count << endl;
    }
    return count;
}

int main() {
	//code
	int t, n, k;
	cin >> t;
	while(t--) {
	    cin >> n >> k;
	    vector<int> arr(n);
	    for(int i=0; i<n; i++) {
	        cin >> arr[i];
	    }
	    cout << countSubArraysK(arr, k) << endl;
	}
	return 0;
}