/*approach
  string,simulation
  iterate two places at a time with the pointer then if i+k <=n then it satisfies the first
  two conditions so reverse that part of string else reverse the whole string and return*/
class Solution{
public:
    string reverseStr(string s,int k){
        int n = s.size();
        for(int i=0;i<n;i+=2){
            if(i+k<=n){
                reverse(s.begin()+i,s.begin()+i+k);
            }else{
                reverse(s.begin()+i,s.end());
            }
        }
        return s;
    }
};
