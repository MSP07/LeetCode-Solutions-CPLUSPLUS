/*approach
  greedy
  we want to find the min Swaps to place all the balck balls together and white balls together
  if we gather either color balls then other color also will be gathered. so we try to do that
  if we come across a black ball we simply add that to our count else if we come across a white ball
  we swap it to the before index of nearest black ball and the count of black balls will be the nearest 
  swap and hence we implement this and return the min swaps required*/
class Solution{
public:
    long long minimumSteps(string s){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        long long swaps = 0;
        long long count_ones = 0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='0'){
                swaps += count_ones;
            }else{
                ++count_ones;
            }
        }
        return swaps;
    }
};
