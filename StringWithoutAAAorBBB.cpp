/*approach
  string, greedy
  if both count becomes 0 we stop till then we add chars to string
  in a,b if a>=b else b,a if b>a if a>=2 we add "aa" and a "b" if not >=2 we add "a" and "b"
  else if b>=2 we add "bb" and "a" if not >=2 we add "b" and "a" and finally return the string*/
class Solution{
public:
    string strWithout3a3b(int a,int b){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        string ans = "";
        while(a>0 || b>0){
            if(a>b){
                if(a>=2){ans+="aa";a-=2;}
                else{ans+="a";a-=1;}
                if(b>0){ans+="b";b-=1;}
            }else if(b>a){
                if(b>=2){ans+="bb";b-=1;}
                else{ans+="b";b-=1;}
                if(a>0){ans+="a";a-=1;}
            }else{
                if(a>0){ans+="a";a-=1;}
                if(b>0){ans+="b";b-=1;}
            }
        }
        return ans;
    }
};
