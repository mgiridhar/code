#include<iostream>
#include<cstring>
using namespace std;

string first_repeating_character(string s)
{
	int upper_case[26], lower_case[26];
	for(int i=0; i<26; i++)
	{
		upper_case[i] = -1;
		lower_case[i] = -1;
	}
	int char_index = s.length();
	for(int i=0; i<s.length(); i++)
	{
		if(s[i] >= 65 && s[i] <=90)
		{
			if(upper_case[s[i] - 65] == -1)
			{
				upper_case[s[i] - 65] = i;
			}
			else
			{
				if(upper_case[s[i] - 65] < char_index)
					char_index = upper_case[s[i] - 65];
			}
		}
		else
		{
			if(lower_case[s[i] - 97] == -1)
			{
				lower_case[s[i] - 97] = i;
			}
			else
			{
				if(lower_case[s[i] - 97] < char_index)
					char_index = lower_case[s[i] -97];
			}
		}
		cout << char_index << " ";
	}
	cout << endl;
	for(int i=0; i<26; i++)
	{
		cout << upper_case[i] << " " << lower_case[i] << endl;
	}
	string return_str = "";
	if(char_index < s.length())
		return_str.push_back(s[char_index]);
	return return_str;
}

int main()
{
	string str;
	cin >> str;
	cout << first_repeating_character(str) << endl;
	return 0;
}
