#include<iostream>
#include<vector>
using namespace std;

//SPOJ - inversion count INVCNT
// divide and conquer - O(log n)
unsigned long long int countInversions(vector<long long int> &v, unsigned long long int low, unsigned long long int high) {
	if(low >= high) return 0;
	unsigned long long int mid = low + (high - low)/2;
	unsigned long long int leftCnt = countInversions(v, low, mid);
	unsigned long long int rightCnt = countInversions(v, mid+1, high);
	unsigned long long int invCnt = 0;
	vector<long long int> temp;
	unsigned long long int i = low, j = mid + 1;
	while(i <= mid && j <= high) {
		if(v[i] <= v[j]) {
			temp.push_back(v[i]);
			i++;
		}
		else {
			invCnt += (mid - i + 1);
			temp.push_back(v[j]);
			j++;
		}
	}
	while(i <= mid) {
		temp.push_back(v[i]);
		i++;
	}
	while(j <= high) {
		temp.push_back(v[j]);
		j++;
	}

	for(i=low, j=0; j<temp.size(); i++,j++) {
		v[i] = temp[j];
	}

	return leftCnt + rightCnt + invCnt;
}

int main() {
	unsigned long long int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<long long int> v(n);
		for(unsigned long long int i=0; i<n; i++)
			cin >> v[i];
		cout << countInversions(v, 0, n-1) << endl;
	}
}
