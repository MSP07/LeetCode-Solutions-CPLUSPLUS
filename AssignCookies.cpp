/*approach
  greedy
  we first sort both and if the size of the particular element
  is greater than or equal to the greed then we increase cnt and 
  pointers at both array else we only increase pointer at size to
  find element with appropriate size*/
class Solution{
public:
    int findContentChildren(vector<int>& g,vector<int>& s){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt=0,i=0,j=0;
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]){
                cnt++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return cnt;
    }
};
