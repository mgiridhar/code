/*
Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
*/
class Solution {
public:
    int parseInt(string &s, int start, int end) {
        if(start == end) return 0;
        int n = 0, flag = 1;
        if(s[start] == '-') {
            flag = -1;
            start++;
        }
        for(int i=start; i<end; i++) {
            int t = int (s[i] - '0');
            n = (n * 10) + t;
        }
        return n * flag;
    }
    pair<int, int> parseComplex(string &s) {
        pair<int, int> cn;
        int start = 0, i;
        i = start+1;
        while(s[i] >= '0' && s[i] <= '9') {
            i++;
        }
        cn.first = parseInt(s, start, i);
        start = i + 1;
        i+=2;
        while(s[i] >= '0' && s[i] <= '9') {
            i++;
        }
        cn.second = parseInt(s, start, i);
        return cn;
    }
    string complexNumberMultiply(string a, string b) {
        pair<int, int> c1, c2;
        c1 = parseComplex(a);
        c2 = parseComplex(b);
        //cout << c1.first << " " << c1.second << endl;
        //cout << c2.first << " " << c2.second << endl;
        int real = (c1.first * c2.first) + (c1.second * c2.second * -1);
        int complex = (c1.first * c2.second) + (c1.second * c2.first);
        return to_string(real) + "+" + to_string(complex) + "i";
    }
};