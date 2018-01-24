/*

A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.

*/
class Solution {
public:
    vector<int> partitionLabels(string S) {
        if(S.length() == 0)
            return vector<int>();
        stack<int> st;
        st.push(-1);
        unordered_map<char, int> hash;
        for(int i=0; i<S.length(); i++) {
            if(hash.find(S[i]) == hash.end()) {
                st.push(i);
                hash[S[i]] = i;
                continue;
            }
            int p = hash[S[i]];
            while(!st.empty() && st.top() >= p) {
                st.pop();
            }
            st.push(i);
        }
        vector<int> result;
        while(st.size() > 1) {
            int t = st.top();
            st.pop();
            result.push_back(t - st.top());
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
