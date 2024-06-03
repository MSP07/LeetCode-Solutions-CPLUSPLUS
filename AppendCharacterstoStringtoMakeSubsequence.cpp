//approach
//we keep two pointers at start of each string
//if both are equal we move pointer at t
//we move pointer at s independently for each iteration
//after iteration the difference between length of string t and the pointer at t is the answer
class Solution{
public:
    int appendCharacters(string s,string t){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int s_ind = 0 ,t_ind = 0;
        int s_len = s.length(), t_len = t.length();
        while(s_ind<s_len && t_ind<t_len){
            if(s[s_ind]==t[t_ind])t_ind++;
            s_ind++;
        }
        return t_len - t_ind;
    }
};
