/*apporach
  prefixSum
  to solve this problem efficiently in one iteration we make use of prefixSum
  and the fact that odd sum can only be produced either odd+even or even+odd 
  so we start with prefixSum 0 and since initially prefixSUm is 0 evencount is 1
  and oddcount is 0 so we iterate and add up the elements if the prefixSum till now
  or at any index is odd then it will form odd subarray with another subarray in prev 
  that had even sum so when we encounter odd sum subarray we increase the cnt by evenSum subarrays
  and similarly when we encounter evenSum subarrays we increase the cnt by oddSum subarrays and modulo them with 1e9+7
  and finally return the cnt*/
class Solution{
    int mod = 1e9+7;
public:
    int numOfSubarrays(vector<int>& arr){
        int oddSum = 0, evenSum = 1;
        int cnt = 0, prefixSum = 0;
        for(int num:arr){
            prefixSum += num;
            if(prefixSum%2){
                cnt += evenSum;
                oddSum++;
            }else{
                cnt += oddSum;
                evenSum++;
            }
            cnt %= mod;
        }
        return cnt;
    }
};
