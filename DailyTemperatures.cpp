/*approach
  we make use of stack and push the indices into stack and compare whether there
  is a greater temperature than the prev day and if we find one we update result array
  with the difference in indices and finally we return the result array*/
class Solution{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int>result(temperatures.size(),0);
        stack<int>st;
        for(int i=0;i<temperatures.size();++i){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};
