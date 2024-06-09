/*approach
  keep a var direction which indicated when to change places
  after iterating if dir==1 then increment else decrement
  after complete iteration push the char of string into new var and return*/
class Solution{
public:
    string convert(string s,int numRows){
        if(numRows<=1)return s;
        vector<string>helper(numRows,"");
        int j = 0, dir = -1;
        for(int i=0;i<s.length();i++){
            if(j==numRows-1 || j==0) dir *= (-1);
            helper[j] += s[i];
            if(dir==1)j++;
            else j--;
        }
        string res;
        for(auto it:helper) res += it;
        return res;
    }
};
