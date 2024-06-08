//approach
//iterate through the string when we find a non-integer we add it to ans
//if the ans size is more than 1 we pop the last element
class Solution{
public:
    string clearDigits(string s){
        int i = 0;
        string ans = "";
        while(i<s.length()){
            if(!isdigit(s[i])){
                ans += s[i];
                i++;
            }else{
                i++;
                if(ans.size()>=1) ans.pop_back();
            }
        }
        return ans;
    }
};
