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
//#include<stdlib.h>
//#include<stdio.h>
//#include<string.h>
//
//void getmemory(char*& p)
//{
//	p = (char*)malloc(100);
//}
//void test()
//{
//	char *str = NULL;
//	getmemory(str);
//	strcpy(str, "hello wordle!");
//	printf("%s\n", str);
//}
//int main()
//{
//	test();
//	return 0;
//}
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


//#include<unordered_map>
//class Solution {
//public:
//	/**
//	*
//	* @param values string字符串二维数组
//	* @param valuesRowLen int values数组行数
//	* @param valuesColLen int* values数组列数
//	* @return string字符串vector
//	*/
//	vector<string> findCommonString(string** values, int valuesRowLen, int* valuesColLen)
//	{
//		vector<string> result;
//		if (valuesRowLen == 0)
//		{
//			return result;
//		}
//		unordered_map<string, int> Map;
//		for (int i = 0; i < valuesRowLen; ++i)
//		{
//			for (int j = 0; j < valuesColLen[i]; ++j)
//			{
//				if (Map.find(values[i][j]) == Map.end())
//				{
//					Map.insert({ values[i][j], 1 });
//				}
//				else
//				{
//					++Map[values[i][j]];
//				}
//			}
//		}
//		
//		auto it = Map.begin();
//		while (it != Map.end())
//		{
//			string str;
//			if ((*it).second == valuesRowLen)
//			{
//				str = (*it).first;
//				result.push_back(str);
//			}
//			it++;
//		}
//		return result;
//	}
//};
//
//
//int main()
//{
//	unordered_map<int, int> mp;
//	for (int i = 0; i < 10; ++i)
//	{
//		if (mp.find(i) != mp.end())
//		{
//
//		}
//	}
//}





//#include <stdio.h>
//int Month1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//int Month2[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//bool isR(int year){
//	if (year % 4 == 0 && year % 100 != 0){
//		return true;
//	}
//	else if (year % 400 == 0){
//		return true;
//	}
//	else{
//		return false;
//	}
//}
//int main(){
//	int y1, y2, m1, m2, d1, d2;
//	int day = 0;
//	long long data = 20190205;
//	long long temp;
//	scanf("%lld", &temp);
//	y1 = data / 10000;
//	y2 = temp / 10000;
//	m1 = data / 100 % 100;
//	m2 = temp / 100 % 100;
//	d1 = data % 100;
//	d2 = temp % 100;
//	if (y2 - y1 == 0 && m2 - m1 == 0){
//		day = d2 - d1;
//	}
//	else if (y2 - y1 == 0 && m2 - m1>0){
//		day = Month1[m1 - 1] - d1;
//		day += d2;
//		for (int i = m1; i<m2 - 1; i++){
//			day += Month1[i];
//		}
//	}
//	else if (y2 - y1 == 0 && m2 - m1<0){
//		day = Month1[m2 - 1] - d2;
//		day += d1;
//		for (int i = m2; i<m1 - 1; i++){
//			day += Month1[i];
//		}
//	}
//	else if (y2 - y1>0){
//		day += Month1[m1 - 1] - d1;
//		for (int i = m1; i<12; i++){
//			day += Month1[i];
//		}
//		if (isR(y2) == true){
//			day += d2;
//			for (int i = 0; i<m2 - 1; i++){
//				day += Month2[i];
//			}
//		}
//		else{
//			day += d2;
//			for (int i = 0; i<m2 - 1; i++){
//				day += Month1[i];
//			}
//		}
//		for (int i = y1 + 1; i<y2; i++){
//			if (isR(i) == true){
//				day += 366;
//			}
//			else{
//				day += 365;
//			}
//		}
//	}
//	else if (y2 - y1<0){
//		if (isR(y2) == true){
//			day += Month2[m2 - 1] - d2;
//			for (int i = m2; i<12; i++){
//				day += Month2[i];
//			}
//		}
//		else{
//			day += Month1[m2 - 1] - d2;
//			for (int i = m2; i<12; i++){
//				day += Month1[i];
//			}
//		}
//		day += d1;
//		for (int i = 0; i<m1 - 1; i++){
//			day += Month1[i];
//		}
//		for (int i = y2 + 1; i<y1; i++){
//			if (isR(i) == true){
//				day += 366;
//			}
//			else{
//				day += 365;
//			}
//		}
//	}
//	//输出日期是周几
//	int dayofweek(int y, int m, int d)  /* 0 = Sunday */
//	{
//		static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
//		y -= m < 3;
//		return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
//	}
//	int week = dayofweek(y1, m1, d1);
//	void IsPeixunDay(int y1, int m1, int d1, int y2, int m2, int d2, int day,int beginweek)
//	{
//		if (y1 - y2 == 0 && m1 - m2 = 0)
//		{
//
//		}
//	}
//
//
//	printf("%d\n", day);
//	return 0;
//}


//#include<iostream>
//#include<map>
//#include<vector>
//using namespace std;
//int main()
//{
//	vector<int> nums;
//	int num;
//	while (1)
//	{
//		cin >> num;
//		nums.push_back(num);
//		if (cin.get() == '\n')
//		{
//			break;
//		}
//	}
//	int k = 0;
//	cin >> k;
//	map<int, int> Map;
//	for (int i = 0; i < nums.size(); ++i)
//	{
//		
//		if (Map.find(nums[i]) == Map.end())
//		{
//			Map.insert({nums[i], 1 });
//		}
//		else
//		{
//			++Map[nums[i]];
//		}
//	}
//	multimap<int, int> muMap;
//	auto it = Map.begin();
//	while (it != Map.end())
//	{
//			muMap.insert({ (*it).second, (*it).first });
//			it++;
//	}
//	auto it2 = muMap.begin;
//	while (k--)
//	{
//		cout << (*it).second;
//		it2++;
//	}
//	cout << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	int n = 0;
//	cin >> n;
//
//	return 0;
//}
//
//#include <iostream>
//using namespace std;
//
//int main() {
//	int n = 0, i = 0, j = 0;
//	cin >> n;
//	i = n - 1;
//	j = 1;
//	while (i >= 0 && j <= 2 * n - 1)
//	{
//		int w = i;
//		int t = j;
//		for (i = w; i > 0; i--)
//			cout << ' ';
//		for (j = 1; j <= 2 * t - 1; j++)
//			cout << '*';
//		for (i = w; i > 0; i--)
//			cout << ' ';
//		i = w;
//		j = t;
//		i--; j++;
//		cout << endl;
//	}
//	i = 1;
//	j = n - 1;
//	while (i >= 0 && j >= 1)
//	{
//		int w = i;
//		int t = j;
//		for (i = w; i > 0; i--)
//			cout << ' ';
//		for (j = 1; j <= 2 * t - 1; j++)
//			cout << '*';
//		for (i = w; i > 0; i--)
//			cout << ' ';
//		i = w;
//		j = t;
//		i++; j--;
//		cout << endl;
//	}
//	cout << endl;
//	return 0;
//}

//void PrintfVector(vector<vector<int>>& matrix, int rows, int cols,int start, vector<int>& result)
//{
//	int xend = rows - start ;
//	int yend = cols - start ;
//	for (int i = start; i < xend; ++i)
//	{
//		result.push_back(matrix[start][i]);
//	}
//	//检测数组是否只有一行
//	if (start < yend - 1)
//	{
//		for (int i = start + 1; i < yend; ++i)
//		{
//			result.push_back(matrix[i][xend - 1]);
//		}
//	}
//	//检测二维数组是否只有一行两列
//	if (start<xend - 1 && start<yend - 1)
//	{
//		for (int i = yend - 1; i > start; --i)
//		{
//			result.push_back(matrix[yend - 1][i]);
//		}
//	}
//	if (start < xend - 1 && start<yend - 2)
//	{
//		for (int i = yend - 1; i > start; --i)
//		{
//			result.push_back(matrix[i][start]);
//		}
//	}	
//}
//vector<int> SpiralMatrix(vector<vector<int> >& matrix)
//{
//	vector<int> result;
//	if (matrix.empty())
//	{
//		return result;
//	}
//	int rows = matrix.size();
//	int cols = matrix[0].size();
//	//设一个每次打印的开始点,第一次从[0,0]开始
//	int start = 0;
//	while (rows > start * 2 && cols > start * 2)
//	{
//		PrintfVector(matrix, rows, cols, start, result);
//		++start;
//	}
//	return result;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n = 0;
//	int m = 0;
//	cin >> n;
//	vector<int> v1;
//	vector<int> v2;
//	vector<int> result;
//	while (1)
//	{
//		int num = 0;
//		cin >> num;
//		v1.push_back(num);
//		if (cin.get() == '\n')
//		{
//			break;
//		}
//	}
//	cin >> m;
//	while (1)
//	{
//		int num = 0;
//		cin >> num;
//		v2.push_back(num);
//		if (cin.get() == '\n')
//		{
//			break;
//		}
//	}
//	auto it1 = v1.begin();
//	auto it2 = v2.begin();
//	while (it1 != v1.end())
//	{
//		while (it2 != v2.end())
//		{
//			if ((*it1) == (*it2))
//			{
//				result.push_back(*it1);
//				break;
//			}
//			it2++;
//		}
//		it1++;
//		it2 = v2.begin();
//	}
//	auto it = result.begin();
//	while (it != result.end())
//	{
//		cout << *it++ << " ";
//	}
//	cout << endl;
//	return 0;
//}


//#include<iostream>
//#include<map>
//using namespace std;
//bool check(string& str)
//{
//	bool flag=true;
//	int i = 0;
//	while (str[i])
//	{
//		if (!isdigit(str[i++]))
//		{
//			flag = false;
//		}
//	}
//	return flag;
//}


//int main()
//{
//	int n = 0, k = 0;
//	int num;
//	cin >> n >> k;
//	num = k;
//	cin.get();
//	if ((n<1 && n>100000) || (k<1 && k>100000))
//	{
//		return 0;
//	}
//	map<string, int> Smap;
//	while (n--)
//	{
//		string str;
//		getline(cin, str);
//		if (check(str))
//		{
//			if (Smap.find(str) == Smap.end())
//			{
//				Smap.insert({ str, 1 });
//			}
//			else
//			{
//				Smap[str]++;
//			}
//		}
//	}
//	
//	multimap<int, string> swapmap;
//	auto it = Smap.begin();
//	while (it != Smap.end())
//	{
//		swapmap.insert({ (*it).second, (*it).first });
//		it++;
//	}
//	auto s_it = swapmap.begin();
//	while (k--)
//	{
//		if (s_it != swapmap.end())
//		{
//			cout << (*s_it).second << " " << (*s_it).first << endl;
//		}
//		s_it++;
//	}
//	auto s_e_it = swapmap.end();
//	k = num;
//	while (k--)
//	{
//		s_e_it--;
//	}
//	multimap<int, string> s_e_map;
//	k = num;
//	while (k--)
//	{
//		s_e_map.insert(make_pair((*s_e_it).first, (*s_e_it).second));
//		s_e_it++;
//	}
//	auto _it = s_e_map.begin();
//	while (_it!=s_e_map.end())
//	{
//		cout << (*_it).second << " " << (*_it).first << endl;
//		_it++;
//	}
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n = 0;
//	int m = 0;
//	cin >> n;
//	vector<int> v1;
//	vector<int> v2;
//	vector<int> result;
//	while (1)
//	{
//		int num = 0;
//		cin >> num;
//		v1.push_back(num);
//		if (cin.get() == '\n')
//		{
//			break;
//		}
//	}
//	cin >> m;
//	while (1)
//	{
//		int num = 0;
//		cin >> num;
//		v2.push_back(num);
//		if (cin.get() == '\n')
//		{
//			break;
//		}
//	}
	//if ((n<1 && n>100000) || (m<1 && m>100000))
	//{
	//	return 0;
	//}
//	auto it1 = v1.begin();
//	auto it2 = v2.begin();
//	while (it1 != v1.end() && it2 != v2.end())
//	{
//		if ((*it1) > (*it2))
//		{
//			it1++;
//		}
//		if ((*it1) < (*it2))
//		{
//			it2++;
//		}
//		else
//		{
//			result.push_back((*it1));
//			++it1;
//			++it2;
//		}
//	}
//	auto _it = result.begin();
//	while (_it != result.end())
//	{
//		cout << *_it++ << " ";
//	}
//	cout << endl;
//	return 0;
//}

//
//class Car
//{
//public:
//	virtual void Drive();
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//void Test()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//}
//int main()
//{
//	Test();
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//int Check(string str)
//{
//	int length = str.size();
//	if (length<8 || length>120)
//	{
//		return 1;
//	}
//	bool IsNumber = false;
//	bool IsUpperLetter = false;
//	bool IsLessLetter = false;
//	bool IsOther = false;
//	for (int i = 0; i < length; ++i)
//	{
//		if ('0' <= str[i]&& str[i] <= '9')
//		{
//			IsNumber = true;
//		}
//		else if (str[i]>='A' && str[i]= 'Z')
//		{
//			IsUpperLetter = true;
//		}
//		else if ('a' <= str[i]&&str[i] <= 'z')
//		{
//			IsLessLetter = true;
//		}
//		else 
//		{
//			IsOther = true;
//		}
//	}
//	if (IsNumber&&IsUpperLetter&&IsLessLetter&&IsOther)
//	{
//		return 0;
//	}
//	return 2;
//}
//int main()
//{
//	string str;
//	getline(cin, str);
//	string str_n;
//	int result = -1;
//	for (int i = 0; i < str.size(); ++i)
//	{
//		str_n.push_back(str[i]);
//		if (str[i] == ' ')
//		{
//			str_n.pop_back();
//			str_n.push_back('\n');
//			result = Check(str_n);
//			cout << result << endl;
//			str_n.clear();
//		}
//	}
//	str_n.push_back('\n');
//	result = Check(str_n);
//	cout << result << endl;
//	return 0;
//}




/*
#include<iostream>
#include<vector>
#include<math
using namespace std;
int NumBirSerTree(int n)
{
	if (n<1)
	{
		return 0;
	}
	vector<int> dp(n + 1, -1);
	dp[0] = 1;
	dp[1] = 1;
	int i, j;
	for (i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + pow(3, (i-1));
	}
	return dp[n];
}
int main()
{
	int n = 0;
	cin >> n;
	int result = NumBirSerTree(n);
	cout << result << endl;
	return 0;
}
*/

//#include<iostream>
//#include<string>
//#include<math.h>
//#include<unordered_map>
//using namespace std;
//int main()
//{
//	string str;
//	unordered_map<char, int> Map = { { '0', 0 }, { '1', 1 }, { '2', 2 }, { '3', 3 }, { '4', 4 }, { '5', 5 }, { '6', 6 }, { '7', 7 }, { '8', 8 },
//	{ '9', 9 }, { 'a', 10 }, { 'b', 11 }, { 'c', 12 }, { 'd', 13 }, { 'e', 14 }, { 'f', 15 }, { 'g', 16 }, { 'h', 17 }, { 'i', 18 }, { 'j', 19 }, 
//	{ 'k', 20 },{ 'l', 21 }, { 'm', 22 }, { 'n', 23 }, { 'o', 24 }, { 'p', 25 }, { 'q', 26 }, { 'r', 27 }, { 's', 28 }, { 't', 29 }, { 'u', 30 }, { 'v', 31 }, 
//	{ 'w', 32 }, { 'x', 33 }, { 'y', 34 }, { 'z', 35 } };
//	getline(cin, str);
//	int index = str.size()-1;
//	long ans = 0;
//	int i = 0;
//	while (index > 0)
//	{
//		if (Map.find(str[index]) != Map.end())
//		{
//			ans += Map[str[index]]*pow(36,i);
//		}
//		++i;
//	}
//	cout << ans << endl;
//	return 0;
//}

/*
typedef struct Node
{
	int data;
	Node *next;
} Node;
//写一个c函数将链表（如head->1->2->3->4）逆序

Node* ReverseList(Node* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	stack<Node*> st;
	Node* cur = head->next;
	while (cur)
	{
		st.push(cur);
		cur = cur->next;
	}
	Node* pre = head;
	head ->next= pre;
	while (!st.empty())
	{
		cur = st.top();
		st.pop();
		pre = cur;
		pre = pre->next;
	}
	pre = NULL;
	return head;


	Node* pre = NULL;
	Node* cur = head->next;
	Node* next = NULL;
	while (cur)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}
*/
//void insertSort(int array[], int size)
//{
//	int left = 0;
//	int right = left+1;
//	int temp = 0;
//	while (right<size)
//	{
//		int i = 0;
//		while (i <= left)
//		{
//			if (array[i]<= array[right])
//			{
//				++i;
//			}
//		}
//		temp = array[i];
//		array[i] = array[right];
//		array[right] = temp;
//		++left;
//		++right;
//	}
//}

/*
#include<iostream>
#include<stack>
using namespace std;
int main()
{
	string s1 = "abcde";
	string s2;
	if (true)
	{
		string s3 = "aawd";
		s2 = s3;
	}
	cout << s2;
	cin.get();
	#define max 45
	max = 32;
	int x = 1, y = 0, z = 5;
	int a = (x&&y) || z++;
	cout << z << endl;
	cin.get();
	return 0;
}

*/


/*
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n = -1;
	string str;
	cin >> n;
	cin.get();
	getline(cin, str);
	int begin = 0;
	int end = n;
	while (begin < str.size()&&end<str.size())
	{
		reverse(str.begin()+begin, str.begin()+end);
		begin += n;
		end += n;
	}
	reverse(str.begin() + begin, str.end());
	cout << str << endl;
	return 0;
}
*/

/*
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int T = -1;
	cin >> T;
	cin.get();
	while (T--)
	{
		int n;
		int m;
		int k;
		cin >> n >> m >> k;
		vector<int> v1;
		vector<vector<int>> v(m, vector<int>(3));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cin >> v[i][j];
			}
		}
		for (int i = 0; i < m; ++i)
		{
			if (v[i][2] <= k)
			{
				v1.push_back(v[i][0]);
				v1.push_back(v[i][1]);
			}
		}
		sort(v1.begin(), v1.end());
		if (v1.size()>1)
		{
			for (int i = 0; i < v1.size()-1; ++i)
			{
				if (v1[i] == v1[i + 1])
				{
					v1.erase(v1.begin() + i + 1);
					i--;
				}
			}
		}
		if (v1.size() != n)
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
	}
	return 0;
}
*/


/*
#include<string>
#include<iostream>
#include<vector>
#include <limits>
using namespace std;
int OneNum(int num)
{
	int count = 0;
	while (num)
	{
		count += 1;
		num &= (num - 1);
	}
	return count;
}

vector < int > findNumber(int num)
{
	vector<int> result(0);
	int MinNum = 0;
	int MaxNum = num;
	MinNum = num;
	int count = OneNum(num);
	bool flag = false;
	while (++MaxNum)
	{
		if ((1 <= MaxNum <= 2147483647))
		{
			if (count == (OneNum(MaxNum)))
			{
				flag = true;
				break;
			}
		}
		else
		{
			result.push_back(-1);
			return result;
		}
	}
	if (flag)
	{
		result.push_back(MaxNum);
		flag = false;
	}
	while (--MinNum)
	{
		if (1 <= MinNum <= 2147483647)
		{
			if (count == (OneNum(MinNum)))
			{
				flag = true;
				break;
			}
		}
		else
		{
			result.pop_back();
			result.push_back(-1);
			return result;
		}
	}
	if (flag)
	{
		result.push_back(MinNum);
	}
	return result;
}

int main()
{
	int num = 15;
	int count = 0;
	count = OneNum(num);
	cout << count << endl;
	cin.get();
	return 0;
}
*/

/*
#include<algorithm>


	
	* 找出字符串中最大公共子字符串
	* @param str1 string字符串 输入字符串1
	* @param str2 string字符串 输入字符串2
	* @return string字符串
	
	string GetCommon(string str1, string str2)
	{
		string result;
		if (str1.size() == 0 || str2.size() == 0)
		{
			return result;
		}
		int index = -1;
		int MaxLength = 0;
		for (int i = 0; i<str1.size(); ++i)
		{
			for (int j = 0; j<str2.size(); ++j)
			{
				if (str1[i] == str2[j])
				{
					int n = 1;
					while (str1[i + n] == str2[j + n] && str1[n + i] != '\0')
					{
						n++;
					}
					if (n>MaxLength)
					{
						index = i;
						MaxLength = n;
					}
				}
			}
		}
		if (index == -1)
		{
			return result;
		}
		else
		{
			int i = 0;
			while (MaxLength--)
			{
				result[i++] = str1[index++];
			}
			result.push_back('\0');
			return result;
		}
	}
	int main()
	{
		string s1 = "abccade", str2 = "dgcadde";
		GetCommon(s1, str2);
		cin.get();
		return 0;
	}
	


#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int T = 0;
	cin >> T;
	cin.get();
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> food;
		for (int i = 0; i < n; ++i)
		{
			int num = 0;
			cin >> num;
			food.push_back(num);
		}
		vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
		dp[0][0] = 0;
		for (int i = 0; i <= n; ++i)
		{
			dp[0][i] = 0;
			dp[i][0] = 0;
		}
		int x1, x2;
		for (int i = 0; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (j > i)
				{
					dp[i][j] = dp[i][j - 1];
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + food[i - 1]);
				}
				if (dp[i][j] >= m)
				{
					x1 = i - 1;
					x2 = i;
				}
			}
		}
		if (dp[n][n] < m)
		{
			return -1;
		}
		else
		{
			cout << x1 << x2 << endl;
		}
	}
	return 0;
}


#include<iostream>
using namespace std;
class A
{
public:
	A()
	{
		cout << "A" << endl;
	}
	~A()
	{
		cout << "~A" << endl;
	}
};
class B :public A
{
public:
	B(A &a) 
		:_a(a)
	{
		cout << "B" << endl;
	}
	~B()
	{
		cout << "~B" << endl;
	}
private:
	A _a;
};
int main()
{
	A a;
	B b(a);
	cin.get();
	return 0;
}
*/

/*
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int count = 0;
	auto it1 = s1.begin();
	while (it1 != s1.end())
	{
		auto it2 = s2.begin();
		while (it2 != s2.end())
		{
			if (*it1 == *it2)
			{
				++count;
				it2 = s2.erase(it2);
				break;
			}
			else
			{
				++it2;
			}
		}
		++it1;
	}
	cout << count << endl;
	return 0;
}


#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n = 0;
	cin>>n;
	cin.get();
	while (n--)
	{
		string str;
		getline(cin, str);
		int count = 0;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = i; j < str.size(); j += 3)
			{
				if (str[i] != str[j])
				{
					++count;
					break;
				}
			}
		}
		if (count>1)
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
	}
	return 0;
}


#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string str;
	getline(cin, str);
	if (str.empty())
	{
		cout<<""<<endl;
	}
	int n = str.size();
	int begin = 0;
	int Maxlen = 1;
	vector<vector<bool>> dp(n, vector<bool>(n, false));
	for (int i = 0; i<n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (i - j<2)
			{
				dp[j][i] = (str[j] == str[i]);
			}
			else if (i - j >= 2)
			{
				dp[j][i] = ((str[j] == str[i]) && (dp[j + 1][i - 1]));
			}
			if (dp[j][i] && Maxlen<i - j + 1)
			{
				Maxlen = i - j + 1;
				begin = j;
			}
		}
	}
	cout<< str.substr(begin, Maxlen)<<endl;
	return 0;
}



#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	getline(cin, str);
	int len = str.size();
	string instr;
	string result;
	for (int i = 0; i<len; ++i)
	{
		for (int j = i + 1; j < len; ++j)
		{
			instr = str.substr(i, j);
			if (j == len)
			{
				if (result.size() < instr.size())
				{
					result = instr;
				}
				break;
			}
			else
			{
				if (str.find(instr.substr(j, j + 1)) != string::npos && j<len)
				{
					result = result.size() < instr.size() ? instr : result;
					break;
				}
			}
		}
	}
	cout << result << endl;
	return 0;
}


#include<limits>
#include<stdio.h>
#define SQR(a) a*a

int main()
{
	int MyArray[5] = { 1, 2, 3, 4, 5 };
	for (int &x : MyArray)
	{
		x *= 2;
		printf("%d", x);
	}
	INT_MAX;
	return 0;
}


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string IntToString(int num)
{
	string result;
	while (num)
	{
		int n = num % 10;
		char c = '0' + n;
		num /= 10;
		result.push_back(c);
	}
	return result;
}
int main()
{
	vector<int> nums;
	for (int i = 0; i < 10; ++i)
	{
		int num = 0;
		cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());
	int n = 4;
	auto it = nums.end();
	--it;
	string str;
	while (n--)
	{
		int temp = *it--;
		str += IntToString(temp);
	}
	cout << str << endl;
	return 0;
}
*/

#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	vector<char> array = { 'A', 'A', 'A', 'A', 'B', 'B', 'B','C', 'C', 'D'};
	int num1,num2;
	while (1)
	{
		num1 = rand() % 6 + 1;
		num2 = rand() % 6 + 1;
		if (num1 != num2)
		{
			break;
		}
	}
	cout << array[num1] << array[num2] << endl;
	return 0;
}