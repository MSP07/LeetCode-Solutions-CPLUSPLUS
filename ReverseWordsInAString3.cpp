/*approach
  string, two pointers
  to solve this efficiently we start from first char and iterate till we end up at ' ' or last char
  when we end up there instead of keeping all the prev char in temp string and reversing it we can simply
  keep another pointer at the index before to i and start pushing that into ans so it is stored in reverse order
  else if the index is last we need to make sure that pointer is pointed to last char instead of before index so as to push
  the last word fully into ans string from last manner and if we come across a ' ' we simply leave a ' ' in ans string too
  and finally return the ans string*/
class Solution{
public:
    string reverseWord(string s){
        int n = s.size();
        string ans = "";
        int i=0;
        while(i<n){
            if(i==n-1 || s[i]==' '){
                int j = i-1;
                if(i==n-1)j++;
                while(j>=0 || s[j]!=' '){
                    ans += s[j];
                    j--;
                }
                if(s[i]==' ')ans.push_back(' ');
            }
            i++;
        }
        return ans;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
