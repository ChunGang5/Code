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

/*
����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&&tqId=11179&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
	public:
	void ConvertNode(TreeNode *pNode,TreeNode*& pIndex)
	{
		if(pNode==NULL)
			return;
		TreeNode* cur=pNode;
		if(cur->left)
		{
			ConvertNode(cur->left, pIndex);
		}
		cur->left=pIndex;
		//�սڵ�û��right
		if(pIndex!=NULL)
		{
			pIndex->right=cur;
		}
		pIndex=cur;
		if(cur->right)
		{
			ConvertNode(cur->right, pIndex);
		}
	}
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if(pRootOfTree==NULL)
			return NULL;
		TreeNode* pListIndex=NULL;
		ConvertNode(pRootOfTree, pListIndex);
		TreeNode* pHead=pListIndex;
		while(pHead!=NULL && pHead->left!=NULL )
		{
			pHead=pHead->left;
		}
		return pHead;
	}
};
*/

/*����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣����磬�����������4 X 4���� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
�����δ�ӡ������1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
https://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a?tpId=13&&tqId=11172&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	void PrintfVector(vector<vector<int>> matrix, vector<int>& result, int rows, int cols, int start)
	{
		//ÿ�ζ��Ǵӣ�start,start����ʼ��ӡ��
		int EndX = cols - 1 - start;
		int EndY = rows - 1 - start;
		//��
		for (int i = start; i <= EndX; ++i)
		{
			result.push_back(matrix[start][i]);
		}
		//�ұ�
		//��ֻ��һ��
		if (start<EndY)
		{
			for (int i = start + 1; i <= EndY; ++i)
			{
				result.push_back(matrix[i][EndX]);
			}
		}
		//��
		//���������в��ܴ�ӡ�����һ��
		if (start<EndX&&start<EndY)
		{
			for (int i = EndX - 1; i >= start; --i)
			{
				result.push_back(matrix[EndY][i]);
			}
		}
		//��
		//���ٱ�֤����������
		if (start<EndX&&start<EndY - 1)
		{
			for (int i = EndY - 1; i>start; --i)
			{
				result.push_back(matrix[i][start]);
			}
		}
	}
	vector<int> printMatrix(vector<vector<int> > matrix)
	{
		vector<int> result;
		if (matrix.empty())
		{
			result;
		}
		int rows = matrix.size();
		int cols = matrix[0].size();
		int start = 0;
		while (rows>start * 2 && cols>start * 2)
		{
			PrintfVector(matrix, result, rows, cols, start);
			++start;
		}
		return result;
	}
};
*/


/*
����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
��֤base��exponent��ͬʱΪ0
https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&&tqId=11165&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
	public:
	double Power(double base, int exponent)
	{
		bool flag=false;
		//��֤���ܸ�0�����������ᵼ�³������
		if(base==0.0&&exponent<0)
		{
			flag=true;
			return 0.0;
		}
		unsigned int absexponent=abs(exponent);
		double result=1.0;
		for(int i=0;i<absexponent;++i)
		{
			result*=base;
		}
		if(exponent<0)
		{
			result=1.0/result;
		}
		return result;
	}
};
*/

/*
���ϵ��°����ӡ��������ͬһ����������������ÿһ�����һ�С�
https://www.nowcoder.com/practice/445c44d982d04483b04a54f298796288?tpId=13&&tqId=11213&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot)
	{
		vector<vector<int>> result;
		if (pRoot == NULL)
		{
			return result;
		}
		queue<TreeNode*> q;
		q.push(pRoot);
		while (!q.empty())
		{
			int n = q.size();
			vector<int> temp;
			for (int i = 0; i<n; ++i)
			{
				TreeNode* cur = q.front();
				q.pop();
				temp.push_back(cur->val);
				if (cur->left)
				{
					q.push(cur->left);
				}
				if (cur->right)
				{
					q.push(cur->right);
				}
			}
			result.push_back(temp);

		}
		return result;
	}
};
*/

/*
��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null��
2(L+X)=L+X+nR
L=nR-X;
https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&&tqId=11208&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL)
		{
			return NULL;
		}
		ListNode* fast = pHead;
		ListNode* last = pHead;
		bool flag = false;
		while (fast != NULL&&fast->next != NULL)
		{
			fast = fast->next->next;
			last = last->next;
			if (fast == last)
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			return NULL;
		}
		ListNode* pM = last;
		ListNode* pH = pHead;
		while (pM != pH)
		{
			pM = pM->next;
			pH = pH->next;
		}
		return pM;
	}
};


//����������map���
#include<unordered_map>
class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if(pHead==NULL)
		{
			
		}
		unordered_map<ListNode*,int> ListMap;
		ListNode* cur=pHead;
		bool flag=false;
		while(cur)
		{
			if(ListMap.find(cur)==ListMap.end())
			{
				ListMap.insert({cur,1});
			}
			else
			{
				flag=true;
				break;
			}
			cur=cur->next;
		}
		if(!flag)
		{
			return NULL;
		}
		return cur;
	}
};
*/

/*
ÿ����һ��ͯ��,ţ�Ͷ���׼��һЩС����ȥ�����¶�Ժ��С����,����������ˡ�HF��Ϊţ�͵�����Ԫ��,��ȻҲ׼����һЩС��Ϸ��
����,�и���Ϸ��������:����,��С������Χ��һ����Ȧ��Ȼ��,�����ָ��һ����m,�ñ��Ϊ0��С���ѿ�ʼ������
ÿ�κ���m-1���Ǹ�С����Ҫ���г��׸�,Ȼ���������Ʒ�����������ѡ����,���Ҳ��ٻص�Ȧ��,��������һ��С���ѿ�ʼ,
����0...m-1����....������ȥ....ֱ��ʣ�����һ��С����,���Բ��ñ���,�����õ�ţ������ġ�����̽���ϡ���ذ�(��������Ŷ!!^_^)��
������������,�ĸ�С���ѻ�õ������Ʒ�أ�(ע��С���ѵı���Ǵ�0��n-1)

���û��С���ѣ��뷵��-1
Լɪ������
class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n<1 || m<1)
		{
			return -1;
		}
		list<int> Loop;
		for (int i = 0; i<n; ++i)
		{
			Loop.push_back(i);
		}
		auto cur = Loop.begin();
		while (Loop.size()>0)
		{
			for (int i = 1; i<m; ++i)
			{
				cur++;
				if (cur == Loop.end())
				{
					cur = Loop.begin();
				}
			}
			auto next = ++cur;
			if (next == Loop.end())
			{
				next = Loop.begin();
			}
			--cur;
			Loop.erase(cur);
			cur = next;
		}
		return *cur;
	}
};
*/

/*
дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�
https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&&tqId=11201&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	int Add(int num1, int num2)
	{
		int sum, carry;
		do
		{
			//����������λ�ļӷ�������
			sum = num1^num2;
			//num1+num2�����Ľ�λ
			carry = (num1&num2) << 1;
			num1 = sum;
			num2 = carry;
		} while (num2 != 0);    //num2Ҳ����carryΪ0����û�н�λʱѭ����ֹ
		return num1;
	}
};
*/

/*
��һ���ַ���(0<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��, ���û���򷵻� -1����Ҫ���ִ�Сд��.����0��ʼ������
https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&&tqId=11187&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	int FirstNotRepeatingChar(string str)
	{
		if (str.empty())
		{
			return -1;
		}
		vector<int> HashTable(256, 0);    //1KB
		for (int i = 0; i<str.size(); ++i)
		{
			HashTable[str[i]]++;
		}
		int i = 0;
		while (str[i] != '\0')
		{
			if (HashTable[str[i]] == 1)
			{
				cout << str[i] << endl;
				return i;
			}
			++i;
		}
		return -1;
	}
};
*/

