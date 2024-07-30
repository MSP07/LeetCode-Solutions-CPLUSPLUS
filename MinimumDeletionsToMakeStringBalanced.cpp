/*approach
  dp approach and stack approach
  we keep track of acount and bcount
  if char is a we either delete it
  so ++acount else we choose to delete bcount
  till then whichever is minimum we choose that
  if char is b then we simply increase the count and finally
  return acount as that will be minimum
  in stack if it is b we push it so as to find a 'a' pair in future
  if we find a 'a' in future and the st is not empty and st.top is b
  we found a pair so we pop that stack and increase the deletions
  and finally return the deletions*/
class Solution{
public:
    int minimumDeletions(string s){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int acount = 0, bcount = 0;
        for(char c:s){
            if(c=='a'){
                acount = min(++acount,bcount);
            }else{
                ++bcount;
            }
        }
        return acount;
        //stack approach
        stack<int>st;
        int deletions = 0;
        for(char c:s){
            if(c=='b'){
                st.push(c);
            }else{
                if(!st.empty() && st.top()=='b'){
                    st.pop();
                    ++deletions;
                }
            }
        }
        return deletions;
    }
};
