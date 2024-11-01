/*approach
  greedy, two pointers
  start with 0,n and for each 'I' we make perm[i] = low
  and incr low, for each 'D' we make perm[i] = high and incr high
  finally perm[n] = low and return perm*/
class Solution{
public:
    vector<int> diStringMatch(string s){
        int n = s.size();
        vector<int>perm(n+1);
        int low = 0, high = n;
        for(int i=0;i<n;++i){
            if(s[i]=='I'){
                perm[i] = low;
                low++;
            }else{
                perm[i] = high;
                high--;
            }
        }
        perm[n] = low;
        return perm;
    }
};
