#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int process(int upperLim,int colLim,int leftDiaLim,int rightDiaLim){
    if(upperLim==colLim)
        return 1;
    int pos=0;
    int mostRightOne = 0;
    pos = upperLim&(~(colLim|leftDiaLim|rightDiaLim));//为了判断哪些位置可以放,1代表可以放,0代表不能放
    int res = 0;
    //找到最右端的1，并从右到左依次进行递归（把皇后放在1处）
    while(pos!=0){
       mostRightOne = pos&(~pos+1);
       pos = pos-mostRightOne;//为了判断循环结束
       res+=process(upperLim,colLim|mostRightOne,(leftDiaLim|mostRightOne)<<1,(rightDiaLim|mostRightOne)>>1);
    }
    return res;
}
 
int num(int n){
    if(n>32||n<1)
        return 0;
    int upperLim=n==32? -1:(1<<n)-1;
    return process(upperLim,0,0,0);
}
 
int main(){
    int n;
    while(cin>>n)
    {
        if(n==0) break;
    cout<<num(n)<<endl;
    }
}