#include<iostream>
#include<fstream>
using namespace std;

int happyPossible(string s, int k) {
	int flips = 0;
	bool poss = true;
	for(int i = s.length()-1; i >= (k-1); i--) {
		if(s[i] == '+') {
			continue;
		}
		else {
			flips++;
			poss = true;
			for(int j=0; j<k; j++) {
				if(s[i-j] == '-'){
					s[i-j] = '+';
				}
				else {
					poss = false;
					s[i-j] = '-';
				}
			}
		}
	}
	for(int i=0; i<k; i++) {
		if(s[i] == '-') {
			poss = false;
			break;
		}
	}
	if(poss)
		return flips;
	else
		return -1;
}

int main() {

	ifstream fin;
	//fin.open("A-small-attempt2.in.txt");
	fin.open("A-large.in.txt");
	ofstream fout;
	fout.open("panflip_output.txt");

	int t, k, flips;
	string s;
	fin >> t;
	for(int i=1; i<=t; i++) {
		fin >> s >> k;
		if((flips = happyPossible(s, k)) >= 0)
			fout << "Case #" << i << ": " << flips << endl;
		else
			fout << "Case #" << i << ": IMPOSSIBLE" << endl;
	}
	return 0;
}
