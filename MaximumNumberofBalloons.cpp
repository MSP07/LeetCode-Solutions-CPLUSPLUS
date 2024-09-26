/*approach
  we simply take the count of chars in Balloons in the
  given string text*/
class Solution{
public:
    int maxNumberofBalloons(string text){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int>v(26,0);
        for(int i=0;i<text.size();++i){
            v[text[i]-'a'];
        }
        int mini = v[1];
        mini = min(v[0],mini);
        mini = min(v[11]/2,mini);
        mini = min(mini,v[14]/2);
        mini = min(mini,v[13]);
        return mini;
    }
};
