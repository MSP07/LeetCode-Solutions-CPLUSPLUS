/*approach
  greedy approach
  we first take count on char in given string
  then we sort them in descending order to know the highest
  then to calculate no of presses we iterate through the vector
  and if we see a non-element we break else we update presses
  and finally we return the presses*/
class Solution{
public:
    int minimumPushes(string word){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int>letterCount(26,0);
        for(char c:word){
            letterCount[c-'a']++;
        }
        sort(letterCount.rbegin(),letterCount.rend());
        int presses = 0;
        for(int i=0;i<26;++i){
            if(letterCount[i]==0)break;
            presses += (i/8+1)*letterCount[i];
        }
        return presses;
    }
};
