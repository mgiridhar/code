class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxLen = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(')
                st.push(i);
            else {
                if(st.top() == -1 || s[st.top()] == ')') {
                    st.push(i);
                }
                else{
                    st.pop();
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};