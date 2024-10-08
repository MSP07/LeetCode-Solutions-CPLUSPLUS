/*approach
  greedy
  our aim is to find ']' for all '[' then only we can make it balanced to do it
  effectively first we count '[' and if the count of the open bracket is if greater 
  and there is a ']' we found a match so we reduce the count/swaps finally the min swaps
  will be (swaps+1)/2*/
class Solution{
public:
    int minSwaps(string s){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int swaps = 0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='['){
                ++swaps;
            }else if(swaps>0){
                --swaps;
            }
        }
        return (swaps+1)/2;
    }
};
