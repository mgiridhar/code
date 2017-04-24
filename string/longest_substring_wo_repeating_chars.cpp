class Solution {
public:
// faster solution: run time - 39ms
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        unordered_map<char, int> hash;
        int start = 0, maxLen = 1;
        hash[s[0]] = 0; // map value stores its the key's position in the string
        for(int i=1; i<s.length(); i++) {
            if(hash.find(s[i]) != hash.end()) { //element available in the map
                maxLen = max(maxLen, i - start);
                start = max(start, hash[s[i]] + 1);
            }
            hash[s[i]] = i;
        }
        maxLen = max(maxLen, (int)s.length() - start);
        return maxLen;
    }

// run time - 69ms
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        map<char, int> hash;
        hash[s[0]] = 0;
        int start = 0, end = 1, i=0, j=1;
        while(j<s.length())
        {
            if(hash.find(s[j]) != hash.end())
            {
                for(int k = i; k<hash[s[j]]; k++)
                {
                    hash.erase(s[k]);
                }
                i = hash[s[j]] + 1;
            }
            hash[s[j]] = j;
            j++;
            if((end - start) < (j-i))
            {
                start = i;
                end = j;
            }
            //cout << i << " " << j << endl;
        }
        return end - start;
    }
};
