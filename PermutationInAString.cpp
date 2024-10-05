/*approach
  two pointers, hashmap, sliding window
  the idea is that if there is permutation then it will be just re arrangement of chars in s1 to s2
  so if we can find the count of chars in s1 then we can return whether they are equal or not in s2
  this checking can be done by sliding window approach*/
class Solution{
public:
    bool checkInclusion(string& s1,string& s2){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n1 = s1.size(), n2 = s2.size();
        vector<int>freq1(26,0),freq2(26,0);
        for(int i=0;i<n1;++i){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        for(int i=n1;i<n2;++i){
            if(freq1 == freq2)return true;
            freq2[s2[i]-'a']++;
            freq2[s2[i-n1]-'a']--;
        }
        return freq1  == freq2;
    }
};
