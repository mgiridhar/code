/*
 *

You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

 */


/*** Longest Increasing Subsequence type solution ***/
bool myComp(pair<int, int> a, pair<int, int> b) {
    return (a.first == b.first) ? (a.second < b.second) : (a.first < b.first);
}
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.size() == 0)
            return 0;
        sort(envelopes.begin(), envelopes.end(), myComp);
        int maxEnv = 1;
        vector<int> dp(envelopes.size(), 1);
        for(int i=1; i<envelopes.size(); i++) {
            for(int j=0; j < i; j++) {
                if(envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                maxEnv = max(maxEnv, dp[i]);
            }
        }
        /*for(int i=0; i<envelopes.size(); i++) {
            cout << envelopes[i].first << " " << envelopes[i].second << endl;
        }*/
        return maxEnv;
    }
};
