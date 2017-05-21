/*
Given a string representing an expression of fraction addition and subtraction, you need to return the calculation result in string format. The final result should be irreducible fraction. If your final result is an integer, say 2, you need to change it to the format of fraction that has denominator 1. So in this case, 2 should be converted to 2/1.

Example 1:
Input:"-1/2+1/2"
Output: "0/1"
Example 2:
Input:"-1/2+1/2+1/3"
Output: "1/3"
Example 3:
Input:"1/3-1/2"
Output: "-1/6"
Example 4:
Input:"5/3+1/3"
Output: "2/1"
Note:
The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
Each fraction (input and output) has format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1,10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
The number of given fractions will be in the range [1,10].
The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
*/
class Solution {
public:
    int lcm(vector<int> denom) {
        int prod = 1;
        for(int i=0; i<denom.size(); i++) {
            prod *= denom[i];
        }
        return prod;
    }
    
    int gcd(int a, int b) {
        if(b == 0)
            return a;
        return gcd(b, a%b);
    }

    int sum_numerators(vector<int> num, vector<int> denom, int lcm) {
        int sum = 0;
        for(int i=0; i<num.size(); i++) {
            sum += (num[i] * (lcm / denom[i]));
        }
        return sum;
    }

    void print(vector<int> num, vector<int> denom) {
        cout << num.size() << " " << denom.size() << endl;
        for(int i=0; i<num.size(); i++) {
            cout << num[i] << "/" << denom[i] << " ";
        }
    }
    
    string fractionAddition(string expression) {
        if(expression.size() <= 4)
            return expression;
        vector<int> numerators, denominators;
        int sign; // 1 - positive, -1 - negative
        
        for(int i = 0; i<expression.size();) {
            if(expression[i] == '-') {
                sign = -1;
                i++;
            }
            else if (expression[i] == '+'){
                sign = 1;
                i++;
            }
            else
                sign = 1;
            int num = 0;
            while(i < expression.size() && expression[i] >= '0' && expression[i] <= '9') {
                num = (num * 10) + (expression[i] - '0');
                i++;
            }
            numerators.push_back(num * sign);
            if(expression[i] == '/')
                i++;
            
            int denom = 0;
            while(i < expression.size() && expression[i] >= '0' && expression[i] <= '9') {
                denom = (denom * 10) + (expression[i] - '0');
                i++;
            }
            denominators.push_back(denom);
        }
        
        //print(numerators, denominators);
        
        int res_denom = lcm(denominators);
        int res_num = sum_numerators(numerators, denominators, res_denom);
        string result = "";
        if(res_num == 0) {
            return "0/1";
        }
        if(res_num < 0) {
            result += "-";
            res_num *= -1;
        }
        
        int com_div = gcd(max(res_num, res_denom), min(res_num, res_denom));
        res_num /= com_div;
        res_denom /= com_div;
        result += to_string(res_num) + '/' + to_string(res_denom);
        
        return result;
    }
};
