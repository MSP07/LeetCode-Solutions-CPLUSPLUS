/*approach
  string, string matching
  given we need to find two strings wrods[i] and words[j] in
  words such that words[i] is both prefix and suffix of words[j]
  and i<j we can run two for loops for i<j condition and a bool function
  where we compare the prefix substring and suffix substring of the two strings
  if str1.size() > str2.size() we return false and we return true if str1 is both
  prefix and suffix and we keep count of such pairs and return it*/
class Solution{
private:
    bool isPrefixAndSuffix(string& str1,string& str2){
        if(str1.size()>str2.size())return false;
        if(str2.substr(0,str1.size())!=str1)return false;
        if(str2.substr(str2.size()-str1.size())!=str1)return false;
        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words){
        int indices = 0;
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                if(isPrefixAndSuffix(words[i],words[j]))indices++;
            }
        }
        return indices;
    }
};
