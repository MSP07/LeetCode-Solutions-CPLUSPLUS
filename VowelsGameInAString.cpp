/*approach
  the approach is if there are 0 vowels in the initial string then only
  bob can win else if it is odd or any even number except 0 then alice
  will reduce max odd vowels and make it to 1 eventually she will win*/
class Solution{
private:
    void vowelCnt(string&s,int&cnt){
        for(char c:s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                ++cnt;
            }
        }
    }
public:
    bool doesAliceWin(string s){
        int cnt = 0;
        vowelCnt(s,cnt);
        return cnt != 0;
    }
};
