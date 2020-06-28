#include<iostream>
#include<string>
using namespace std;
//int main()
//{
//	string s1;
//	s1 = "Hello world!";
//	/*s1.reserve(40);
//	s1.reserve(10);
//	s1.resize(20, '&');
//	s1.resize(10);*/
//	//string::iterator it = s1.begin();
//	//while (it != s1.end())
//	//{
//	//	cout << *it++ << endl;
//	//}
//	string::reverse_iterator it = s1.rbegin();
//	while (it != s1.rend())
//	{
//		cout << *it++ << endl;
//	}
//	
//	/*for (auto ch : s1)
//	{
//		cout << ch << endl;
//	}*/
//	cin.get();
//	return 0;
//}

//int main()
//{
//	string s = "ajdijaio";
//	string s1("jkaq");
//	s.push_back('a');
//	s.append(5, '&');
//	s += '^';
//	s += "Hello";
//	cin.get();
//	return 0;
//}

//int main()
//{
//	string s1;
//	while (getline(cin, s1))
//	{
//		int n = 0;
//		int pos = s1.rfind(' ');
//		pos += 1;
//		while (s1[pos] != '\0')
//		{
//			pos++;
//			++n;
//		}
//		cout << n << endl;
//	}
//	return 0;
//}

//class Solution {
//public:
//	string reverseOnlyLetters(string S)
//	{
//		char* left = (char*)S.c_str();
//		int n = S.size() - 1;
//		char* right = left + n;
//		while (left<right)
//		{
//			//从前往后找，找到字符串的第一个字符
//			while (left<right)
//			{
//				if (isalpha(*left))
//				{
//					break;
//				}
//				//不是的话指针后移
//				++left;
//			}
//			//从后往前找到最后一个字符
//			while (right>left)
//			{
//				if (isalpha(*right))
//				{
//					break;
//				}
//				--right;
//			}
//			//如果left和right指向同一个字符，不做处理
//			if (left<right)
//			{
//				swap(*left, *right);
//				++left;
//				--right;
//			}
//		}
//		return S;
//	}
//	string S = ("ab - cd");
//};

class Solution {
public:
	bool isPalindrome(string s)
	{
		if (s.empty())
		{
			return true;
		}
		int begin = 0;
		int end = s.length() - 1;

		while (begin<end)
		{
			while (begin<end)
			{
				if (IsNumberOrLetter(s[begin]))
				{
					break;
				}
				begin++;
			}
			while (begin<end)
			{
				if (IsNumberOrLetter(s[end]))
				{
					break;
				}
				end--;
			}
			if (begin<end)
			{
				if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
				{
					return false;
				}
				begin++;
				end--;
			}
		}
		return true;
	}
	bool IsNumberOrLetter(char c)
	{
		if ('0' <= c <= '9' ||
			'A' <= c <= 'Z' ||
			'a' <= c <= 'z')
		{
			return true;
		}
		return false;
	}
};
int main()
{
	Solution S1;
	string S = ("ab - cd");
	string s = "A man, a plan, a canal : Panama";
	S1.isPalindrome(s);
	cin.get();
	return 0;
}