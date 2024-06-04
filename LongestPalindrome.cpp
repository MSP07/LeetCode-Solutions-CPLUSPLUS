//approach
//we iterate through the given string and keep a set
//when we find the char in the set that means we have another duplicate of the particular char so there can be plaindrome hence len += 2;
//we erase it and increase the len
//else we add the char to the set
//after that if the charSet is not empty then there is no duplicate for that so it will be the centre of palindrome hence len += 1
//finally we return the len
class Solution{
public:
    int longestPalindrome(string s){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(s.length()==1)return 1;
        unordered_set<char>charSet;
        int len = 0;
        for(char c:s){
            if(charSet.find(c)!=charSet.end()){
                charSet.erase(c);
                len += 2;
            }else charSet.insert(c);
        }
        if(!charSet.empty()) len += 1;
        return len;
    }
};
