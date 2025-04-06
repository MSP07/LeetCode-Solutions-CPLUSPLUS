/*approach
  hashmap
  we keep a hashmap to find the firstoccurence and 
  if the char is occured already then we calculate the length in between
  its chars and keep track of max ones*/
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int>hashi(26,-1);
        int ans = -1;
        for(int i=0;i<s.size();i++){
            int ind = s[i]-'a';
            if(hashi[ind]==-1){
                hashi[ind] = i;
            }else{
                ans = max(ans,i-hashi[ind]-1);
            }
        }
        return ans;
    }
};
