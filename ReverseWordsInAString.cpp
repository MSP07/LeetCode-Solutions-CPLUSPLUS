/*approach
  we first reverse the entire string and then idea is to reverse the words alone and the spaces between them
  if there is space before and after the words we skip else we add them into first index then iterate we reverse
  that word and make left and right in same index then repeat this process and finally resize the s to our answer 
  without before and after spaces and return s*/
class Solution{
public:
    string reverseWords(string s){
        int n = s.size();
        reverse(s.begin(),s.end());
        int left = 0, right = 0, i = 0;
        while(i<n){
            while(i<n && s[i]==' ')i++;
            if(i==n)break;
            while(i<n && s[i]!=' '){
                s[right++] = s[i++];
            }
            reverse(s.begin()+left,s.begin()+right);
            s[right++] = ' ';
            left = right;
            i++;
        }
        s.resize(right-1);
        return s;
    }
};
