/*approach
  we use a hashmap to count the frequency of chars
  then we use another array to push char and its occurences
  then we sort the array in decending order. then we finally 
  append them inside a string as per the sorted order and return it*/
class Solution{
public:
    string frequencySort(string s){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        unordered_map<char,int>charCount;
        string ans = "";
        for(char c: s){
            charCount[c]++;
        }
        vector<pair<int,char>>freqCount;
        for(auto& entry:charCount){
            freqCount.push_back({entry.second,entry.first});
        }
        sort(freqCount.begin(),freqCount.end(), [](const pair<int,char>& a,const pair<int,char>& b){
            return b.first < a.first;
        }); 
        for(auto& freq:freqCount){
            ans.append(freq.first,freq.second);
        }
        return ans;
    }
};
