/*
Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
Note:

All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
*/

class Solution {
public:
    double distance(vector<int> &p1, vector<int> &p2) {
        return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));
    }
    bool checkEqual(vector<int> &p1, vector<int> &p2) {
        return (p1[0] == p2[0]) && (p1[1] == p2[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        if(checkEqual(p1, p2) || checkEqual(p2, p3) || checkEqual(p3, p4) || checkEqual(p1, p4))
            return false;
        
        double d1_2 = distance(p1, p2);
        double d1_3 = distance(p1, p3);
        double d1_4 = distance(p1, p4);
        
        double diagonal = max(d1_2, max(d1_3, d1_4));
        double side = min(d1_2, d1_3);
        //cout << diagonal << " " << side << " " << (side * sqrt(2)) << " " << (abs(diagonal - (side * sqrt(2))) < 0.0001) << endl;
        
        if(!(((d1_2 == d1_3) && abs(d1_4 - (d1_2 * sqrt(2))) < 0.0001) || ((d1_2 == d1_4) && abs(d1_3 - (d1_2 * sqrt(2))) < 0.0001) || ((d1_3 == d1_4) && abs(d1_2 - (d1_3 * sqrt(2))) < 0.0001)))
            return false;
        
        double d2_3 = distance(p2, p3);
        double d2_4 = distance(p2, p4);
        double d3_4 = distance(p3, p4);
        
        double diagonal1 = max(d2_3, max(d2_4, d3_4));
        double side1 = min(d2_3, d3_4);
        //cout << diagonal1 << " " << side1 << " " << (side1 * sqrt(2)) << " " << (diagonal1 == (side1 * sqrt(2))) << endl;

        if(!(((d2_3 == d2_4) && abs(d3_4 - (d2_3 * sqrt(2))) < 0.0001) || ((d2_3 == d3_4) && abs(d2_4 - (d2_3 * sqrt(2))) < 0.0001) || ((d2_4 == d3_4) && abs(d2_3 - (d2_4 * sqrt(2))) < 0.0001)))
            return false;
        
        if((diagonal != diagonal1) || (side != side1))
            return false;
        
        return true;
    }
};
