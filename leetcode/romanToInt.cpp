#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
static map<char, int> roman;

void initializeRoman() {
	roman['I'] = 1;
	roman['V'] = 5;
	roman['X'] = 10;
	roman['L'] = 50;
	roman['C'] = 100;
	roman['D'] = 500;
	roman['M'] = 1000;
}

int valueOf(char x) {
	return (roman.find(x) != roman.end()) ? roman[x] : -1;
}

int rom2int(string s) {
	if(s.empty())
		return 0;
	int ans = valueOf(s[s.length()-1]);
	for(int i=s.length()-2; i >= 0; i--) {
		if(valueOf(s[i]) < valueOf(s[i+1]))
			ans = ans - valueOf(s[i]);
		else
			ans += valueOf(s[i]);
	}
	return ans;
}

int main() {
	initializeRoman();
	string s;
	cin >> s;
	while(s != "end") {
		cout << rom2int(s) << endl;
		cin >> s;
	}
	return 0;
}