/*approach
  hashmap, simulation
  to find no of pairs such that one is exact reverse of another
  we iterate through the strings and if any of the words reversed is
  already in that hashmap we increase the pairs else we add the org word
  to the hashmap and finally return the no of pairs*/
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int pairs = 0;
        unordered_set<string>hashi;
        for(string word:words){
            string temp = word;
            reverse(temp.begin(),temp.end());
            if(hashi.count(temp))pairs++;
            else hashi.insert(word);
        }
        return pairs;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
