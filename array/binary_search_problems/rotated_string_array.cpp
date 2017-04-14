//https://www.interviewcake.com/question/cpp/find-rotation-point?utm_source=weekly_email&utm_campaign=weekly_email&utm_medium=email
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string myFunction (const vector<string> words)
{
    // write the body of your function here
    if(!words.size())
        return "";
    if(words.size() == 1)
        return words[0];
    if(words.size() == 2)
        return (words[0].compare(words[1])) ? words[0] : words[1];
    unsigned long int l = 0, h = words.size() - 1, m;
    while(l <= h) {
        if(words[l].compare(words[h]) <= 0)
            return words[l];
        m = l + (h - l) / 2;
        if(m > 0 && words[m-1].compare(words[m]) > 0)
            return words[m];
        if(m < words.size()-1 && words[m].compare(words[m+1]) > 0)
            return words[m+1];
        
        if(words[l].compare(words[m]) < 0)
            l = m+1;
        else
            h = m-1;
    }
    return "NOT FOUND";
}

int main ()
{
    // run your function through some test cases here
    // remember: debugging is half the battle!
    const vector<string> words {
        "ptolemaic",
        "retrograde",
        "supplant",
        "undulate",
        "xenoepist",
        "asymptote", // <-- rotates here!
        "babka",
        "banoffee",
        "engender",
        "karpatka",
        "othellolagkage",
    };
    cout << myFunction (words);
    return 0;
}
