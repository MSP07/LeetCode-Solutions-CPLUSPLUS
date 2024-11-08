/*approach
  string
  only if both a and b are equal we return -1
  else both are not equal so we must return the longest one in the both of them*/
class Solution{
public:
    int findLUSlength(string a,string b){
        if(a==b)return -1;
        return max(a.size(),b.size());
    }
};
