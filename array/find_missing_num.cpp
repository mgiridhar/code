/**
 * Given a contiguous sequence of numbers in which each number repeats thrice, there is exactly one missing number. Find the missing number.
 * eg: 11122333 : Missing number 2
 *     11122233344455666 Missing number 5
 */

#include<iostream>
using namespace std;

int find_missing_num(string s) {
	int low = 0, high = s.length() - 1, mid;
	while(low < high) {
		mid = low + (high - low) / 2;
		if( (mid / 3) + 1 == (s[mid] - '0') )
			low = mid + 1;
		else
			high = mid;
	}
	return (low / 3) + 1;
}

int main() {
	string s;
	cin >> s;
	cout << find_missing_num(s) << endl;
	return 0;
}
