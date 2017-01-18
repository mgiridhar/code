class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = 0;
        int logm, logn;
        while(m>0 && n>0) {
            logm = log2(m);
            logn = log2(n);
            cout << logm << " " << logn << " ";
            if(logm != logn)
                break;
            result |= (1 << logm);
            m = m & ~(1 << logm);
            n = n & ~(1 << logn);
            cout << m << " " << n << " " << result << endl;
        }
        return result;
    }
};