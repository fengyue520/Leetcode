/*
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/max-increase-to-keep-city-skyline/
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

/*
�ῴ�����ɷ壬Զ���ߵ͸���ͬ��
��North���South���ó��Ľ����һ�µģ�ÿ�п����Ķ��Ǹ��е����ֵ
East��Westͬ�ϡ�
��������洢�����ֵ��ע����Ŀ�и�������һ����n*n�ģ��ʿ���һ������洢�����е����ֵ��
һ������洢�����е����ֵ��ͬʱ������n*n���飬����ʱ��ͬʱ�ó��к��е����ֵ��
���ÿ��Ԫ�ؿ����ߵ�ֵΪ ����Ԫ�������е����ֵ�� �� ����Ԫ�������е����ֵ���н�С���Ǹ����Ԫ�صĲ�ֵ
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