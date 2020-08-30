#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
//bool Check(vector<vector<char>> &v)
//{
//	int sum = 0;
//	int T = 0;
//	int B = 0;
//	int W = 0;
//	for (int i = 0; i < v.size(); ++i)
//	{
//		if (v[i][1] == 'T')
//		{
//			++T;
//		}
//		if (v[i][1] == 'B')
//		{
//			++B;
//		}
//		if (v[i][i] == 'W')
//		{
//			++W;
//		}
//	}
//	if (T > 3 || B > 3 || W > 3)
//	{
//		return false;
//	}
//	return true;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	vector<vector<char>> v;
//	while (n--)
//	{
//		int x = 0;
//		char y;
//		int i = 0;
//		while (cin >> x >> y)
//		{
//			char c = '0' + x;
//			v[i][0] = c;
//			v[i][1] = y;
//			++i;
//		}
//		if (Check(v))
//		{
//			cout << "YES" << endl;
//		}
//		else
//		{
//			cout << "NO" << endl;
//		}
//	}
//	return 0;
//}


//int main()
//{
//	vector<vector<char>> v;
//	for (int i = 0; i < 3; i++)
//	{
//		char c = 'a';
//		v[i][0] = c;
//		v[i][1] = 'b';
//	}
//	cin.get();
//	return 0;
//}

//
//class A
//{
//public:
//	int Add(int a, int b);
//private:
//	int a;
//	//char c;
//};
//
//int main()
//{
//	A a;
//	cout << sizeof(a) << endl;
//	cin.get();
//	return 0;
//}


//typedef struct ListNode
//{
//	int val;
//	ListNode *pre;
//	ListNode *next;
//}ListNode;
//typedef struct TreeNode
//{
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//}TreeNode;
//#include<queue>
//ListNode *Test(TreeNode *pRoot)
//{
//	queue<TreeNode*> q;
//	q.push(pRoot);
//	ListNode* pHead = NULL;
//
//	while (!q.empty())
//	{
//		int size = q.size();
//		for (int i = 0; i < size; ++i)
//		{
//			TreeNode *Tcur = q.front();
//			ListNode *Lcur = new ListNode();
//			pHead->next = Lcur;
//
//			Lcur->val = Tcur->val;
//			Lcur->pre=
//			
//			if (Tcur->left)
//			{
//				q.push(Tcur->left);
//			}
//			if (Tcur->right)
//			{
//				q.push(Tcur->right);
//			}
//		}
//	}
//
//}
//
//void insert(ListNode *node,int val)
//{
//	ListNode *newNode = new ListNode();
//	newNode->val = val;
//	
//	node->next = newNode;
//	newNode->pre = node;
//}




//#include<algorithm>
//int CalulateMethodCount(int num_money)
//{
//	if (num_money == 1)
//	{
//		return 1;
//	}
//	int result = 1;
//	for (int i = 1; i<num_money; ++i)
//	{
//		result *= 2;
//	}
//	return result;
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int ret=CalulateMethodCount(n);
//	cout << ret << endl;
//	cin.get();
//	return 0;
//}



//int main()
//{
//	int a = 0, b = 0, c = 0;
//	while (cin >> a >> b >> c)
//	{
//		vector<int> result;
//		result.push_back(a);
//		result.push_back(b);
//		result.push_back(c);
//		sort(result.begin(), result.end());
//		cout << "[" << result[0] << "," << " " << result[1] << "," << " " << result[2] << "]" << endl;
//	}
//	return 0;
//}



//#include<iostream>
//#include<string>
//using namespace std;
//
//bool Is_range(string& s)
//{
//	bool flag = true;
//	for (int i = 0; i < s.size(); ++i)
//	{
//		if (!(('A' <= s[i]&& s[i]<= 'Z') ||( 'a' <= s[i]&& s[i]<= 'z')))
//		{
//			flag = false;
//			break;
//		}
//	}
//	return flag;
//}
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		int result = 0;
//		string s;
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> s;
//			if ((0<=s.size() <= 10) && Is_range(s))
//			{
//				++result;
//			}
//		}
//		cout << result << endl;
//	}
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<list>
//using namespace std;
//
//void Move_End_Num(list<int>& number)
//{
//	int num = *number.begin();
//	number.erase(number.begin());
//	number.push_back(num);
//}
//void Swap(list<int>& number)
//{
//	auto it = number.begin();
//	while (it != number.end())
//	{
//		swap(it, ++it);
//		++it;
//	}
//}
//int main()
//{
//	int n, m;
//	while (cin >> n >> m)
//	{
//		if (n % 2!=0)
//		{
//			break;
//		}
//		vector<int> op(m);
//		for (int i = 0; i < op.size(); ++i)
//		{
//			cin >> op[i];
//		}
//		list<int> number;
//		for(int i = 0; i < number.size(); ++i)
//		{
//			number.push_back(i + 1);
//		}
//		for (int i = 0; i < op.size(); ++i)
//		{
//			if (op[i] == 1)
//			{
//				Move_End_Num(number);
//			}
//			else
//			{
//				Swap(number);
//			}
//		}
//		for (auto it = number.begin(); it != number.end(); ++it)
//		{
//			cout << *it;
//		}
//		cout << endl;
//	}
//	return 0;
//}






#include<iostream>
#include<string>
using namespace std;
//void Find_Char(string& str)
//{
//	int start = 0;
//	auto pos = 0;
//	while (pos < str.size())
//	{
//		pos = str.find(start+1, 'n');
//		if (pos != str.npos)
//		{
//			str[start] -= 32;
//			for (int i = start; i < pos; ++i)
//			{
//				cout << str[i];
//			}
//			cout << endl;
//		}
//		start = pos;
//	}
//}
//int main()
//{
//	string str;
//	cin >> str;
//	if (str.empty())
//	{
//		return 0;
//	}
//	int start = 0;
//	auto pos = 0;
//	while (pos < str.size())
//	{
//		pos = str.find( 'n', start + 1);
//		if (pos != str.npos)
//		{
//			str[start] -= 32;
//			for (int i = start; i < pos; ++i)
//			{
//				cout << str[i];
//			}
//			cout << endl;
//			start = pos;
//		}
//	}
//	if (start < str.size())
//	{
//		str[start] -= 32;
//		for (auto i = start; i < str.size(); ++i)
//		{
//			cout << str[i];
//		}
//		cout << endl;
//	}
//	return 0;
//}

//#include<vector>
//int mian()
//{
//	int m, n;
//	cin >> m >> n;
//	vector<vector<int>> dp(m, vector<int>(n));
//	for (int i = 0; i < m; ++i)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> dp[i][j];
//		}
//	}
//	return 0;
//}



//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> tree(n);
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> tree[i];
//	}
//	int count = 0;
//	sort(tree.begin(), tree.end());
//	int min = tree[0];
//	for (int i = 0; i < n; ++i)
//	{
//		count += (tree[i] - min);
//	}
//	cout << count << endl;
//	return 0;
//}




//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//	string str;
//	getline(cin, str);
//	int n;
//	cin >> n;
//	vector<vector<int>> numbers(0, vector<int>(2, 0));
//	for (int i = 0; i < n; ++i)
//	{
//		vector<int> temp;
//		int a, b;
//		cin >> a >> b;
//		temp.push_back(a);
//		temp.push_back(b);
//		numbers.push_back(temp);
//	}
//	vector<int> tmp(10);
//	for (int i = 0; i < n; ++i)
//	{
//
//		for (int j = 0; j < 10; j++)
//		{
//			if (tmp[j] == numbers[i][0])
//			{
//				tmp[j] = numbers[i][1];
//			}
//		}
//		tmp[numbers[i][0]] = numbers[i][1];
//	}
//	for (int i = 0; i < str.size(); ++i)
//	{
//		int j = str[i] - '0';
//		char c = tmp[j] + '0';
//		str[i] = c;
//	}
//	cout << str << endl;
//	cin.get();
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//long long TenReverseFive(long long n)
//{
//	long long number = 0;
//	while (n)
//	{
//		int temp = n % 10;
//		if (temp == 0)
//		{
//			n /= 10;
//		}
//		else
//		{
//			break;
//		}
//	}
//	while (n)
//	{
//		int temp = n % 10;
//		number = number * 10 + temp;
//		n /= 10;
//	}
//	vector<int> arr;
//	while (number)
//	{
//		int temp = number % 5;
//		arr.insert(arr.begin(), temp);
//		number /= 5;
//	}
//	long long result=0;
//	auto it = arr.begin();
//	while (it != arr.end())
//	{
//		result = result * 10 + (*it++);
//	}
//	return result;
//}
//int main()
//{
//	long long TenNumeber = 0;
//	cin >> TenNumeber;
//	int FiveNumber = TenReverseFive(TenNumeber);
//	cout << FiveNumber << endl;
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
////////////////////////////////////////////////////////////////////////////
////请根据要求实现以下函数
//class ToString {
//public:
//	void toString(int x, vector<string>& output)
//	{
//
//	}
//};
////////////////////////////////////////////////////////////////////////////
////以下的输入输出代码请勿改动
//int main()
//{
//	ToString t;
//	auto ilineCount = 0;
//	string line;
//	getline(cin, line);
//	auto iTotalLines = stoi(line);
//	vector<string> curRes;
//
//	while (ilineCount < iTotalLines)
//	{
//		getline(cin, line);
//
//		t.toString(stoi(line), curRes);
//		string curlineRes;
//		for (auto iter = curRes.cbegin(); iter != curRes.cend(); iter++)
//		{
//			curlineRes += (*iter) + " ";
//		}
//		curRes.clear();
//		cout << curlineRes << endl;
//
//		ilineCount++;
//	}
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	vector<int> arr;
//	int num = 0;
//	while (1)
//	{
//		cin >> num;
//		arr.push_back(num);
//		if (cin.get() == '\n')
//		{
//			break;
//		}
//	}
//	int count = 0;
//	auto it = arr.begin();
//	
//	while (it != arr.end() )
//	{
//		if (*it == 0)
//		{
//			
//			it=arr.erase(it);
//			++count;
//		}
//		else
//		{
//			++it;
//		}
//	}
//	//补0
//	for (int i = 0; i < count; ++i)
//	{
//		arr.push_back(0);
//	}
//	//输出
//	for (auto e:arr)
//	{
//		cout << e;
//	}
//	cout << endl;
//	return 0;
//}
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void getmemory(char*& p)
{
	p = (char*)malloc(100);
}
void test()
{
	char *str = NULL;
	getmemory(str);
	strcpy(str, "hello wordle!");
	printf("%s\n", str);
}
int main()
{
	test();
	return 0;
}
//typedef struct ListNode {
//	int val;
//	ListNode *next;	
//}ListNode;
//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
//	{
//	if (l1 == NULL)
//	{
//		return l2;
//	}
//	if (l2 == NULL)
//	{
//		return l1;
//	}
//	ListNode* newList = NULL;
//	ListNode* cur1 = l1;
//	ListNode* cur2 = l2;
//	ListNode* tail = NULL;
//	if (cur1->val <= cur2->val)
//	{
//		newList = cur1;
//		cur1 = cur1->next;
//	}
//	else
//	{
//		newList = cur2;
//		cur2 = cur2->next;
//	}
//	tail = newList;
//	while (cur1&&cur2)
//	{
//		if (cur1->val <= cur2->val)
//		{
//			tail->next = cur1;
//			cur1 = cur1->next;
//		}
//		else{
//			tail->next = cur2;
//			cur2 = cur2->next;
//		}
//		tail = tail->next;
//	}
//	if (cur1 == NULL)
//	{
//		tail->next = cur2;
//	}
//	if (cur2 == NULL)
//	{
//		tail->next = cur1;
//	}
//	return newList;
//}
//int main()
//{
//	ListNode* pHead1 = NULL;
//	ListNode* pHead2 = NULL;
//	int num = 0;
//	ListNode* cur1 = pHead1;
//	ListNode* cur2 = pHead2;
//	while (1)
//	{
//		cin >> num;
//		ListNode* newNode = (ListNode*)malloc(sizeof(ListNode*));
//		newNode->val = num;
//		cur1->next = newNode;
//		cur1 = cur1->next;
//		if (cin.get() == '\n')
//		{
//			break;
//		}
//	}
//	while (1)
//	{
//		cin >> num;
//		ListNode* newNode = (ListNode*)malloc(sizeof(ListNode*));
//		newNode->val = num;
//		cur2->next = newNode;
//		cur2 = cur2->next;
//		if (cin.get() == '\n')
//		{
//			break;
//		}
//	}
//	ListNode* newpHead=mergeTwoLists(pHead1->next, pHead2->next);
//	ListNode* cur = newpHead->next;
//	while (cur)
//	{
//		cout << cur->val;
//		cur = cur->next;
//	}
//	cout << endl;
//	return 0;
//}