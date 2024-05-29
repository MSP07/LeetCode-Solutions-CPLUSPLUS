//approach
//two pointer approach
//we iterate through haystack and we search for indices from which to the length of substring of needle 
//if that equals to needle then we return the index
//else we return -1
class Solution{
public:
    int strStr(string haystack,string needle){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        if(haystack.length()<needle.length())return -1;
        for(int i=0;i<=haystack.length()-needle.length();i++){
            if(haystack.substr(i,needle.length())==needle)return i;
        }
        return -1;
    }
};
