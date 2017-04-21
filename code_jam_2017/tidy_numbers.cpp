#include<iostream>
#include<fstream>
using namespace std;

bool isTidy(string n) {
	if(n.size() <= 1)
		return true;
	for(int i=n.size()-1; i>0; i--) {
		if(n[i-1] > n[i])
			return false;
	}
	return true;
}

void decrement(string &n) {
	if(n.size() == 0)
		return;
	if(n.size() == 1)
		n[0]--;
	int i;
	for(i=n.size()-1; i>0; i--) {
		if(n[i-1] > n[i])
			break;
	}
	int j = i;
	while(j<n.size()) {
		n[j] = '9';
		j++;
	}
	if(i == 1 && n[i-1] == '1') 
		n = n.substr(i);
	else
		n[i-1]--;	
}

int main() {
	ofstream fout;
	fout.open("output.txt");
	ifstream fin;
	//fin.open("B-small-attempt3.in.txt");
	fin.open("B-large.in.txt");
	int t;
	//unsigned long long int n;
	string n;
	fin >> t;
	for(int i=1; i<=t; i++) {
		fin >> n;
		while(!isTidy(n)) {
		//while(!isTidy(to_string(n))) {
			decrement(n);
			//cout << n << endl;
			//n--;
		}
		fout << "Case #" << i << ": " << n << endl;
	}
	fin.close();
	fout.close();
	return 0;
}
