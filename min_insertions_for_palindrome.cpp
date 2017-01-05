#include <iostream>
#include <cstring>
using namespace std;

//recursive solution
int rec_min_inserts(char str[], int l, int h) {
    if(l > h)
        return 0;
    if(l == h)
        return 0;
    int min_in = min(1 + min_insertions(str, l+1, h), 1 + min_insertions(str, l, h-1));
    if(str[l] == str[h]) {
        min_in = min(min_in, min_insertions(str, l+1, h-1));
    }
    return min_in;
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--) {
	    char str[40];
	    cin >> str;
	    cout << rec_min_inserts(str, 0, strlen(str)-1) << endl;
	}
	return 0;
}
