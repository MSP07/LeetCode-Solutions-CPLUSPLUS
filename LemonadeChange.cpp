/*appraoch
  greedy
  we simply iterate keeping track of fives and tens
  any moment we cant give change we return false
  else we return true*/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int five = 0;
        int ten = 0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                five++;
            }else if(bills[i]==10){
                ten++;
                if(five>0)five--;
                else return false;
            }else{
                if(five>0 && ten>0){
                    ten--;
                    five--;
                }else if(five>=3){
                    five -= 3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
