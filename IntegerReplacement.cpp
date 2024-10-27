/*approach
  dp,greedy,bit manipulation
  in dp if its even we take find(n/2) + 1 else 1 + min(find(n-1),find(n+1))
  we memoize this but still gives us tle so greedily we do the same but with bit manipulation
  if num is even change it to num/2 else if num is 3 or (num&2) it indicates num -= 1 will give min steps
  else we do num += 1 and increase count ,finally return the count */
class Solution{
    unordered_map<int,int>dp;
private:
    int find(int n){
        if(n==1)return 0;
        if(dp.count(n))return dp[n];
        int steps = 0;
        if(n%2==0){
            steps = 1 + find(n/2);
        }else{
            steps = 1 + min(find(n-1),find(n+1));
        }
        return dp[n] = steps;
    }
public:
    int integerReplacement(int n){
        //dp approach(will give tle for memoization)
        return find(n);
        //greedy,bit manipulation approach
        long long num = n ,count = 0;
        while(num>1){
            if(num%2==0){
                num /= 2;
            }else{
                if(num==3 || (num&2)==0){
                    num -= 1;
                }else{
                    num += 1;
                }
            }
            ++count;
        }
        return count;
    }
};
