//10��쳲���������_�ǵݹ��󷨣�O(n)
//class Solution {
//public:
//	int Fibonacci(int n)
//	{
//		if (n == 0)
//		{
//			return 0;
//		}
//		if (n == 1)
//		{
//			return 1;
//		}
//		long long fibone = 0;
//		long long fibtwo = 1;
//		long long fibn = 0;
//		for (int i = 2; i <= n; i++)
//		{
//			fibn = fibtwo + fibone;
//			fibone = fibtwo;
//			fibtwo = fibn;
//		}
//		return fibn;
//	}
//};

//��չ��������̨������
//�����ܵ�һ����һ�ڵ�ʱ�򣬻�Ҫf(n-1)����������һ������2��ʱ��ʣ����f(n-2)������
//class Solution {
//public:
//	int jumpFloor(int number) {
//		if (number == 1)
//		{
//			return 1;
//		}
//		if (number == 2)
//		{
//			return 2;
//		}
//		else
//		{
//			return jumpFloor(number - 1) + jumpFloor(number - 2);
//		}
//	}
//};

//�ǵݹ�
//class Solution {
//public:
//	int jumpFloor(int number)
//	{
//		if (number == 1)
//		{
//			return 1;
//		}
//		if (number == 2)
//		{
//			return 2;
//		}
//		long long jumpone = 1;
//		long long jumptwo = 2;
//		long long jumpN = 0;
//		for (int i = 2; i<number; i++)	//ע��������Ӧ��쳲����������Ǵ�1��ʼ�ģ�����i����=n
//		{
//			jumpN = jumpone + jumptwo;
//			jumpone = jumptwo;
//			jumptwo = jumpN;
//		}
//		return jumpN;
//	}
//};

//04:��ά�����еĲ���
//class Solution {
//public:
//	//����ֻ�ܴ����½ǻ������Ͻ���⣬��Ȼ�Ļ��ͻ�����жϵĲ�ȷ��
//	bool Find(int target, vector<vector<int> > array) {
//		int rowCount = array.size();
//		int colCount = array[0].size();
//		int row = 0;
//		int col = colCount - 1;
//		bool found = false;    //��־����Ҫ
//		if (rowCount>0 && colCount>0)    //�ж������Ƿ���Ч
//		{
//			while (row<rowCount && col >= 0)    //�ж������Ƿ�Խ��
//			{
//				if (target == array[row][col])
//				{
//					found = true;
//					break;
//				}
//				else if (target < array[row][col])
//				{
//					--col;
//				}
//				else
//					++row;
//			}
//		}
//		return found;
//	}
//};

//05���滻�ո�
//class Solution {
//public:
//	void replaceSpace(char *str, int length)
//	{
//		if (NULL == str || length <= 0)
//		{
//			return;
//		}
//		int OldLength = 0;
//		int NumberBlank = 0;
//		int i = 0;
//		//ͳ���ַ��������Ϳո����
//		while (str[i] != '\0')
//		{
//			OldLength++;
//			if (str[i] == ' ')
//				NumberBlank++;
//			i++;
//		}
//		int NewLength = OldLength + 2 * NumberBlank;
//		if (NewLength>length)    //length���ַ��������������NewLength>length��ô�Ͳ��ܽ����滻�ˣ�����������
//			return;
//		//��ʼ�滻
//		int IndexOld = OldLength;
//		int IndexNew = NewLength;
//		while (IndexOld >= 0 && IndexNew>IndexOld)    //>=0����Ϊ�ַ�����һ���ַ��±���0�����ԭ�ַ���û�пո�
//			//��Indexold==IndexNew�Ͳ��ô�����û��<������
//		{
//			if (str[IndexOld] == ' ')
//			{
//				str[IndexNew--] = '0';    //����--�����ú��
//				str[IndexNew--] = '2';
//				str[IndexNew--] = '%';
//				//IndexOld--;
//			}
//			else
//			{
//				//str[IndexNew--]=str[IndexOld--];
//				str[IndexNew--] = str[IndexOld];
//			}
//			IndexOld--;    //��������ı�IndexOld�ȽϷ��㣬��Ϊÿ��IndexOld����Ҫ��ǰ��һ��
//		}
//	}
//};

//06�������ӡ����
//����һ��ջ
//class Solution {
//public:
//	vector<int> printListFromTailToHead(ListNode* head)
//	{
//		vector<int> value;
//		std::stack<ListNode*> nodes;
//		ListNode* cur = head;
//		while (cur)
//		{
//			nodes.push(cur);
//			cur = cur->next;
//		}
//		while (!nodes.empty())
//		{
//			cur = nodes.top();
//			value.push_back(cur->val);
//			nodes.pop();
//		}
//		return value;
//	}
//};
//���������ݹ�˼·
//class Solution {
//public:
//	vector<int> value;    //����Ҫ�ں����ⶨ�壬��Ȼ�ͻ�ݹ鼸�����ɼ�������
//	vector<int> printListFromTailToHead(ListNode* head)
//	{
//		ListNode* cur = head;
//		if (cur)
//		{
//			if (cur->next)    //������һ���ڵ��Ƿ�Ϊ�գ�����ǵݹ������
//			{
//				printListFromTailToHead(cur->next);
//			}
//			value.push_back(cur->val);
//		}
//		return value;
//	}
//};
//����������������
//class Solution {
//public:
//
//	vector<int> printListFromTailToHead(ListNode* head)
//	{
//		vector<int> value;
//		ListNode* cur = head;
//		while (cur)
//		{
//			value.push_back(cur->val);
//			cur = cur->next;
//		}
//		reverse(value.begin(), value.end());
//		return value;
//	}
//};

//09��������ջʵ�ֶ���
//class Solution
//{
//public:
//	void push(int node)
//	{
//		//ֱ����push��ʱ��ͽ������д���ã�stack2ֻ��һ����������
//		while (!stack1.empty())
//		{
//			stack2.push(stack1.top());
//			stack1.pop();
//		}
//		stack2.push(node);
//		while (!stack2.empty())
//		{
//			stack1.push(stack2.top());
//			stack2.pop();
//		}
//	}
//
//	int pop()
//	{
//		int value = stack1.top();
//		stack1.pop();
//		return value;
//	}
//
//private:
//	stack<int> stack1;
//	stack<int> stack2;
//};

#include<iostream>
#include<map>
#include<vector>
using namespace std;
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers)
//	{
//		if (0 == numbers.size())
//		{
//			return 0;
//		}
//		int result = numbers[0];
//		int times = 1;
//		for (int i = 1; i<numbers.size(); i++)
//		{
//			if (times == 0)
//			{
//				result = numbers[i];
//				times++;
//			}
//			else if (result == numbers[i])
//			{
//				times++;
//			}
//			else
//			{
//				times--;
//			}
//		}
//		int count = 0;
//		for (int i = 0; i<numbers.size(); i++)
//		{
//			if (result == numbers[i])
//				count++;
//		}
//		return count>numbers.size() / 2 ? result : 0;
//	}
//};
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers)
//	{
//		map<int, int>mp;
//		int sz = numbers.size();
//		for (int i = 0; i<sz; i++)
//		{
//			if (mp.find(numbers[i]) == mp.end())
//			{
//				mp.insert(make_pair(numbers[i], 1));
//			}
//			else
//			{
//				mp[numbers[i]]++;
//			}
//			if (mp[numbers[i]]>(sz / 2))
//			{
//				return numbers[i];
//			}
//		}
//		return 0;
//	};
//#include<algorithm>
//int main()
//{
//	vector<int> numbers{ 1, 2, 3, 2, 2, 2, 5, 4, 2 };
//	sort(numbers.begin(), numbers.end());
//	int len = numbers.size();
//	int targer = numbers[len / 2];
//	int sz = 0;
//	for (int i = 0; i<len; i++)
//	{
//		int ret = numbers[i];
//		if (numbers[i] == targer);
//		{
//			sz++;
//		}
//	}
//	if (sz>(len / 2))
//	{
//		cout<< targer<<endl;
//	}
//	cin.get();
//	cout << 0 << endl;
//	return 0;
//}


/*class Solution {
public:
int MoreThanHalfNum_Solution(vector<int> numbers)
{
unordered_map<int,int> map;
int half=numbers.size()/2;
for(int i=0;i<numbers.size();i++)
{
auto it=map.find(numbers[i]);
if(it!=map.end())
{
map[numbers[i]]++;
}
else
{
map.insert(make_pair(numbers[i],1));
}
if(map[numbers[i]]>half)
{
return numbers[i];
}
}
return 0;
}
};*/

/*class Solution {
public:
int MoreThanHalfNum_Solution(vector<int> numbers)
{
sort(numbers.begin(),numbers.end());
int targer=numbers[numbers.size()/2];
int count=0;
for(int i=0;i<numbers.size();i++)
{
if(numbers[i]==targer)
{
count++;
}
}
if(count>numbers.size()/2)
{
return targer;
}
return 0;
}
};*/

//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers)
//	{
//		if (0 == numbers.size())
//		{
//			return 0;
//		}
//		int result = numbers[0];
//		int times = 1;
//		for (int i = 1; i<numbers.size(); i++)
//		{
//			if (times == 0)
//			{
//				result = numbers[i];
//				times++;
//			}
//			else if (result == numbers[i])
//			{
//				times++;
//			}
//			else
//			{
//				times--;
//			}
//		}
//		int count = 0;
//		for (int i = 0; i<numbers.size(); i++)
//		{
//			if (result == numbers[i])
//				count++;
//		}
//		return count>numbers.size() / 2 ? result : 0;
//	}
//}





/*
�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&&tqId=11170&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
class Solution {
public:
	bool IsSubTree(TreeNode *Root, TreeNode *SubRoot)
	{
		if (SubRoot == NULL)    //�����Ѿ�û�нڵ��ˣ��Ƚ�����
		{
			return true;
		}
		if (Root == NULL)    //����û�бȽ��꣬���������Ƚ�����
		{
			return false;
		}
		if (Root->val != SubRoot->val)
		{
			return false;
		}
		return IsSubTree(Root->left, SubRoot->left) && IsSubTree(Root->right, SubRoot->right);
	}
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == NULL || pRoot2 == NULL)
		{
			return false;
		}
		bool result = false;
		if (pRoot1->val == pRoot2->val) //�ҵ���ʼ�ڵ�
		{
			result = IsSubTree(pRoot1, pRoot2);
		}
		if (!result)
		{
			result = HasSubtree(pRoot1->left, pRoot2);
		}
		if (!result)
		{
			result = HasSubtree(pRoot1->right, pRoot2);
		}
		return result;
	}
};*/


/*
���������Ķ�����������任ΪԴ�������ľ���
https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&&tqId=11171&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
class Solution {
public:
	void Mirror(TreeNode *pRoot)
	{
		if (pRoot == NULL)
			return;
		if (pRoot->left == NULL&&pRoot->right == NULL)
		{
			return;
		}
		//�������ҽڵ�
		TreeNode *pTemp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = pTemp;
		if (pRoot->left)
		{
			Mirror(pRoot->left);
		}
		if (pRoot->right)
		{
			Mirror(pRoot->right);
		}
	}
};*/

/*
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
		{
			return pHead;
		}
		//���ǵ�����ȫ���ظ�
		ListNode *head = new ListNode(0);
		head->next = pHead;
		ListNode *prev = head;
		ListNode *last = prev->next;
		//��������Ȼ�����ȥ�ˣ����ǻ��������ڴ�й©
		while (last != NULL)
		{
			while (last->next != NULL&& last->val != last->next->val)
			{
				prev = prev->next;
				last = last->next;
			}
			while (last->next != NULL&&last->val == last->next->val)
			{
				last = last->next;
			}
			if (prev->next != last)
			{
				prev->next = last->next;
			}
			last = last->next;
		}
		return head->next;
	}
};
*/

/*
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&&tqId=11173&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	void push(int value)
	{
		DataStack.push(value);
		if (MinStack.size() == 0 || value<MinStack.top())
		{
			MinStack.push(value);
		}
		else    //��СջԪ����Ӧ������ջԪ����һ��
		{
			MinStack.push(MinStack.top());
		}
	}
	void pop()
	{
		if (DataStack.size()>0 && MinStack.size()>0)
		{
			DataStack.pop();
			MinStack.pop();
		}
	}
	int top()
	{
		return DataStack.top();
	}
	int min()
	{
		return MinStack.top();
	}
private:
	stack<int> MinStack;
	stack<int> DataStack;
};
*/


/*
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ���������1, 2, 3, 4, 5��ĳջ��ѹ��˳������4, 5, 3, 2, 1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
��4, 3, 5, 1, 2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		if (pushV.size() == 0 || popV.size() == 0 || pushV.size() != popV.size())
		{
			return false;
		}
		stack<int> st;
		int PushIndex = 0;
		int PopIndex = 0;
		while (PushIndex<pushV.size())
		{
			st.push(pushV[PushIndex]);
			while (!st.empty() && st.top() == popV[PopIndex])
			{
				st.pop();
				++PopIndex;
			}
			++PushIndex;
		}
		//������stΪ�գ��򵯳�˳���ǶԵ�
		return st.empty();
	}
};
*/


/*
�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��
https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?tpId=13&&tqId=11175&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root)
	{
		vector<int> result;
		if (root == NULL)
		{
			return result;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode *tmp = q.front();
			q.pop();
			result.push_back(tmp->val);
			if (tmp->left)
			{
				q.push(tmp->left);
			}
			if (tmp->right)
			{
				q.push(tmp->right);
			}
		}
		return result;
	}
};
*/

/*
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes, �������No��
�������������������������ֶ�������ͬ��
https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&&tqId=11176&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	bool IsSquenceOfBST(vector<int> sequence, int start, int end)
	{
		//�����˻��߾�ʣһ�����Ǹ����Ǹ��ڵ�
		if (start >= end)
		{
			return true;
		}
		int root = sequence[end];
		int i = 0;
		//������������Χ
		for (; i<end; ++i)
		{
			if (sequence[i]>root)
				break;
		}
		int j = i;
		for (; j<end; ++j)
		{
			if (sequence[j]<root)    //���������бȸ��ڵ��ģ��������������бȸ��ڵ�С��
				return false;
		}
		return IsSquenceOfBST(sequence, 0, i - 1) && IsSquenceOfBST(sequence, i, end - 1);
	}
	bool VerifySquenceOfBST(vector<int> sequence)
	{
		if (sequence.empty())
		{
			return false;
		}
		return IsSquenceOfBST(sequence, 0, sequence.size() - 1);
	}
};
*/



/*
����һ�Ŷ������ĸ��ڵ��һ�����������ֵ����ӡ���������н��ֵ�ĺ�Ϊ��������������·����·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&&tqId=11177&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
class Solution {
public:
	void DFSFindPath(TreeNode *root, int expectNumber, vector<vector<int>> &result, vector<int> &path)
	{
		//�ݹ���ֹ����
		if (root == NULL)
		{
			return;
		}
		path.push_back(root->val);
		expectNumber -= root->val;
		if (root->left == NULL && root->right == NULL && expectNumber == 0)
		{
			result.push_back(path);
		}
		DFSFindPath(root->left, expectNumber, result, path);
		DFSFindPath(root->right, expectNumber, result, path);

		//���root�ڵ�������ˣ���Ҫɾ������ڵ㣬������
		path.pop_back();
		//�����ټ�ȥʲô�ˣ���Ϊ�����ݹ��ȥ�ˣ�expectNumber��ջ�ϵĿռ䣬�ص���ȥ���Զ��ͷ���
		//��ԭ����expectNumber,����result��path
	}
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber)
	{
		vector<vector<int>> result;
		vector<int> path;
		DFSFindPath(root, expectNumber, result, path);
		return result;
	}
};
*/


/*
����һ���ַ���, ���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc, 
���ֵ����ӡ�����ַ�a, b, c�������г����������ַ���abc, acb, bac, bca, cab��cba��
https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&&tqId=11180&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	void Swap(string &str, int i, int j)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	void PermutetationHelper(string &str, int start, vector<string> &result)
	{
		//����
		if (start == str.length() - 1)
		{//��ȥ��
			bool flag = false;
			auto it = result.begin();
			for (; it != result.end(); ++it)
			{
				if (*it == str)
				{
					flag = true;
				}
			}
			if (flag == false)
			{
				result.push_back(str);
			}
			return;
		}
		//start����ͷ��λ�õ�Ԫ�أ���i�ı仯���ı�startλ��Ԫ��
		for (int i = start; i<str.size(); i++)
		{
			Swap(str, start, i);
			PermutetationHelper(str, start + 1, result);
			Swap(str, start, i);
		}
	}
	vector<string> Permutation(string str)
	{
		vector<string> result;
		if (str.empty())
		{
			return result;
		}
		PermutetationHelper(str, 0, result);
		//sortĬ��ΪASCIIֵ������Ϊ����Ҫ���ֵ����ӡ����������
		sort(result.begin(), result.end());
		return result;
	}
};
*/


/*
����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4��
https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&&tqId=11182&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
�ⷨһ��ֱ������ʱ�临�ӶȱȽϸ��ӿ��żӣ�
class Solution {
public:
vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
vector<int> result;
if(input.empty()||input.size()<k)
{
return result;
}
sort(input.begin(),input.end());
for(auto i=0;i<k;i++)
{
result.push_back(input[i]);
}
return result;
}
};
//�ⷨ����
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
	{
		vector<int> result;
		if (k<1 || input.empty() || input.size()<k)
		{
			return result;
		}
		//Ĭ�ϴ�ѣ�С�ѵĻ�Ҫ����greater
		priority_queue<int, vector<int>> q;
		for (int i = 0; i<input.size(); ++i)
		{
			if (i<k)
			{
				q.push(input[i]);
			}
			else
			{
				if (input[i]<q.top())
				{
					q.pop();
					q.push(input[i]);
				}
			}
		}
		for (int i = 0; i<k; i++)
		{
			result.push_back(q.top());
			q.pop();
		}
		return result;
	}
};
*/

#include<iostream>
using namespace std;
//class Solution {
//public:
//	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2)
//	{
//		if (data.size() == 0 || num1 == NULL || num2 == NULL)
//		{
//			return;
//		}
//		//1.�������
//		int result = data[0];
//		for (auto i = 1; i<data.size(); ++i)
//		{
//			result ^= data[i];
//		}
//		if (result == 0)
//			return;
//		//2���ҵ���ĳһ��λΪ1��λ��λ�ã���Ϳ��Խ����ݷֳ�������
//		int flag = 1;
//		int len = sizeof(int)* 8;
//		for (int i = 0; i<len; i++)
//		{
//			//��&������
//			if ((flag << i)&result)
//			{
//				flag <<= i;
//				break;
//			}
//		}
//		//3�����ҵ���Ϊ1�ı���λ���л��֣����ܰ�����ֻ����һ�ε����ַ�Ϊ����
//		int a=*num1 = 0;
//		int b=*num2 = 0;
//		for (int i = 0; i<data.size(); ++i)
//		{
//			if (data[i] & flag)
//			{
//				*num1 ^= data[i];
//			}
//			else
//			{
//				*num2 ^= data[i];
//			}
//		}
//	}
//};


/*
//���������ֱ����ķǵݹ�д��
//ǰ��
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> result;
		if (root == NULL)
		{
			return result;
		}
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty())
		{
			TreeNode* cur = st.top();
			result.push_back(cur->val);
			st.pop();
			if (cur->right)
				st.push(cur->right);
			if (cur->left)
				st.push(cur->left);
		}
		return result;
	}
};
//����
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> result;
		if (root == NULL)
			return result;
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty())
		{
			TreeNode* cur = st.top();
			st.pop();
			if (cur != NULL)
			{
				if (cur->right)
					st.push(cur->right);
				st.push(cur);
				st.push(NULL);
				if (cur->left)
					st.push(cur->left);
			}
			else
			{
				result.push_back(st.top()->val);
				st.pop();
			}
		}
		return result;
	}
};
//����
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int> result;
		if (root == NULL)
		{
			return result;
		}
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty())
		{
			TreeNode* cur = st.top();
			st.pop();
			if (cur != NULL)
			{   //��NULLΪ�жϸ��ڵ������
				st.push(cur);
				st.push(NULL);
				if (cur->right)
					st.push(cur->right);
				if (cur->left)
					st.push(cur->left);
			}
			else
			{
				result.push_back(st.top()->val);
				st.pop();
			}
		}
		return result;
	}
};
*/


