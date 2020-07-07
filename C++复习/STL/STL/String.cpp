#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
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

//class Solution {
//public:
//	bool isPalindrome(string s)
//	{
//		if (s.empty())
//		{
//			return true;
//		}
//		int begin = 0;
//		int end = s.length() - 1;
//
//		while (begin<end)
//		{
//			while (begin<end)
//			{
//				if (IsNumberOrLetter(s[begin]))
//				{
//					break;
//				}
//				begin++;
//			}
//			while (begin<end)
//			{
//				if (IsNumberOrLetter(s[end]))
//				{
//					break;
//				}
//				end--;
//			}
//			if (begin<end)
//			{
//				if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
//				{
//					return false;
//				}
//				begin++;
//				end--;
//			}
//		}
//		return true;
//	}
//	bool IsNumberOrLetter(char c)
//	{
//		if ('0' <= c <= '9' ||
//			'A' <= c <= 'Z' ||
//			'a' <= c <= 'z')
//		{
//			return true;
//		}
//		return false;
//	}
//};

//字符串相加
//class Solution {
//public:
//	string addStrings(string num1, string num2)
//	{
//		int end1 = num1.size() - 1;
//		int end2 = num2.size() - 1;
//		int value1 = 0, value2 = 0;
//		//进位
//		int next = 0;
//		string addret;
//		while (end1 >= 0 || end2 >= 0)
//		{
//			if (end1 >= 0)
//			{
//				value1 = num1[end1--] - '0';
//			}
//			else
//				value1 = 0;
//			if (end2 >= 0)
//				value2 = num2[end2--] - '0';
//			else
//				value2 = 0;
//			int valueret = value1 + value2 + next;
//
//			if (valueret >= 10)
//			{
//				valueret -= 10;
//				next = 1;
//			}
//			else
//			{
//				next = 0;
//			}
//			addret += (valueret + '0');
//		}
//		if (next == 1)
//		{
//			addret += '1';
//		}
//		reverse(addret.begin(), addret.end());
//		return addret;
//	}
//};

//字符串相乘
//class Solution {
//public:
//	string multiply(string num1, string num2)
//	{
//		vector<int> a, b, c;
//		string ans;
//		for (int i = 0; i<num1.size(); i++)
//			a.push_back(num1[i] - '0');
//		for (int i = 0; i<num2.size(); i++)
//			b.push_back(num2[i] - '0');
//		for (int i = 0; i<a.size(); i++)
//		{
//			for (int j = 0; j<b.size(); j++)
//			{
//				c[i + j] += a[i] * b[j];
//			}
//		}
//		int index = c.size() - 1;
//		int next = 0;
//		while (index >= 0)
//		{
//			c[index] += next;
//			next = c[index] / 10;
//			c[index] %= 10;
//			ans += (c[index] + '0');
//		}
//		return ans;
//	}
//};

//输出字符串第一个只出现一次的字符
//https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4?tpId=37&&tqId=21282&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s;
//	while (cin >> s)
//	{
//		bool isexit = false;
//		char c;
//		int count[256] = { 0 };
//		int n = s.size();
//		for (int i = 0; i<n; i++)
//		{
//			count[s[i]] += 1;
//		}
//		for (int i = 0; i<n; i++)
//		{
//			if (count[s[i]] == 1)
//			{
//				cout << s[i] << endl;
//				isexit = true;
//				break;
//			}
//		}
//		if (isexit == false)
//		{
//			cout << -1 << endl;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	/*Solution S1;
//	string S = ("ab - cd");
//	string s = "A man, a plan, a canal : Panama";
//	S1.isPalindrome(s);*/
//	/*string s1 = "123";
//	string s2 = "456";
//	cout << s1 + s2 << endl;
//	cout << 'a' + 'b' << endl;
//	cout << s1 + '1' << endl;*/
//	//Solution S;
//	//string num1 = "9";
//	//string num2 = "99";
//	////cout<<S.addStrings(num1, num2)<<endl;
//	//string a;
//	//a += (8 + '0');
//	//cout << a << endl;
//	//a += (0 + '0');
//	//cout << a << endl;
//	//a = "123456";
//	//reverse(a.begin(), a.end());
//	//cout << 18 % 10 << endl;
//	//cout << a << endl;
//	/*vector<int> a;
//	a.push_back(1);
//	a.push_back(2);
//	a.push_back(3);*/
//	Solution s;
//	string num1 = "123";
//	string num2 = "456";
//	s.multiply(num1, num2);
//	cin.get();
//	return 0;
//}

#include<stdio.h>

//void   print(int  w)
//{
//	int  i;
//	if (w != 0)
//	{
//		print(w - 1);
//		for (i = 1; i <= w; ++i)
//			printf(" % 3d, ", w);
//		printf("\n");
//	}
//}

//int main()
//{
//	int w = 4;
//	print(w);
//	cin.get();
//	return 0;
//}

//#include<string.h>
//#include<algorithm>
////模拟实现string
//namespace my_string
//{
//	class string
//	{
//	public:
//		string(const char* str = " ")
//		{
//			//string s1();
//			if (str == nullptr)
//			{
//				//构造一个空的字符串
//				_str = new char[1];
//				*_str = '\0';
//				
//			}
//			else
//			{
//				_str = new char[strlen(str) + 1];
//				strcpy(_str, str);
//			}
//		}
//
//		/*string(const string&s)
//			:_str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str, s._str);
//		}*/
//		string(const string&s)
//			:_str(nullptr)
//		{
//			string temp(s);
//			//swap(_str, s._str);
//		}
//		//string& operator=(const string&s)
//		//{
//		//	if (this != &s)
//		//	{
//		//		char* PStr = new char[strlen(s._str) + 1];
//		//		strcpy(PStr, s._str);
//		//		//应该释放s1的空间，因为要给s1里面赋值拷贝。
//		//		delete[] _str;
//		//		_str = PStr;
//		//	}
//		//	return *this;
//		//}
//		string& operator =(const string&s)
//		{
//			if (this != &s)
//			{
//				string temp(s);
//				//swap(_str, s._str);
//			}
//			return *this;
//		}
//		~string()
//		{
//			if (_str != NULL)
//			{
//				delete[] _str;
//				_str = nullptr;
//				size = 0;
//				capacity = 0;
//			}
//		}
//	private:
//		char* _str;
//		size_t size;
//		size_t capacity;
//	};
//}
//
//int main()
//{
//	my_string::string s1 = "abc";
//	my_string::string s2;
//	my_string::string s3(s2);
//	my_string::string s4 = "awdad";
//	//拷贝
//	my_string::string s5 = s1;
//	//赋值
//	s1 = s4;
//	//cin.get();
//	return 0;
//}



