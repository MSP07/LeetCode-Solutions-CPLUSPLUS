/*approach
  we first take count of all chars and their frequencies
  then we iterate through the hashmap we have stored the values
  if the count of the frequency is above 0 and it is already seen in the past
  we would have stored that in a set and we look there if so then we need a unique value
  so till we get a unseen value we reduce the count or increase the deletion and if it is not in the 
  freq set and we simply add it to the set and finally return the deleltions*/
class Solution{
public:
    int minDeletions(string s){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        unordered_map<char,int>charCount;
        unordered_set<int>freq;
        int deletions = 0;
        for(auto ch:s){
            charCount[ch]++;
        }
        for(auto& [character,count]:charCount){
            while(count>0 && freq.count(count)){
                count--;
                ++deletions;
            }
            if(count>0){
                freq.insert(count);
            }
        }
        return deletions;
    }
};
