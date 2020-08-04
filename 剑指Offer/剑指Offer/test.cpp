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