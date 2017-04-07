#include<iostream>
#include<vector>
using namespace std;

/*** Recursive implementation - O(n^n) ***/
void genAbbRec(string s, string abb, vector<string> &v, int i, bool flag) {
	if(i >= s.length()) {
		cout << abb << endl;
		v.push_back(abb);
		return;
	}
	genAbbRec(s, abb + s[i], v, i+1, true);
	if(flag) {
		for(int j = i; j<s.length(); j++) {
			genAbbRec(s, abb + to_string(j - i + 1), v, j+1, false);
		}
	}
}

int main() {
	string s;
	cin >> s;
	vector<string> v;
	genAbbRec(s, "", v, 0, true);
	return 0;
}
