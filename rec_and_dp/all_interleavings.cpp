#include<iostream>
#include<vector>
using namespace std;

//if all characters in the two strings are different
void all_interleavings1(string &s1, string &s2, int i, int j, string curr, vector<string> &result) {
	if(i == s1.length() && j == s2.length()) {
		result.push_back(curr);
		return;
	}
	if(i < s1.length())
		all_interleavings1(s1, s2, i+1, j, curr + s1[i], result);
	if(j < s2.length())
		all_interleavings1(s1, s2, i, j+1, curr + s2[j], result);
}

//if the two strings can contain common characters
void all_interleavings2(string &s1, string &s2, int i, int j, string curr, vector<string> &result) {
	if(i == s1.length() && j == s2.length()) {
		result.push_back(curr);
		return;
	}
	if(i < s1.length())
		all_interleavings2(s1, s2, i+1, j, curr + s1[i], result);
	if(j < s2.length() && i < s1.length() && s1[i] == s2[j]) {
		if(j+1 < s2.length())
			all_interleavings2(s1, s2, i, j+2, curr + s2[j] + "" + s2[j+1], result);
	}
	else if(j < s2.length())
		all_interleavings2(s1, s2, i, j+1, curr + s2[j], result);
}

void print(vector<string> res) {
	for(auto s : res) {
		cout << s << " ";
	}
	cout << endl;
}

int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;
	vector<string> result;
	all_interleavings1(s1, s2, 0, 0, "", result);
	print(result);
	result.clear();
	all_interleavings2(s1, s2, 0, 0, "", result);
	print(result);
}
