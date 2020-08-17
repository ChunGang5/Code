//42：连续子数组最大和
//方法一：动态规划
//动态规划的4个步骤：1、状态
					/*2、状态转移方程
					3、初始值（还要注意边界问题）
					4、返回值
*/
//class Solution {
//public:
//	int FindGreatestSumOfSubArray(vector<int> array)
//	{
//		int len = array.size();
//		//申请一个数组，用以存放，不同长度子串的最大和
//		int *ret = new int[len];
//		ret[0] = array[0];
//		for (int i = 1; i<len; i++)
//		{
//			//状态转移方程：F(i)=max(F(i-1)+array[i],array[i]);
//			ret[i] = max(ret[i - 1] + array[i], array[i]);
//		}
//		int MaxSum = ret[0];
//		for (int i = 1; i<len; i++)
//			MaxSum = max(MaxSum, ret[i]);
//		return MaxSum;
//	}
//};

//普通方法
//class Solution {
//public:
//	int FindGreatestSumOfSubArray(vector<int> array)
//	{
//		int CurSum = array[0];
//		int MaxSum = array[0];
//		int len = array.size();
//		for (int i = 1; i<len; i++)    //控制子串的长度
//		{
//			if (CurSum <= 0)    //标记子串的开始位置
//				CurSum = array[i];
//			else
//				CurSum += array[i];    //更新子串的最大和
//			if (CurSum>MaxSum)
//				MaxSum = CurSum;    //最大子串的最大和
//		}
//		return MaxSum;
//	}
//};



/*在一个二维数组中（每个一维数组的长度相同），
每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/codinginterviews/question-ranking
*/
//class Solution {
//public:
//	bool Find(int target, vector<vector<int> > array)
//	{
//		if (array.empty())
//		{
//			return false;
//		}
//		//从左下角或者右上角解决问题。我们选择从右上角解决问题
//		int row = 0;
//		int col = array[0].size() - 1;
//		//边界条件
//		while (row<array.size() && col >= 0)
//		{
//			if (array[row][col]>target)
//				//array[row][col]是当前行最大的，当前列最小的
//				--col;
//			else if (array[row][col]<target)
//				++row;
//			else
//				return true;
//		}
//		return false;
//	}
//};

/*我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?
tpId = 13 & tqId = 11163 & tPage = 1 & rp = 1 & ru = / ta / coding - interviews&qru = / ta / coding - interviews / questionranking
class Solution {
public:
	int rectCover(int number)
	{
		//设定状态f(n)表示n个方块放的方法
		//2、推导状态转移方程 f(n)=f(n-2)+f(n-1)
		//3、设置边界
		int *dp = new int[number + 1];
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= number; i++)
		{
			dp[i] = dp[i - 2] + dp[i - 1];
		}
		int result = dp[number];
		delete[]dp;
		return result;
	}
};*/

/*
输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示。
https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?
class Solution {
public:
int  NumberOf1(int n)
{
int count=0;
int flag=1;
while(flag)
{
if(n&flag)
{
++count;
}
flag=flag<<1;
}
return count;
}
};

//解法二：n=(n-1)&n;消一位1；
class Solution {
public:
	int  NumberOf1(int n)
	{
		int count = 0;
		while (n)
		{
			++count;
			n = (n - 1)&n;
		}
		return count;
	}
};*/


/*给定一个仅由小写字母组成的字符串。现在请找出一个位置，删掉那个字母之后，字符串变成回文。请放心总会有一个合法的解。
如果给定的字符串已经是一个回文串，那么输出-1。给定一个仅由小写字母组成的字符串。现在请找出一个位置，删掉那个字母之后，字符串变成回文。
请放心总会有一个合法的解。如果给定的字符串已经是一个回文串，那么输出-1。
https://www.nowcoder.com/practice/b6edb5ca15d34b1eb42e4725a3c68eba?https://www.nowcoder.com/practice/b6edb5ca15d34b1eb42e4725a3c68eba?
#include<iostream>
#include<string>
using namespace std;
bool IsPalindrome(string &s, int *start, int *end)
{
	int i = 0;
	int j = s.size() - 1;
	bool flag = true;
	while (i <= j)
	{
		if (s[i] != s[j])
		{
			flag = false;
			break;
		}
		++i;
		--j;
	}
	if (start != NULL)    *start = i;
	if (end != NULL)    *end = j;
	return flag;
}
int main()
{
	int T = 0;
	cin >> T;
	while (T)
	{
		string s;
		cin >> s;
		int start = 0;
		int end = s.length() - 1;
		if (IsPalindrome(s, &start, &end))
		{
			cout << "-1" << endl;
		}
		else
		{
			s.erase(end, 1);
			if (IsPalindrome(s, NULL, NULL))
			{
				cout << end << endl;
			}
			else
			{
				cout << start << endl;
			}
		}
		--T;
	}
}
*/

/*输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?tpId=13&&tqId=11185&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	static bool cmp(int x, int y)
	{
		string Sx = to_string(x);
		string Sy = to_string(y);
		string S1 = Sx;
		S1 += Sy;
		string S2 = Sy;
		S2 += Sx;
		return S1<S2;
	}
	string PrintMinNumber(vector<int> numbers)
	{
		//按字典序比较大小，排序
		sort(numbers.begin(), numbers.end(), cmp);
		string result = "";
		for (int i = 0; i<numbers.size(); ++i)
		{
			result += to_string(numbers[i]);
		}
		return result;
	}
};
*/

/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/

/*class Solution {
	public:
	void TreeDepthCore(TreeNode *pRoot,int depth,int &count)
	{
		if(pRoot==NULL)
		{
			if(depth>count)
			{
				count=depth;
			}
			return;
		}
		TreeDepthCore(pRoot->left,depth+1, count);
		TreeDepthCore(pRoot->right,depth+1, count);
	}
	int TreeDepth(TreeNode* pRoot)
	{
		if(pRoot==NULL)
		{
			return 0;
		}
		int count =0;
		int depth=0;
		TreeDepthCore(pRoot, depth, count);
		return count;
	}
};


class Solution {
public:
int TreeDepth(TreeNode* pRoot)
{
	if(pRoot==NULL)
	{
		return 0;
	}
	return 1+max(TreeDepth(pRoot->left),TreeDepth(pRoot->right));
}
};

//层序遍历求深度
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
		{
			return 0;
		}
		queue<TreeNode*> q;
		q.push(pRoot);
		int depth = 0;
		while (!q.empty())
		{
			++depth;
			int size = q.size();
			for (int i = 0; i<size; i++)
			{
				TreeNode *cur = q.front();
				q.pop();
				if (cur->left)
				{
					q.push(cur->left);
				}
				if (cur->right)
				{
					q.push(cur->right);
				}
			}
		}
		return depth;
	}
};
*/

/*一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
https://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811?tpId=13&&tqId=11193&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2)
	{
		if (data.size() == 0 || num1 == NULL || num2 == NULL)
		{
			return;
		}
		//1.整体异或
		int result = data[0];
		for (int i = 1; i<data.size(); ++i)
		{
			result ^= data[i];
		}
		if (result == 0)
			return;
		//2、找到其某一个位为1的位的位置，这就可以将数据分成两组了
		int flag = 1;
		int len = sizeof(int)* 8;
		for (int i = 0; i<len; i++)
		{
			//先&后左移
			if ((flag << i)&result)
			{
				flag <<= i;
				break;
			}
		}
		//3、由找到的为1的比特位进行划分，就能把两个只出现一次的数字分为两组
		*num1 = 0;
		*num2 = 0;
		for (int i = 0; i<data.size(); ++i)
		{
			if (data[i] & flag)
			{
				*num1 ^= data[i];
			}
			else
			{
				*num2 ^= data[i];
			}
		}
	}
};
*/

/*输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b?tpId=13&&tqId=11195&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum)
	{
		vector<int> result;
		if (array.size()<2)
		{
			return result;
		}
		int i = 0;
		int j = array.size() - 1;
		//这块不用考虑乘积，两个数字离的越远，乘积越小，而且数列是升序排列的
		while (i<j)
		{
			long long curSum = array[i] + array[j];
			if (curSum == sum)
			{
				result.push_back(array[i]);
				result.push_back(array[j]);
				break;
			}
			else if (curSum>sum)
			{
				j--;
			}
			else
			{
				i++;
			}
		}
		return result;
	}
};
*/


/*
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,
你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?tpId=13&&tqId=11194&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum)
	{
		vector<vector<int>> result;
		if (sum <= 0)
		{
			return result;
		}
		int start = 1;
		int end = 2;
		while (start<end)
		{
			//等差数列求和公式：（a1+an)*n/2
			int total = (start + end)*(end - start + 1) / 2;
			if (total == sum)
			{
				vector<int> v;
				for (int i = start; i <= end; i++)
				{
					v.push_back(i);
				}
				result.push_back(v);
				//这块要重新开始新序列了
				start++;
			}
			else if (total>sum)
			{
				start++;
			}
			else
			{
				end++;
			}
		}
		return result;
	}
};
*/


/*牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3?tpId=13&&tqId=11197&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	void ReverseWord(string &str, int begin, int end)
	{
		while (begin<end)
		{
			swap(str[begin++], str[end--]);
		}
	}
	string ReverseSentence(string str)
	{
		if (str.empty())
		{
			return str;
		}
		int begin = 0;
		int end = str.size() - 1;
		//整体反转
		ReverseWord(str, begin, end);
		int i = 0;
		while (i<str.size())
		{
			//跳过刚开头的空格
			while (str[i] == ' '&&i<str.size())
			{
				i++;
			}
			begin = end = i;
			//找寻单词的区间
			while (i<str.size() && str[i] != ' ')
			{
				i++;
				end++;
			}
			end--;
			ReverseWord(str, begin, end);
		}
		return str;
	}
};
*/


/*
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,
要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?tpId=13&&tqId=11196&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
解法一：局部翻转，再全局反转
class Solution {
public:
void ReserveWord(string &str,int begin,int end)
{
while(begin<end)
{
swap(str[begin++],str[end--]);
}
}
string LeftRotateString(string str, int n)
{
if(str.empty()||n==0)
{
return str;
}
//减少重复移动次数，并规范n
n%=str.size();
int begin=0;
int end=str.size()-1;
ReserveWord(str, begin, n-1);
ReserveWord(str, n,end);
ReserveWord(str, begin, end);
return str;
}
};


//解法二：逐步向前移动字符串，向后插入字符
class Solution {
public:
	void Rotatechar(string &str)
	{
		char temp = str[0];
		int i = 0;
		for (; i<str.size() - 1; i++)
		{
			str[i] = str[i + 1];
		}
		str[i] = temp;
	}
	string LeftRotateString(string str, int n)
	{
		if (str.empty() || n == 0)
		{
			return str;
		}
		n %= str.size();
		while (n)
		{
			Rotatechar(str);
			--n;
		}
		return str;
	}
};
*/


/*
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=13&&tqId=11212&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
	vector<vector<int> > Print(TreeNode* pRoot)
	{
		vector<vector<int>> result;
		if (pRoot == NULL)
		{
			return result;
		}
		//以队列为辅助工具，因为要层序遍历，栈的话就不行，不能层序遍历，因为后进先出
		queue<TreeNode*> q;
		//把队列里的节点放入栈中，从栈里取节点，，放数据
		stack<TreeNode*> s;
		//第一次从左往右遍历,标志位设为true
		bool flag = true;
		s.push(pRoot);
		while (!s.empty())
		{
			vector<int> v;
			int size = s.size();
			for (int i = 0; i<size; i++)
			{
				TreeNode *cur = s.top();
				s.pop();
				v.push_back(cur->val);
				//如果这一次从左往右遍历，那么下一层就应该从左往右入栈，才能实现从右往左遍历
				TreeNode *first = flag ? cur->left : cur->right;
				//如果这一次从右往左遍历，那么下一层就应该从右往左入栈，才能实现从左往右遍历
				TreeNode *second = flag ? cur->right : cur->left;
				if (first != NULL)
					q.push(first);
				if (second != NULL)
					q.push(second);
			}
			result.push_back(v);
			while (!q.empty())
			{
				s.push(q.front());
				q.pop();
			}
			//更改标志位
			flag = flag ? false : true;
		}
		return result;
	}
};
*/


/*
给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
https://www.nowcoder.com/practice/ef068f602dde4d28aab2b210e859150a?
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
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot == NULL || k <= 0)
		{
			return NULL;
		}
		stack<TreeNode*> s;
		TreeNode *cur = pRoot;
		//当s为空时也可能是左边遍历完了但还没有找到第k个节点
		while (!s.empty() || cur != NULL)
		{
			while (cur != NULL)
			{
				s.push(cur);
				cur = cur->left;
			}
			if (!s.empty())
			{
				//拿节点就相当于根节点，因为左边已经访问完了，拿了根节点以后，就得访问右边了
				cur = s.top();
				s.pop();
				--k;
				if (k == 0)
				{
					return cur;
				}
				cur = cur->right;
			}
		}
		return NULL;
	}
};
*/