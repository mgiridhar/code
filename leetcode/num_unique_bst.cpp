class Solution {
public:
    unsigned long int combination(unsigned long int n, unsigned long int r)
    {
        unsigned long int res = 1;
        if(r > n-r)
            r = n-r;
        for(int i=0; i<r; i++)
        {
            res *= (n-i);
            res /= (i+1);
        }
        return res;
    }
    
    unsigned long int numTrees(unsigned long int n) {
        return combination(2*n, n)/(n+1);
    }
};
