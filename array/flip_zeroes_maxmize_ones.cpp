// http://www.geeksforgeeks.org/find-zeroes-to-be-flipped-so-that-number-of-consecutive-1s-is-maximized/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//time - O(n)

//without O(n) space
int maxOnes(vector<int> arr, int m) {
    int n = arr.size(), l = 0, r = 0, curr_m = 0, max_len = 0;
    if(n == 0) return 0;
    for(; r<n; r++) {
        if(arr[r] == 0) curr_m++;
        if(curr_m > m) {
            while(l<r && arr[l] == 1) l++;
            l++;
            curr_m--;
        }
        max_len = max(max_len, r - l + 1);
    }
    return max_len;
}

//with O(n) space
int maxOnes_1(vector<int> arr, int m) {
    int n = arr.size();
    if(n == 0) return 0;
    vector<int> left(n), right(n);
    for(int i=0; i<n; i++) {
        if(i > 0 && arr[i-1] == 1)
            left[i] = left[i-1];
        else
            left[i] = i;
    }
    for(int i=n-1; i>=0; i--) {
        if(i < n-1 && arr[i+1] == 1)
            right[i] = right[i+1];
        else
            right[i] = i;
    }
    /*for(int i=0; i<n; i++) {
        cout << left[i] << " ";
    }
    cout << endl;
    for(int i=0; i<n; i++) {
        cout << right[i] << " ";
    }*/
    cout << endl;
    queue<int> q;
    int max_ones = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == 0) q.push(i);
        if(q.size() > m) q.pop();
        int l = q.empty() ? i : left[q.front()];
        int r = q.empty() ? i : right[q.back()];
        max_ones = max(max_ones, r - l + 1);
        //cout << max_ones << " " << r - l + 1 <<  endl;
    }
    //cout << endl;
    return max_ones;
}

int main() {
	//code
	int t, n, m;
	cin >> t;
	while(t--) {
	    cin >> n;
	    vector<int> arr(n);
	    for(int i=0; i<n; i++) cin >> arr[i];
	    cin >> m;
	    cout << maxOnes(arr, m) << endl;
	}
	return 0;
}
