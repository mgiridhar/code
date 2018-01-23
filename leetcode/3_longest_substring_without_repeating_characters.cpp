/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
/*
 * Time Complexity - O(n)
 * Space Complexity - O(n)
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) 
            return 0;
        unordered_map<char, int> hash;
        int start = 0, maxLength = 0;
        for(int i=0; i<s.length(); i++) {
            if(hash.find(s[i]) != hash.end()) {
                int t = hash[s[i]];
                while(start <= t) {
                    hash.erase(s[start]);
                    start++;
                }
            }
            hash[s[i]] = i;
            maxLength = max(maxLength, i - start + 1);
        }
        return maxLength;
    }
};
