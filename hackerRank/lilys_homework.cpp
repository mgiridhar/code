#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool ascend(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}

bool descend(pair<int,int> a, pair<int,int> b) {
    return a.first > b.first;
}

int minSwaps(vector<int> A) {

    vector<pair<int, int>> arr(A.size());
	for(int i=0; i<A.size(); i++) {
        arr[i].first = A[i];
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end(), ascend);

    int ascSwaps = 0;
	vector<bool> visited(A.size(), false);
	for(int i=0; i<arr.size(); i++) {
		if(visited[i] || arr[i].second == i)
			continue;

		int cycleNodes = 0, j=i;
		while(!visited[j]) {
			visited[j] = true;
			j = arr[j].second;
			cycleNodes++;
		}
		ascSwaps += (cycleNodes - 1);
	}
    
    sort(arr.begin(), arr.end(), descend);
    int descSwaps = 0;
    visited.assign(A.size(), false);
    for(int i=0; i<arr.size(); i++) {
        if(visited[i] || arr[i].second == i)
            continue;
        
        int cycleNodes = 0, j=i;
        while(!visited[j]) {
            visited[j] = true;
            j = arr[j].second;
            cycleNodes++;
        }
        descSwaps += (cycleNodes - 1);
    }
    
	return min(ascSwaps, descSwaps);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
	cin >> n;
	vector<int> A(n);
	for(int i=0; i<n; i++)
		cin >> A[i];
	cout << minSwaps(A) << endl;
    return 0;
}

