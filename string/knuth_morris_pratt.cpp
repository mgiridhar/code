class Solution {
public:
    vector<int> longest_prefix_suffix(string p)
    {
        int j=0, i=1;
        vector<int> lps(p.size());
        lps[0] = 0;
        while(i<p.size())
        {
            if(p[i] == p[j])
            {
                lps[i] = lps[i-1] + 1;
                j++;
            }
            else
            {
                while(j>0 && p[i] != p[j])
                {
                    j = lps[j-1];
                }
                if(p[i] == p[j])
                {
                    lps[i] = lps[j] + 1;
                    j++;
                }
                else
                    lps[i] = 0;
            }
            i++;
        }
        /*for(int k=0; k<p.size(); k++)
            cout << lps[k] << " ";*/
        return lps;
    }
    int strStr(string haystack, string needle) {
        if(haystack.empty() && needle.empty())
            return 0;
        if(needle.empty())
            return 0;
        if(haystack.size() < needle.size())
            return -1;
        int n = haystack.length(), m = needle.length();
        int i=0, j=0;
        vector<int> lps = longest_prefix_suffix(needle);
        //cout << endl;
        while(i<n)
        {
            //cout << i << " " << j << endl;
            if(haystack[i] == needle[j])
            {
                j++;
            }
            else
            {
                while(j>0 && needle[j] != haystack[i])
                {
                    j = lps[j-1];
                }
                if(needle[j] == haystack[i])
                    j++;
            }
            i++;
            if(j == m)
                return i - m;
        }
        return -1;
    }
};