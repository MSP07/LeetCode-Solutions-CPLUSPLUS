/*approach
  declare a comparator to check whether the substring iterating is palindrome or not
  then iteratively check which is the max length and update that too.
  then iterate for both even and odd possibilities and return the substr of start pointer and maxLength pointer that was found out while iterating*/
class Solution{
public:
    string longestPalindrome(string s){
        int n = s.size();
        if(n<=1)return s;
        int start = 0, maxLen = 1;
        auto expandAroundCentre = [&](int left,int right){
            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
            }
            left++;
            right--;
            int len = right - left + 1;
            if(len>maxLen){
                start = left;
                maxLen = len;
            }
        };
        for(int i=0;i<n-1;i++){
            expandAroundCentre(i,i);
            expandAroundCentre(i,i+1);
        }
        return s.substr(start,maxLen);
    }
};
