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

#include<iostream>
using namespace std;
class A
{
public:
	int a;
	int b;
};
class B:public A
{
public:
	int a;
	int c;
};
int main()
{
	B b;
	b.a = 10;
	cout << b.a << endl;
	cout << b.A::a << endl;
	cin.get();
	return 0;
}