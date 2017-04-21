#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

long int chooseBath(vector<long int> &l, vector<long int> &r) {

	long int choice = -1;
	long int maxmin = -1, maxmax = -1;
	for(int i=0; i<l.size(); i++) {

		//cout << l[i] << "," << r[i] << " ";
		if(l[i] == -1 && r[i] == -1)
			continue;
		long int mins = min(l[i], r[i]);
		long int maxs = max(l[i], r[i]);
		if(mins > maxmin) {
			choice = i;
			maxmin = mins;
			maxmax = maxs;
		}
		else if(mins == maxmin && maxs > maxmax) {
			choice = i;
			maxmax = maxs;
		}
	}
	//cout << endl;
	return choice;
}

int main() {
	int t;
	long int n, k;
	ofstream fout;
	fout.open("bath_output");
	ifstream fin;
	fin.open("C-small-practice-2.in.txt");
	fin >> t;
	for(int i=1; i<=t; i++) {
		fin >> n >> k;
		vector<long int> l(n), r(n);
		long int choice;
		for(long int j=0; j<n; j++) {
			l[j] = j;
			r[n-j-1] = j;
			//cout << l[j] << "," << r[n-j-1] << " ";
		}
		//cout << endl;
		for(long int j=1; j<k; j++) {
			choice = chooseBath(l, r);
			//cout << choice << endl;
			l[choice] = -1;
			r[choice] = -1;
			long int p = choice + 1, q = choice - 1;
			int s = 0;
			while(p < n && l[p] != -1) {
				l[p] = s;
				s++;
				p++;
			}
			s = 0;
			while(q >=0 && r[q] != -1) {
				r[q] = s;
				s++;
				q--;
			}
		}
		choice = chooseBath(l, r);
		fout << "Case #" << i << ": " << max(l[choice], r[choice]) << " " << min(l[choice], r[choice]) << endl;
	}
	fout.close();
	fin.close();
	return 0;
}
