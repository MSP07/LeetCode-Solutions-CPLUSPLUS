/*approach
  hashmap
  we simply keep a hashmap and store chars at same level iterate through chars at words in the given string
  if we find any char that is not in same level with its adj char we change flag to false and if the flag is
  true alone we add that word to ans and finally return it*/
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int>level = {{'q',1},{'w',1},{'e',1},{'r',1},{'t',1},{'y',1},{'u',1},{'i',1},{'o',1},{'p',1},
        {'a',2},{'s',2},{'d',2},{'f',2},{'g',2},{'h',2},{'j',2},{'k',2},{'l',2},{'z',3},{'x',3},{'c',3},{'v',3},{'b',3},
        {'n',3},{'m',3}};
        vector<string>ans;
        for(string word:words){
            bool same = true;
            for(int i=0;i<word.size()-1;++i){
                if(level[tolower(word[i])]!=level[tolower(word[i+1])]){
                    same = false;
                    break;
                }
            }
            if(same)ans.push_back(word);
        }
        return ans;

    }
};
