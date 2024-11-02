/*approach
  stack,greedy
  since req is min we push max value into stack and compare num in arr with that
  while we find min num than the st.top() we take that into ans and multiply it with the min 
  of curr node or next node val we push the num into stack and if there are more than 2 nodes
  we add that to out sum multiplying it with next nodes val to it and finally return the ans*/
class Solution{
public:
    int mctFromLeafValues(vector<int>& arr){
        int sum = 0;
        stack<int>st;
        st.push(INT_MAX);
        for(int num:arr){
            while(st.top()<=num){
                int mid = st.top();
                st.pop();
                sum += mid*min(st.top(),num);
            }
            st.push(num);
        }
        while(st.size()>2){
            int mid = st.top();
            st.pop();
            sum += mid*st.top();
        }
        return sum;
    }
};
