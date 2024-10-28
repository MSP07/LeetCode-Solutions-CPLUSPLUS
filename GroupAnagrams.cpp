/*approach
  hashmap, sorting
  two strings are anagrams if both their frequencies are equal if we implement that approach it will take more
  time and space so instead for every string given in vector we sort that string and mark it as an anagram for the 
  original string that was there before sorting and finally append all such anagrams in an ans vector and finally return it*/
class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        unordered_map<string,vector<string>>anagram;
        for(string str:strs){
            string temp = str;
            sort(temp.begin(),temp.end());
            anagram[temp].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto it:anagram){
            ans.push_back(it.second);
        }
        return ans;
    }
};
