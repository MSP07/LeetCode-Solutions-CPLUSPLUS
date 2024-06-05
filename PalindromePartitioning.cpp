//approach
//we iterate through given string and check whether the consecutive substring is palindrome
//if yes we push it into data structure
//when we arrive at the final index of the given string we simply add the data structure to ans vector and return
class Solution{
private:
    bool isPalindrome(string&s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--])return false;
        }
        return true;
    }
    void partitionHelper(int index,string&s,vector<vector<string>>&ans,vector<string>&ds){
        if(index==s.length()){
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(isPalindrome(s,index,i)){
                ds.push_back(s.substr(index,i-index+1));
                partitionHelper(i+1,s,ans,ds);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<string>>ans;
        vector<string>ds;
        partitionHelper(0,s,ans,ds);
        return ans;
    }
};
