class Solution {
public:
    /*** optimized solution - find the occurrence of repeatition pattern of s2 in S1 and then calculate repeatition accordingly .ie. (prefix count + pattern count + suffix count)/n2 
        Check: http://blog.csdn.net/kusanoneu/article/details/72391639 and https://discuss.leetcode.com/topic/70667/c-0ms-o-str1-length-str2-length for detailed explanation
    ***/
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> repeatCount(n1+1, 0);
        unordered_map<int, int> nextInd;
        int k = 0, count = 0;
        for(int i=1; i<=n1; i++) {
            for(int j=0; j<s1.size(); j++) {
                if(s1[j] == s2[k]) {
                    k++;
                }
                if(k == s2.size()) {
                    k = 0;
                    count++;
                }
            }
            repeatCount[i] = count;
            if(nextInd.count(k)) {
                int patStart = nextInd[k];
                int prefixCount = repeatCount[patStart];
                int patternCount = (repeatCount[i] - repeatCount[patStart]) * (n1 - patStart) / (i - patStart);
                int suffixCount = repeatCount[patStart + ((n1 - patStart) % (i - patStart))] - repeatCount[patStart];
                return (prefixCount + patternCount + suffixCount) / n2;
            }
            nextInd[k] = i;
        }
        return count / n2;
    }
    
    /*** Simple solution - timed out***/
    /*** count the number of occurrences of s2 in S1 and then return  count/n2 ***/
    /*
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int count = 0, k = 0;
        for(int i=1; i<=n1; i++) {
            for(int j=0; j<s1.size(); j++) {
                if(s1[j] == s2[k]) {
                    k++;
                }
                if( k == s2.size() ) {
                    k=0;
                    count++;
                }
            }
        }
        return count/n2;
    }
    */
};