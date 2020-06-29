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

//给定一个字符串s和一组单词dict，判断s是否可以用空格分割成一个单词序列，使得单词序列中所有的单词都是dict中的单词（序列可以包含一个或多个单词）。
//例如:
//给定s = “leetcode”；
//dict = ["leet", "code"].
//返回true，因为"leetcode"可以被分割成"leet code".

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
//		//1、设置初始值为true，代表前面是个空串，不影响题，是一个辅助
//		ret[0] = true;
//		//2、观察题找规律，得出题目结果的状态是什么？
//		for (int i = 1; i <= len; i++)
//		{
//			for (int j = i - 1; j >= 0; j--)
//			{
//				//3、状态转移方程：F[i]=F[i-1]&&s[j,i]能否在dict中被找到
//				//为什么要&&呢？
//				//原因是：当第i个判断是否能被分割时，F[i-1]如果是true，代表前面已经
//				//被分割成功，如果s[i-1,i]也能被分割，那么if内条件成立，如果F[i-1]是
//				//false，代表这一点前没有被分割成功，就算后面s[i-1,i]在dict里被找到，
//				//也不能说明F[i]此位置的子串能被dict完全分割
//				if (ret[j] && dict.find(s.substr(j, i - j)) != dict.end())
//				{
//					ret[i] = true;
//					break;
//				}
//			}
//		}
//		//4、返回值
//		return ret[len];
//	}
//};
