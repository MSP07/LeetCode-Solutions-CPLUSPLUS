/*approach
  we first take in all numbers as strings 
  and then we sort them in string format using a comparator function
  then if the start of string is 0 then the largest will be "0" else
  we iterate through the sorted nums in string format to properly have a string
  and finally return them*/
class Solution{
public:
    static bool compare(string& x,string& y){
        return x+y > y+x;
    }
    string largestNumber(vector<int>& nums){
        vector<string>numStr;
        for(int num:nums){
            numStr.push_back(to_string(num));
        }
        sort(numStr.begin(),numStr.end(),compare);
        if(numStr[0]=="0")return "0";
        string ans = "";
        for(string num:numStr){
            ans += num;
        }
        return ans;
    }
};
