/*approach
  sliding window
  we start from 0 index and go uptil n-k+1
  we maintain a lastcolor that is first element and if the curr element is 
  equal to lastcolor then we assign count to 1, lastcolor to current color and 
  continue else we increase the cnt and also update the lastcolor to curr color
  and if the count we are counting is >= k then we have found a group so we incr the
  count of ans and finally return the ans*/
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = colors.size();
        int ans = 0;
        int ele = 1, lastColor = colors[0];
        for(int i=1;i<n+k-1;i++){
            int ind = i%n;
            if(colors[ind]==lastColor){
                ele = 1;
                lastColor = colors[ind];
                continue;
            }
            ele += 1;
            if(ele>=k){
                ans += 1;
            }
            lastColor = colors[ind];
        }
        return ans;
    }
};
