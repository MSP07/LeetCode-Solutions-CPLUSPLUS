/*approach
  stack
  brute force will be to run two for loops, check the given condition and update the maxRamp
  to optimise that to a 0(N) soln we can use stack first we keep track of decreasing points in the array
  and then we iterate the array from backward so the decreased index we first calculated will show us the 
  possible indices which has lower val than curr index so we check for that and update our maxRamp and finally
  return the answer*/
class Solution{
public:
    int maxWidthRamp(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int maxRamp = 0;
        stack<int>st;
        st.push(0);
        for(int i=1;i<nums.size();++i){
            if(nums[st.top()]>nums[i]){
                st.push(i);
            }
        }
        for(int j=nums.size()-1;j>=0;--j){
            while(!st.empty() && nums[st.top()]<=nums[j]){
                maxRamp = max(maxRamp,j-st.top());
                st.pop();
            }
        }
        return maxRamp;
    }
};
