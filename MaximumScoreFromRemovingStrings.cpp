/*approach
  we first take into count which has high points x or y 
  accordingly we call function with chars that we wanna match
  in the function we keep a new string and add chars of given string to 
  the new string and if we encounter the chars order (ab for x or ba for y)
  we simply delete it and increase the points by that much and once one iteration 
  is over we update string to the new string and continue iteration
  finally we return the score calculated.
  POINT TO NOTE: this mentioned above process instead of newstring can also be 
  done with stack where we compare st.top() and pop the top element but after traversal
  the remaining chars in stack must be formed to a string and should be reversed which
  takes additional time so we use this approach*/
class Solution{
public:
    int maximumGain(string s, int x, int y){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int score = 0;

        auto process = [&](char first,char second,int points){
            string newString;
            int localScore = 0;
            for(char c:s){
                if(!newString.empty() && newString.back()==first && c==second){
                    newString.pop_back();
                    localScore += points;
                }else{
                    newString.push_back(c);
                }
            }
            s = newString;
            return localScore;
        };

        if(x>y){
            score += process('a','b',x);
            score += process('b','a',y);
        }else{
            score += process('b','a',y);
            score += process('b','a',x);
        }
        return score;
    }
};
