/*
Write a function to find the longest common prefix string amongst an array of strings.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        string lcp = "";
        
        //*** 6 ms ***
        sort(strs.begin(), strs.end());
        for(int i=0; i<strs[0].length(); i++) {
            if(i < strs[strs.size()-1].length() && strs[0][i] == strs[strs.size()-1][i])
                lcp++;
            else
                break;
        }
        return strs[0].substr(0, lcp);
        
        /*** 9 ms ***
        for(int i=0; i<strs[0].length(); i++) {
            for(int j=1; j<strs.size(); j++) {
                if(i >= strs[j].length() || strs[0][i] != strs[j][i])
                    goto result;
            }
            lcp += strs[0][i];
        }
        result:
        return lcp;
        */
        
        /*** 9 ms ***
        for(int i=0; i<strs[0].length(); i++) {
            for(int j=1; j<strs.size(); j++) {
                if(i >= strs[j].length() || strs[0][i] != strs[j][i])
                    return strs[0].substr(0, lcp);
            }
            lcp++;
        }
        return strs[0];
        */
        
    }
};