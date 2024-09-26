/*approach
  till we have either of the strings we iteratively add the first string chars to ans
  and then if there is a word2 we add its char to the ans and finally return the ans*/
class Solution{
public:
    string mergeAlternatively(string word1,string word2){
        string ans = "";
        int i = 0;
        while(i<word1.size() || i<word2.size()){
            if(i<word1.size()){
                ans += word1[i];
            }
            if(i<word2.size()){
                ans += word2[i];
            }
            i++;
        }
        return ans;
    }
};
