/*approach
  we keep track of increasing and decreasing subbsequence 
  and update the count value accordingly*/
class Solution{
public:
    int numTeams(vector<int>& rating){
        int n = rating.size();
        int cnt = 0;
        for(int j=1;j<n-1;++j){
            int less_left = 0, more_left = 0;
            int less_right = 0, more_right = 0;
            for(int i=0;i<j;++i){
                if(rating[i]<rating[j])less_left++;
                if(rating[i]>rating[j])more_left++;
            }
            for(int k = j+1;k<n;++k){
                if(rating[k]<rating[j])less_right++;
                if(rating[k]>rating[j])more_right++;
            }
            cnt += less_left*more_right + less_right*more_left;
        }
        return cnt;
    }
};
