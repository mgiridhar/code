class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int i=0, res = 0, max_res = 0;
        while(i < heights.size())
        {
            if(s.empty() || heights[s.top()] <= heights[i])
            {
                s.push(i); 
                i++;
            }
            else if(heights[s.top()] > heights[i])
            {
                while(!s.empty() && heights[s.top()] > heights[i])
                {
                    int top = s.top();
                    s.pop();
                    if(s.empty())
                    {
                        res = heights[top] * i;
                    }
                    else
                    {
                        res = heights[top] * (i-s.top()-1);
                    }
                    max_res = max(res, max_res);
                }
            }
        }
        while(!s.empty())
        {
            int top = s.top();
            s.pop();
            if(s.empty())
            {
                res = heights[top] * i;
            }
            else
            {
                res = heights[top] * (i-s.top()-1);
            }
            max_res = max(res, max_res);
        }
        return max_res;
    }
};