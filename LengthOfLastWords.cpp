/*approach
  we only need last word there can be ' ' after the last word
  so we start from last index and till we have ' ' we reduce the pointer
  and from the char part we keep another part and reduce the pointer till we find ' ' by this
  way we cover the last word totally in second pointer and we return the len as end-start as there
  can be ' ' in the end*/
class Solution{
public:
    int lengthOfLastWord(string s){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int end = s.size()-1;
        while(end>=0 && s[end]==' '){
            end--;
        }
        int start = end;
        while(start>=0 && s[start]!=' '){
            start--;
        }
        return end-start;
    }
};
