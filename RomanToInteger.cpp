/*approach
  we use hashmap first to include roman values
  then if there are consecutive romans that are less than upcoming next romans
  then we subtract that from our answer else we add that roman value to our ans
  and we finally we return that ans*/
class Solution{
public: 
    int romanToInt(string s){
        unordered_map<char,int>romanToInt={
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int ans = 0;
        for(int i=0;i<s.size();++i){
            if(i+1<s.size() && romanToInt[s[i]] < romanToInt[s[i+1]]){
                ans -= romanToInt[s[i]];
            }else{
                ans += romanToInt[s[i]];
            }
        }
        return ans;
    }
};
