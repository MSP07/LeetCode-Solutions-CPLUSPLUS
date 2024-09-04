/*approach
  we calculate the last index odd number has occured 
  and we simply return the substr from 0 to that index+1 as ans
  if only even numbers then the lastindex will be -1 so we return empty
  string else we return the substr*/
class Solution{
public:
    string largestOddNumber(string num){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int lastIndex = -1;
        for(int i=0;i<num.size();++i){
            if((num[i]-'0')%2){
                lastIndex = i;
            }
        }
        if(lastIndex == -1){
            return "";
        }
        return num.substr(0,lastIndex+1);
    }
};
