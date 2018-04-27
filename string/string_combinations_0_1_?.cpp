/*
For this popular algorithm interview question, the input will be a string consisting only of 
the characters 0, 1 and ?, where the ? acts as a wildcard that can be either a 0 or 1, and your 
goal is to print all possible combinations of the string. For example, if the string is "011?0" 
then your program should output a set of all strings, which are: ["01100", "01110"].
*/
// Time - O(2^n), Space - O(2^n)

#include<iostream>
#include<queue>
using namespace std;

vector<string> string_combinations(string s) {
    queue<string> q;
    q.push(s);
    int size, idx = 0;
    string temp;
    while(!q.empty()) {
        temp = q.front();
        while(idx < temp.length() && temp[idx] != '?') {
            idx++;
        }
        if(idx == temp.length()) { // end of string
            break;
        }

        size = q.size();
        while(size--) {
            temp = q.front();
            q.pop();
            temp[idx] = '0';
            q.push(temp);
            temp[idx] = '1';
            q.push(temp);
        }
    }

    vector<string> result;
    while(!q.empty()) {
        result.push_back(q.front());
        q.pop();
    }
    return result;
}

void print(vector<string> strings) {
    for(int i=0; i<strings.size(); i++) {
        cout << strings[i] << endl;
    }
}

int main() {
    string s;
    cin >> s;
    vector<string> result = string_combinations(s);
    cout << endl << "output: " << endl;
    print(result);
    return 0;
}