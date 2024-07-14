/*approach
  we use stack
  if asteroid is greater than previous and current asteroid size are equal
  one we pop the previous one only if asteroid is travelling in opp direction
  we keep track whether the asteroid is exploded through a flag and only when 
  the asteroid is exploded we add that asteroid to stack and we initialise the 
  bool to false before start of each iteration. Finally we push the stack's top
  and pop it till the stack is empty to an array in reverse order and we return 
  the array*/
  
class Solution{
public:
    vector<int> asteroidCollision(vector<int>& asteroids){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        stack<int>st;
        for(int asteroid:asteroids){
            bool exploded = false;
            while(!st.empty() && asteroid<0 && st.top()>0){
                if(abs(asteroid) > st.top()){
                  st.pop();
                  continue;
                }else if(abs(asteroid)==st.top()){
                    st.pop();
                }
                exploded = true;
                break;
            }
            if(!exploded){
                st.push(asteroid);
            }
        }
        vector<int>res(st.size());
        for(int i=st.size()-1;i>=0;--i){
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};
