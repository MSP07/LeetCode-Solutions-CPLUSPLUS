//approach
//we skip blank spaces
//keep sign(+) as 1 and (-) as -1
//if multiple signs come consecutively we return 0
//we keep long var res and update it as re*10+(s[i]-'0')
//we return INT_MAX and INT_MIN if sign*res is larger than or smaller than them respectively
//finally if none has been returned then we return sign*res
class Solution{
public:
    int myAtoi(string s){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int i = 0;
        int n = s.size();
        while(i<n && s[i]==' '){
            i++;
        }
        int sign = 1;
        while(i<n && (s[i]=='-'||s[i]=='+')){
            sign = (s[i]=='-') ? -1 : 1;
            i++;
        }
        while(i<n && !isdigit(s[i])){
            return 0;
        }
        long res = 0;
        while(i<n && isdigit(s[i])){
            res = res*10+(s[i]-'0');
            if(sign*res>INT_MAX)return INT_MAX;
            else if(sign*res<INT_MIN)return INT_MIN;
            i++;
        }
        return sign*res;
    }
};
