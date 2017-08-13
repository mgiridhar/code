#include<iostream>
#include<string>
#include<cctype>
using namespace std;

bool encodeString(string &s, int i, string curr_enc, string &ans, bool isEncoded) {
	if(i == s.length()) {
		if(curr_enc.length() <= s.length()) {
			ans = curr_enc;
			return true;
		}
		return false;
	}
	int j=i+1;
	while(j < s.length() && s[i] == s[j]) 
		j++;
	if(!(isdigit(s[i]) && !isEncoded && i > 0 && isdigit(s[i-1]))) {
		if(encodeString(s, j, curr_enc + s[i] + "x" + to_string(j - i), ans, true))
			return true;
	}
	return encodeString(s, j, curr_enc + s.substr(i, j-i), ans, false);
}

int main() {
	int t;
	string s;
	cin >> t;
	while(t--) {
		cin >> s;
		string encodedStr = "";
		encodeString(s, 0, "", encodedStr, true);
		cout << encodedStr << endl;
	}
	return 0;
}
