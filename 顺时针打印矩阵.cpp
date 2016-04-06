#include <iostream>
#include <vector>
using namespace std;
//解法一
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
/*解法二
class Solution {
public:
   vector<int> printMatrix(vector<vector<int>> matrix) {
        int tR=0;
        int tC=0;
        int dR=matrix.size()-1;
        int dC=matrix[0].size()-1;
        vector<int> result;
        while(tR<=dR&&tC<=dC)
                print(matrix,result,tR++,tC++,dR--,dC--);
        return result;
   }
   void print(vector<vector<int>> matrix,vector<int>& result,int tR,int tC,int dR,int dC){
        if(tR==dR)
            for(int i=tC;i<=dC;i++)
                result.push_back(matrix[tR][i]);
        else if(tC==dC)
            for(int i = tR;i<=dR;i++)
                result.push_back(matrix[i][tC]);
        else {
            int curC=tC;
            int curR=tR;
         while(curC!=dC){
             result.push_back(matrix[tR][curC]);
             ++curC;
        }
        while(curR!=dR){
             result.push_back(matrix[curR][dC]);
             ++curR;
        }
        while(curC!=tC){
             result.push_back(matrix[dR][curC]);
             --curC;
        }
        while(curR!=tR){
             result.push_back(matrix[curR][tC]);
             --curR;
        }
     }
   }
};*/