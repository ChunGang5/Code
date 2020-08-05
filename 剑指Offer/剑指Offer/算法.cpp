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

//����һ���ַ���s��һ�鵥��dict���ж�s�Ƿ�����ÿո�ָ��һ���������У�ʹ�õ������������еĵ��ʶ���dict�еĵ��ʣ����п��԰���һ���������ʣ���
//����:
//����s = ��leetcode����
//dict = ["leet", "code"].
//����true����Ϊ"leetcode"���Ա��ָ��"leet code".

//class Solution {
//public:
//	bool wordBreak(string s, unordered_set<string> &dict)
//	{
//		if (s.empty())
//		{
//			return false;
//		}
//		int len = s.size();
//		vector<bool> ret(len + 1, false);
//		//1�����ó�ʼֵΪtrue������ǰ���Ǹ��մ�����Ӱ���⣬��һ������
//		ret[0] = true;
//		//2���۲����ҹ��ɣ��ó���Ŀ�����״̬��ʲô��
//		for (int i = 1; i <= len; i++)
//		{
//			for (int j = i - 1; j >= 0; j--)
//			{
//				//3��״̬ת�Ʒ��̣�F[i]=F[i-1]&&s[j,i]�ܷ���dict�б��ҵ�
//				//ΪʲôҪ&&�أ�
//				//ԭ���ǣ�����i���ж��Ƿ��ܱ��ָ�ʱ��F[i-1]�����true������ǰ���Ѿ�
//				//���ָ�ɹ������s[i-1,i]Ҳ�ܱ��ָ��ôif���������������F[i-1]��
//				//false��������һ��ǰû�б��ָ�ɹ����������s[i-1,i]��dict�ﱻ�ҵ���
//				//Ҳ����˵��F[i]��λ�õ��Ӵ��ܱ�dict��ȫ�ָ�
//				if (ret[j] && dict.find(s.substr(j, i - j)) != dict.end())
//				{
//					ret[i] = true;
//					break;
//				}
//			}
//		}
//		//4������ֵ
//		return ret[len];
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


