class Solution {
public:
      int getLenOfNum(int num){
        int len = 0;
        while(num!=0){
           ++len;
           num/=10;
        }
          return len;
    }
     
    int powerBaseof10(int base){
        return pow(10,base);
    }
    //依次计算每一位1的个数
    int NumberOf1Between1AndN_Solution(int num)
    {
         
        if(num<=0) return 0;
         
        int len = getLenOfNum(num);
        if(len==1) return 1;
         
        int tmp = powerBaseof10(len-1);
        int first = num/tmp;
        int firstOneNum = first==1? num%tmp+1:tmp;
        int otherOneNum = first*(len-1)*(tmp/10);
        return firstOneNum + otherOneNum + NumberOf1Between1AndN_Solution(num%tmp);
         
    }
     
   
};