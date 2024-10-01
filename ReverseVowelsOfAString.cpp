/*approach
  two pointers
  we start from left at 0 index and right at last index then till we find a vowel we incr and decr them
  then we swap the vowels and finally return the string*/
class Solution{
private:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
public:
    string reverseVowels(string s){
        int left = 0, right = s.size()-1;
        while(left<right){
            while(left<right && !isVowel(s[left])){
                left++;
            }
            while(left<right && !isVowel(s[right])){
                right--;
            }
            if(left<right){
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};
