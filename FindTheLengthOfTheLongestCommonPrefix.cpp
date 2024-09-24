/*approach
  hashmap approach
  we first count all the prefixes of nums we have in arr1 
  then we start iterating in arr2 by calculating the no of digits in each num
  we iterate till we exhaust that num w.r.t len of that num and since we start with the whole num and
  we are calculating largest if at any point we find that prefix of num in arr2 in the hashmap we stored 
  our num in arr1 we break and update longestPrefix else we iterate next prefix by num /= 10 and len--
  till we find one and finally return the longestPrefix*/
class Solution{
public:
    int longestCommonPrefix(vector<int>& arr1,vector<int>& arr2){
        unordered_map<int,int>prefixNum;
        for(int num:arr1){
            while(num>0){
                prefixNum[num]++;
                num /= 10;
            }
        }
        int longestPrefix = INT_MIN;
        for(int num:arr2){
            int len = log10(num)+1;
            while(len>0){
                if(prefixNum.find(num)!=prefixNum.end()){
                    break;
                }
                num /= 10;
                --len;
            }
            longestPrefix = max(longestPrefix,len);
        }
        return longestPrefix;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
