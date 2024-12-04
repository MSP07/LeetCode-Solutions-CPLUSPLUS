/*approach
  two pointers
  we check if both chars are equal or we incr the left pointer or decrease the left pointer
  by 1 and 25 respectively we get the char at str2  equivalently if so we incr the second pointer
  and at the end of the iteration if the second pointer is at the last index of the str2 then we can
  successfully make a subsequence else we cannot*/
class Solution{
public:
    bool canMakeSubsequence(string str1,string str2){
        int n = str1.size(), m=str2.size();
        if(n<m)return false;
        int j=0;
        for(int i=0;i<n;i++){
            if(str1[i]==str2[j] || str1[i]+1==str2[j] || str1[i]-25 == str2[j]){
                j++;
            }
        }
        return j==m;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
