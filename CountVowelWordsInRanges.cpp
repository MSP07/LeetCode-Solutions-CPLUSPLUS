/*approach
  prefixsum, string
  we start by counting the no of strings that contain vowels from first word to ith word in words
  and then we use the prefix array and iterate again in queries array and calculate the no of vowel words
  from li to ri and append it to result vector/array and finally reutnr it*/
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = words.size();
        vector<int>prefix(n,0);
        auto isVowel = [](char ch){
            return (ch=='a') || (ch=='e') || (ch=='i') || (ch=='o') || (ch=='u');
        };
        prefix[0] = (isVowel(words[0][0]) && isVowel(words[0].back())) ? 1 : 0;
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + ((isVowel(words[i][0])&& isVowel(words[i].back())) ? 1 : 0);
        }
        vector<int>result;
        for(auto& query:queries){
            int li = query[0], ri=query[1];
            int count = prefix[ri] - (li>0 ? prefix[li-1] : 0);
            result.push_back(count);
        }
        return result;
    }
};
