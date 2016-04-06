class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
            int n = numbers.size();
        if(n==0) return 0;
        else {
            int count = 0;
            sort(numbers.begin(),numbers.end());
            int ans = numbers[n/2];
            for(int i = 0;i<n;++i)
              if(numbers[i]==ans)
                  ++count;
            return count>n/2 ? ans:0;
        }
    }
};