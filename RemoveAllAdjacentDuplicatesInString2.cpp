/*approach
  we follow similar approach for prev version of this problem
  we declare a vector and we check whether the previosuly added element in the vector is same char as now
  if we see it we increase its count else we simply add the char into vector with 1 as count and we check whether the
  count as reached k if it is then we pop that element from the vector we continue this process and when we complete iterating
  the given string we declare another string and append the chars from vector into ans and finally return it*/
class Solution{
public:
    string removeDuplicates(string s, int k){
        vector<pair<char,int>>st;
        for(char c:s){
            if(!st.empty() && st.back().first==c){
                st.back().first++;
            }else{
                st.push_back({c,1});
            }
            if(st.back().second==k){
                st.pop_back();
            }
        }
        string ans = "";
        for(auto it:st){
            ans.append(it.second,it.first);
        }
        return ans;
    }
};
