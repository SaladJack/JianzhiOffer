#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
           int n = array.size();
           if(n==0) return 0;
           else return find(array,0,n-1);
    }
    int find(vector<int> array,int l,int h){
        if(l>=h) return array[h];   
        int middle = (l+h)/2;
            int front = find(array,l,middle);
            int behind =find(array,middle+1,h);
            int mid =findmiddle(array,l,h);
            return max(max(front,behind),mid);
    }
    int findmiddle(vector<int> array,int l,int h){
    int middle = (l+h)/2;
    int sum=0,left=array[middle],right=0;
    for(int i=middle;i>=l;i--){
        sum+=array[i];
        if(sum>=left) left = sum;
      }
    sum = 0;
    for(int i = middle+1;i<=h;i++){
        sum+=array[i];
        if(sum>=right) right = sum;
    }
    return left+right;
    }
};