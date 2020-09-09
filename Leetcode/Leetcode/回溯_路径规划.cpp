#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/word-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution {
public:
	bool existCode(vector<vector<char>>& board, vector<vector<bool>>& dp, string& word, int rows, int cols, int row, int col, int index)
	{
		if (index == word.size())
		{
			return true;
		}
		if (0>row || row >= rows || col<0 || col >= cols || dp[row][col] || board[row][col] != word[index])
		{
			return false;
		}

		dp[row][col] = true;
		bool result = existCode(board, dp, word, rows, cols, row + 1, col, index + 1)
			|| existCode(board, dp, word, rows, cols, row - 1, col, index + 1)
			|| existCode(board, dp, word, rows, cols, row, col + 1, index + 1)
			|| existCode(board, dp, word, rows, cols, row, col - 1, index + 1);
		dp[row][col] = false;
		return result;
	}
	bool exist(vector<vector<char>>& board, string word)
	{
		if (word.size() == 0)
		{
			return true;
		}
		if (board.size() == 0)
		{
			return false;
		}
		int rows = board.size();
		int cols = board[0].size();
		vector<vector<bool>> dp(rows, vector<bool>(cols, false));
		for (int i = 0; i<board.size(); ++i)
		{
			for (int j = 0; j<board[0].size(); ++j)
			{
				if (existCode(board, dp, word, rows, cols, i, j, 0))
					return true;
			}
		}
		return false;
	}
};
*/
int main()
{
	vector<vector< char >> board= {{ 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A', 'D', 'E', 'E'}};
	string word = "ABCB";
	exist(board, word);
	return 0;
}