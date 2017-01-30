class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty())
            return 0;
        vector<int> candies(ratings.size());
        candies[0] = 1;
        for(int i=1; i<ratings.size(); i++)
        {
            if(ratings[i-1] < ratings[i])
                candies[i] = candies[i-1] + 1;
            else 
                candies[i] = 1;
        }
        int numCandies = candies[ratings.size()-1];
        for(int i=ratings.size()-2; i>=0; i--)
        {
            if(ratings[i] > ratings[i+1] && candies[i] <= candies[i+1])
                candies[i] = candies[i+1] + 1;
            numCandies += candies[i];
        }
        /*for(int i=0; i<candies.size(); i++)
            cout << candies[i] << " ";*/
        return numCandies;
    }
};