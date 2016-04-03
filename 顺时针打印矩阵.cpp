#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> v;
		if (matrix.size() == 0 || matrix[0].size() == 0)return v;
		int a = 0, x = matrix.size() - 1, y = matrix[0].size() - 1, i, j;
		do{
			for (i = a, j = a; j <= y; j++) v.push_back(matrix[i][j]);
			for (i = a + 1, j = y; i <= x; i++) v.push_back(matrix[i][j]);
			if (a != x)for (i = x, j = y - 1; j >= a; j--) v.push_back(matrix[i][j]);
			if (a != y)for (i = x - 1, j = a; i >= a + 1; i--) v.push_back(matrix[i][j]);
		} while (++a <= --x&&a <= --y);
		return v;
	}
	
};