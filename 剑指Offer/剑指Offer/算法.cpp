//42����������������
//����һ����̬�滮
//��̬�滮��4�����裺1��״̬
					/*2��״̬ת�Ʒ���
					3����ʼֵ����Ҫע��߽����⣩
					4������ֵ
*/
//class Solution {
//public:
//	int FindGreatestSumOfSubArray(vector<int> array)
//	{
//		int len = array.size();
//		//����һ�����飬���Դ�ţ���ͬ�����Ӵ�������
//		int *ret = new int[len];
//		ret[0] = array[0];
//		for (int i = 1; i<len; i++)
//		{
//			//״̬ת�Ʒ��̣�F(i)=max(F(i-1)+array[i],array[i]);
//			ret[i] = max(ret[i - 1] + array[i], array[i]);
//		}
//		int MaxSum = ret[0];
//		for (int i = 1; i<len; i++)
//			MaxSum = max(MaxSum, ret[i]);
//		return MaxSum;
//	}
//};

//��ͨ����
//class Solution {
//public:
//	int FindGreatestSumOfSubArray(vector<int> array)
//	{
//		int CurSum = array[0];
//		int MaxSum = array[0];
//		int len = array.size();
//		for (int i = 1; i<len; i++)    //�����Ӵ��ĳ���
//		{
//			if (CurSum <= 0)    //����Ӵ��Ŀ�ʼλ��
//				CurSum = array[i];
//			else
//				CurSum += array[i];    //�����Ӵ�������
//			if (CurSum>MaxSum)
//				MaxSum = CurSum;    //����Ӵ�������
//		}
//		return MaxSum;
//	}
//};



/*��һ����ά�����У�ÿ��һά����ĳ�����ͬ����
ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
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
//		//�����½ǻ������Ͻǽ�����⡣����ѡ������Ͻǽ������
//		int row = 0;
//		int col = array[0].size() - 1;
//		//�߽�����
//		while (row<array.size() && col >= 0)
//		{
//			if (array[row][col]>target)
//				//array[row][col]�ǵ�ǰ�����ģ���ǰ����С��
//				--col;
//			else if (array[row][col]<target)
//				++row;
//			else
//				return true;
//		}
//		return false;
//	}
//};

/*���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?
tpId = 13 & tqId = 11163 & tPage = 1 & rp = 1 & ru = / ta / coding - interviews&qru = / ta / coding - interviews / questionranking
class Solution {
public:
	int rectCover(int number)
	{
		//�趨״̬f(n)��ʾn������ŵķ���
		//2���Ƶ�״̬ת�Ʒ��� f(n)=f(n-2)+f(n-1)
		//3�����ñ߽�
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
����һ���������������32λ�����Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
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

//�ⷨ����n=(n-1)&n;��һλ1��
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


/*����һ������Сд��ĸ��ɵ��ַ������������ҳ�һ��λ�ã�ɾ���Ǹ���ĸ֮���ַ�����ɻ��ġ�������ܻ���һ���Ϸ��Ľ⡣
����������ַ����Ѿ���һ�����Ĵ�����ô���-1������һ������Сд��ĸ��ɵ��ַ������������ҳ�һ��λ�ã�ɾ���Ǹ���ĸ֮���ַ�����ɻ��ġ�
������ܻ���һ���Ϸ��Ľ⡣����������ַ����Ѿ���һ�����Ĵ�����ô���-1��
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

/*����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��
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
		//���ֵ���Ƚϴ�С������
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

//������������
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

/*һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
https://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811?tpId=13&&tqId=11193&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2)
	{
		if (data.size() == 0 || num1 == NULL || num2 == NULL)
		{
			return;
		}
		//1.�������
		int result = data[0];
		for (int i = 1; i<data.size(); ++i)
		{
			result ^= data[i];
		}
		if (result == 0)
			return;
		//2���ҵ���ĳһ��λΪ1��λ��λ�ã���Ϳ��Խ����ݷֳ�������
		int flag = 1;
		int len = sizeof(int)* 8;
		for (int i = 0; i<len; i++)
		{
			//��&������
			if ((flag << i)&result)
			{
				flag <<= i;
				break;
			}
		}
		//3�����ҵ���Ϊ1�ı���λ���л��֣����ܰ�����ֻ����һ�ε����ַ�Ϊ����
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

/*����һ����������������һ������S���������в�����������ʹ�����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
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
		//��鲻�ÿ��ǳ˻��������������ԽԶ���˻�ԽС�������������������е�
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
С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100��
���������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��
û���,���͵õ���һ������������Ϊ100������:18,19,20,21,22�����ڰ����⽻����,
���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? Good Luck!
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
			//�Ȳ�������͹�ʽ����a1+an)*n/2
			int total = (start + end)*(end - start + 1) / 2;
			if (total == sum)
			{
				vector<int> v;
				for (int i = start; i <= end; i++)
				{
					v.push_back(i);
				}
				result.push_back(v);
				//���Ҫ���¿�ʼ��������
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


/*ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�
ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ������������˼��
���磬��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ���ȷ�ľ���Ӧ���ǡ�I am a student.����
Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��
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
		//���巴ת
		ReverseWord(str, begin, end);
		int i = 0;
		while (i<str.size())
		{
			//�����տ�ͷ�Ŀո�
			while (str[i] == ' '&&i<str.size())
			{
				i++;
			}
			begin = end = i;
			//��Ѱ���ʵ�����
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
�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ�����ָ�����������
����һ���������ַ�����S���������ѭ������Kλ���������������磬�ַ�����S=��abcXYZdef��,
Ҫ�����ѭ������3λ��Ľ��������XYZdefabc�����ǲ��Ǻܼ򵥣�OK���㶨����
https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?tpId=13&&tqId=11196&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
�ⷨһ���ֲ���ת����ȫ�ַ�ת
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
//�����ظ��ƶ����������淶n
n%=str.size();
int begin=0;
int end=str.size()-1;
ReserveWord(str, begin, n-1);
ReserveWord(str, n,end);
ReserveWord(str, begin, end);
return str;
}
};


//�ⷨ��������ǰ�ƶ��ַ������������ַ�
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
��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ���ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ����ơ�
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
		//�Զ���Ϊ�������ߣ���ΪҪ���������ջ�Ļ��Ͳ��У����ܲ����������Ϊ����ȳ�
		queue<TreeNode*> q;
		//�Ѷ�����Ľڵ����ջ�У���ջ��ȡ�ڵ㣬��������
		stack<TreeNode*> s;
		//��һ�δ������ұ���,��־λ��Ϊtrue
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
				//�����һ�δ������ұ�������ô��һ���Ӧ�ô���������ջ������ʵ�ִ����������
				TreeNode *first = flag ? cur->left : cur->right;
				//�����һ�δ��������������ô��һ���Ӧ�ô���������ջ������ʵ�ִ������ұ���
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
			//���ı�־λ
			flag = flag ? false : true;
		}
		return result;
	}
};
*/


/*
����һ�ö��������������ҳ����еĵ�kС�Ľ�㡣���磬 ��5��3��7��2��4��6��8��    �У��������ֵ��С˳�����С����ֵΪ4��
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
		//��sΪ��ʱҲ��������߱������˵���û���ҵ���k���ڵ�
		while (!s.empty() || cur != NULL)
		{
			while (cur != NULL)
			{
				s.push(cur);
				cur = cur->left;
			}
			if (!s.empty())
			{
				//�ýڵ���൱�ڸ��ڵ㣬��Ϊ����Ѿ��������ˣ����˸��ڵ��Ժ󣬾͵÷����ұ���
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