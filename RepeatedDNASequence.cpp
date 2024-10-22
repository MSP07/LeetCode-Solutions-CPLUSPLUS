/*approach
  hashmap
  we take substrings of 10 length in given string and check whether they already exist if so we add them to 
  repeated hashmap else we add it to first seen hashmap and then finally we add all the repeated substrings
  to a vector and return it*/
class Solution{
public:
    vector<string> findRepeatedDnaSequence(string s){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        if(s.size()<=10)return {};
        vector<string>ans;
        unordered_set<string>seen,repeated;
        for(int i=0;i<=s.size()-10;++i){
            string temp = s.substr(i,10);
            if(seen.count(temp)){
                repeated.insert(temp);
            }else{
                seen.insert(temp);
            }
        }
        ans.assign(repeated.begin(),repeated.end());
        return ans;
    }
};
