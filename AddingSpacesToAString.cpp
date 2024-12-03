/*approach
  string, simulation, two pointers
  ans will be in the length of len(s) + len(spaces) so we reserve that first
  to optimize time then we iterate through s and spaces and if the index matches
  the spaces[j] then we add an empty space to the string and incr that pointer
  and we by default add the chars in s to that of our ans string and finally return the ans string*/
class Solution{
public:
    string addSpaces(string s,vector<int>& spaces){
        string ans;
        ans.reserve(s.size()+spaces.size());
        int j=0;
        for(int i=0;i<s.size();i++){
            if(j<spaces.size() && i==spaces[j]){
                ans += " ";
                j++;
            }
            ans += s[i];
        }
        return ans;
    }
};
