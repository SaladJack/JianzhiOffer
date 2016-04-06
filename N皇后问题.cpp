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
    pos = upperLim&(~(colLim|leftDiaLim|rightDiaLim));//Ϊ���ж���Щλ�ÿ��Է�,1������Է�,0�����ܷ�
    int res = 0;
    //�ҵ����Ҷ˵�1�������ҵ������ν��еݹ飨�ѻʺ����1����
    while(pos!=0){
       mostRightOne = pos&(~pos+1);
       pos = pos-mostRightOne;//Ϊ���ж�ѭ������
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