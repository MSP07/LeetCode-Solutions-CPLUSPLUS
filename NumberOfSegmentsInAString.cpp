/*approach
  simulation
  we keep a bool flag and whenever the char is not a ' ' we change the flag
  to true inicating that we are currently at a word and incr the cnt. else
  we come across ' ' we simply change the flag to false and finally after 
  complete iteration we return the cnt*/
class Solution{
public:
    int countSegments(string s){
        int cnt = 0;
        bool inSeg = false;
        for(char c:s){
            if(c!=' '){
                if(!inSeg){
                    inSeg = true;
                    cnt++;
                }
            }else{
                inSeg = false;
            }
        }
        return cnt;
    }
};
