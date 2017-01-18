#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string max_time(int A, int B, int C, int D)
{
	vector<int> digits;
	digits.push_back(A); digits.push_back(B); digits.push_back(C); digits.push_back(D);
	sort(digits.begin(), digits.end());
	string time;
	bool flag = false;
	int i;
	//first element
	for(i=digits.size()-1; i>=0; i--)
		if(digits[i] <= 2) {
			flag = true;
			break;
		}
	if(flag)
	{
		flag = false;
		time.push_back(digits[i] + 48);
		digits.erase(digits.begin() + i);
		//second element
		for(i = digits.size()-1; i>=0; i--)
		{
			if(time[0] != '2') {
				flag = true;
				break;
			}
			else if(digits[i] <= 3) {
				flag = true;
				break;
			}
		}
		if(flag)
		{
			flag = false;
			time.push_back(digits[i] + 48);
			digits.erase(digits.begin() + i);
			time.push_back(':');
			//third element
			for(i = digits.size() - 1; i>=0; i--)
				if(digits[i] <= 5) {
					flag = true;
					break;
				}
			if(flag)
			{
				time.push_back(digits[i] + 48);
				digits.erase(digits.begin() + i);
				//fourth element
				time.push_back(digits[0] + 48);
			}
		}
	}
	if(flag)
		return time;
	else 
		return "NOT POSSIBLE";
}

int main()
{
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	cout << max_time(A, B, C, D) << endl;
	return 0;
}
