#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string.h>
using namespace std;
/*
struct BaseUserInfo
{
	char m_szUserName[16];
	char m_szPassword[16];
	BaseUserInfo()
	{
		m_szUserName[0] = '\0';
		m_szPassword[0] = '\0';
	}
	void Print()
	{
		PrintUserInfo();
	}
	virtual void PrintUserInfo(){
		printf(m_szUserName);
	}
};
struct VIPInfo : public BaseUserInfo
{
	VIPInfo(const char * pUserName, const char * pPassword)
	{
		strcpy(m_szUserName, pUserName);
		strcpy(m_szPassword, pPassword);
	}
	virtual void PrintUserInfo()
	{
		printf("s", m_szPassword);
	}
};
int main(int argc, char* argv[])
{
	VIPInfo vip("user", "password");
	BaseUserInfo user;
	memcpy(&user, &vip, sizeof(BaseUserInfo));

	user.PrintUserInfo();
	user.Print();
	cin.get();
	return 0;
}
*/

#include<string>
#include<stack>
int main()
{
	cout << "D:\\桌面\\学习资料\\C语言课件V3\\进阶" << endl;
	string path = "D:\\桌面\\学习资料\\C语言课件V3";
	string metadatePath = path + "\\" + "metadate";
	cout << metadatePath << endl;
	stack<int> st;
	int pos = 1;
	while (pos <= 3)
	{
		st.push(pos++);
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << i << endl;
	}
	cin.get();
	return 0;
}