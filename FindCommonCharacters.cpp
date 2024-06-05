//approach
//we find the count of characters given strings 
//we compare the count of char with all strings 
//if count of any char is >0 for all the given strings we add it to result vector
class Solution{
public:
    vector<string> commonChars(vector<string>& words){
        vector<int>minFreq(26,0);
        for(string word:words){
            vector<int>charCnt(26,0);
            for(char c:word){
                charCnt[c-'a']++;
            }
            for(int i=0;i<26;i++){
                minFreq[i]=min(minFreq[i],charCnt[i]);
            }
        }
        vector<string>res;
        for(int i=0;i<26;i++){
            while(minFreq[i]>0){
                res.push_back(string(1,i+'a'));
                minFreq[i]--;
            }
        }
        return res;
    }
};
