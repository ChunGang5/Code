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




#include<algorithm>
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



int main()
{
	int a = 0, b = 0, c = 0;
	while (cin >> a >> b >> c)
	{
		vector<int> result;
		result.push_back(a);
		result.push_back(b);
		result.push_back(c);
		sort(result.begin(), result.end());
		cout << "[" << result[0] << "," << " " << result[1] << "," << " " << result[2] << "]" << endl;
	}
	return 0;
}