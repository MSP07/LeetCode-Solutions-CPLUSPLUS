//approach
//we use backtracking
//we store the combos for the digit at phone number in a hashmap
//we recursively call the function for diff chars in the given number
//when the last index is reached we return
class Solution{
private:
    void findAns(string&digits,int index,string combo,vector<string>&ans,unordered_map<char,string>&Letters){
        if(index==digits.length()){
            ans.push_back(combo);
            return;
        }
        string letter = Letters.at(digits[index]);
        for(char let:letter){
            findAns(digits,index+1,combo+let,ans,Letters);
        }
    }
public:
    vector<string> letterCombinations(string digits){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<string>ans;
        if(digits.empty())return ans;
        unordered_map<char,string>Letters={
            {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
        };
        findAns(digits,0,"",ans,Letters);
        return ans;
    }
};
