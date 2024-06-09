//approach
//iterate through array find the digit
//except that add the remaining to ans
//and check whether that val is greater than the prev greater and replace it
//finally return the maxResult
class Solution{
public:
    string removeDigit(string number,char digit){
        int n = number.size();
        string maxResult = "";
        for(int i=0;i<n;i++){
            if(number[i]==digit){
                string temp = number.substr(0,i)+number.substr(i+1);
                if(temp>maxResult){
                    maxResult = temp;
                }
            }
        }
        return maxResult;
    }
};
