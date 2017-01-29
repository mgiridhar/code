class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0)
        {
            vector<int> pk;
            pk.push_back(1);
            return pk;
        }
        vector<int> pk(rowIndex+1);
        for(int i=0; i<=rowIndex; i++)
            pk[i] = 0;
        pk[rowIndex>>1] = 1;
        /*for(int i=0; i<=rowIndex; i++)
            cout << pk[i] << " ";
        cout << endl;*/
        for(int i=0; i<rowIndex; i++)
        {
            if(i&1)
            {
                for(int j=0; j<=rowIndex; j++)
                {
                    pk[j] += ((j == rowIndex) ? 0 : pk[j+1]);
                    //cout << pk[j] << " ";
                }
            }
            else
            {
                for(int j=rowIndex; j>=0; j--)
                {
                    pk[j] += ((j==0) ? 0 : pk[j-1]);
                    //cout << pk[j] << " ";
                }
            }
            //cout << endl;
        }
        return pk;
    }
};