/*
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-increase-to-keep-city-skyline/
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
横看成岭侧成峰，远近高低各不同。
从North与从South看得出的结果是一致的，每列看到的都是该列的最大值
East和West同上。
可用数组存储该最大值，注意题目中给的数组一定是n*n的，故可用一个数组存储所有列的最大值，
一个数组存储所有行的最大值。同时由于是n*n数组，遍历时可同时得出列和行的最大值。
最后每个元素可增高的值为 “该元素所在行的最大值” 和 “该元素所在列的最大值”中较小的那个与该元素的差值
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		vector<int> row, column;
		for (int i = 0; i < grid.size(); ++i)
		{
			int max_row = -1;
			int max_col = -1;
			for (int j = 0; j < grid.size(); ++j)
			{
				max_row = max_row > grid[i][j] ? max_row : grid[i][j];
				max_col = max_col > grid[j][i] ? max_col : grid[j][i];
			}
			row.emplace_back(max_row);
			column.emplace_back(max_col);
		}

		int output = 0;
		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid.size(); ++j)
			{
				int min_max = row[i] > column[j] ? column[j] : row[i];
				output += (min_max - grid[i][j]);
			}
		}
		return output;
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> grid;
	vector<int> vec1 = { 3, 0, 8, 4 };
	vector<int> vec2 = { 2, 4, 5, 7 };
	vector<int> vec3 = { 9, 2, 6, 3 };
	vector<int> vec4 = { 0, 3, 1, 0 };
	grid.push_back(vec1);
	grid.push_back(vec2);
	grid.push_back(vec3);
	grid.push_back(vec4);

	cout << sol.maxIncreaseKeepingSkyline(grid) << endl;

	system("pause");
	return 0;
}