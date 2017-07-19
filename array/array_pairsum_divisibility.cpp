#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool checkPairsSumK(vector<int> arr, int k) {
    if(arr.size() == 0)
        return false;
    for(int i=0; i<arr.size(); i++) {
        arr[i] %= k;
    }
    unordered_map<int, int> hash;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] == 0) {
            if(hash[arr[i]] > 0)
                hash[arr[i]]--;
            else
                hash[arr[i]]++;
            continue;
        }
        hash[arr[i]]++;
        if(hash.find(k - arr[i]) != hash.end() && hash[k - arr[i]] > 0) {
            hash[arr[i]]--;
            hash[k-arr[i]]--;
        }
    }
    for(unordered_map<int, int>::iterator it=hash.begin(); it!=hash.end(); it++) {
        if(it->second > 0)
            return false;
    }
    return true;
}

int main() {
	//code
	int t, n, k;
	cin >> t;
	while(t--) {
	    cin >> n;
	    vector<int> arr(n);
	    for(int i=0; i<n; i++)
	        cin >> arr[i];
	    cin >> k;
	    cout << (checkPairsSumK(arr, k) ? "True" : "False") << endl;
	}
	return 0;
}