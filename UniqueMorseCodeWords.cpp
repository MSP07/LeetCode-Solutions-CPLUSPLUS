/*approach
  keep a set and iterate through char of every word in given words and add the morse sign for every word to the set and return the set size*/
class Solution{
public:
    int uniqueMorseRepresentation(vector<string>& words){
        vector<string>morse={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string>ans;
        for(auto&word:words){
            string transformation;
            for(auto c:word){
                transformation += morse[c-'a'];
            }
            ans.insert(transformation);
        }
        return ans.size();
    }
};
