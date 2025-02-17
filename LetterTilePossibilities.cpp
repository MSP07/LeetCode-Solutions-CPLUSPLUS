/*approach
  hashmap,counting,string,backtracking
  given problem tends us to find all the possible combination count
  we can achieve this by first calculating the count of all chars in the given string
  storing them in a hashmap and we iterate through that hashmap and if a char has count 
  then we temporarily reduce the count and calculate the total possibilities again and then 
  change the count back to normal and finally return the manipulated count*/
class Solution{
private:
    void find(vector<int>& freq,int& cnt){
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                cnt++;
                freq[i]--;
                find(freq,cnt);
                freq[i]++;
            }
        }
    }
public:
    int numTitlePossibilities(string tiles){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int>freq(26,0);
        int cnt = 0;
        for(char c:tiles){
            freq[c-'A']++;
        }
        find(freq,cnt);
        return cnt;
    }
};
