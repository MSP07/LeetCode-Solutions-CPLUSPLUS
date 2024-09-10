/*approach
  we declare a hashmap for every i 
  then we incr the count of that char 
  then we iterate through hashmap and take values of maxFreq and minFreq of chars till that i
  then we add their diff as beauty to ans and finally after full iteration we return the ans*/
class Solution{
public:
    int beautySum(string s){
        int totalBeauty = 0;
        for(int i=0;i<s.size();++i){
            vector<int>freq(26,0);
            for(int j=i;j<s.size();++j){
                freq[s[j]-'a']++;
                int maxFreq = INT_MIN, minFreq = INT_MAX;
                for(int k=0;k<26;++k){
                    if(freq[k]>0){
                        maxFreq = max(maxFreq,freq[k]);
                        minFreq = min(minFreq,freq[k]);
                    }
                }
                totalBeauty += (maxFreq - minFreq);
            }
        }
        return totalBeauty;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
