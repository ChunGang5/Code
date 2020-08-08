//10：斐波那契数列_非递归求法，O(n)
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

//拓展：青蛙跳台阶问题
//当青蛙第一次跳一节的时候，还要f(n-1)种跳法，第一次条跳2阶时，剩下有f(n-2)种跳法
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

//非递归
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
//		for (int i = 2; i<number; i++)	//注意这个题对应的斐波那契数列是从1开始的，所以i不能=n
//		{
//			jumpN = jumpone + jumptwo;
//			jumpone = jumptwo;
//			jumptwo = jumpN;
//		}
//		return jumpN;
//	}
//};

//04:二维数组中的查找
//class Solution {
//public:
//	//此题只能从左下角或者右上角求解，不然的话就会产生判断的不确定
//	bool Find(int target, vector<vector<int> > array) {
//		int rowCount = array.size();
//		int colCount = array[0].size();
//		int row = 0;
//		int col = colCount - 1;
//		bool found = false;    //标志很重要
//		if (rowCount>0 && colCount>0)    //判断数组是否有效
//		{
//			while (row<rowCount && col >= 0)    //判断数组是否越界
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

//05：替换空格
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
//		//统计字符串个数和空格个数
//		while (str[i] != '\0')
//		{
//			OldLength++;
//			if (str[i] == ' ')
//				NumberBlank++;
//			i++;
//		}
//		int NewLength = OldLength + 2 * NumberBlank;
//		if (NewLength>length)    //length是字符串的容量，如果NewLength>length那么就不能进行替换了，超出容量了
//			return;
//		//开始替换
//		int IndexOld = OldLength;
//		int IndexNew = NewLength;
//		while (IndexOld >= 0 && IndexNew>IndexOld)    //>=0是因为字符串第一个字符下标是0；如果原字符串没有空格
//			//那Indexold==IndexNew就不用处理，更没有<这个情况
//		{
//			if (str[IndexOld] == ' ')
//			{
//				str[IndexNew--] = '0';    //后置--，先用后减
//				str[IndexNew--] = '2';
//				str[IndexNew--] = '%';
//				//IndexOld--;
//			}
//			else
//			{
//				//str[IndexNew--]=str[IndexOld--];
//				str[IndexNew--] = str[IndexOld];
//			}
//			IndexOld--;    //放在这儿改变IndexOld比较方便，因为每次IndexOld都需要向前走一步
//		}
//	}
//};

//06：反向打印链表
//方法一：栈
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
//方法二：递归思路
//class Solution {
//public:
//	vector<int> value;    //数组要在函数外定义，不然就会递归几次生成几个数组
//	vector<int> printListFromTailToHead(ListNode* head)
//	{
//		ListNode* cur = head;
//		if (cur)
//		{
//			if (cur->next)    //检验下一个节点是否为空，这才是递归地条件
//			{
//				printListFromTailToHead(cur->next);
//			}
//			value.push_back(cur->val);
//		}
//		return value;
//	}
//};
//方法三：借助数组
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

//09：用两个栈实现队列
//class Solution
//{
//public:
//	void push(int node)
//	{
//		//直接在push的时候就将数排列处理好，stack2只是一个辅助队列
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
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
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
		if (SubRoot == NULL)    //子树已经没有节点了，比较完了
		{
			return true;
		}
		if (Root == NULL)    //子树没有比较完，但是主树比较完了
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
		if (pRoot1->val == pRoot2->val) //找到起始节点
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
操作给定的二叉树，将其变换为源二叉树的镜像
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
		//交换左右节点
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
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
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
		//考虑到可能全部重复
		ListNode *head = new ListNode(0);
		head->next = pHead;
		ListNode *prev = head;
		ListNode *last = prev->next;
		//这样做虽然代码过去了，但是还存在着内存泄漏
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
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
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
		else    //最小栈元素数应与数据栈元素数一致
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
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1, 2, 3, 4, 5是某栈的压入顺序，序列4, 5, 3, 2, 1是该压栈序列对应的一个弹出序列，
但4, 3, 5, 1, 2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
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
		//如果最后st为空，则弹出顺序是对的
		return st.empty();
	}
};
*/


/*
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes, 否则输出No。
假设输入的数组的任意两个数字都互不相同。
https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&&tqId=11176&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	bool IsSquenceOfBST(vector<int> sequence, int start, int end)
	{
		//找完了或者就剩一个，那个就是根节点
		if (start >= end)
		{
			return true;
		}
		int root = sequence[end];
		int i = 0;
		//划分左子树范围
		for (; i<end; ++i)
		{
			if (sequence[i]>root)
				break;
		}
		int j = i;
		for (; j<end; ++j)
		{
			if (sequence[j]<root)    //左子树里有比根节点大的，或者右子树里有比根节点小的
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
输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
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
		//递归终止条件
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

		//这个root节点遍历完了，就要删除这个节点，回退了
		path.pop_back();
		//不用再减去什么了，因为函数递归回去了，expectNumber是栈上的空间，回调回去就自动释放了
		//用原来的expectNumber,不像result和path
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