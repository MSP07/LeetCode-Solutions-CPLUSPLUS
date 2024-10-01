/*approach
  hashmap
  we first take count of all remainders w.r.t k then adjust it and add them if it is negative
  if there are even no of 0 remainders then there can be pairs else there cant be then we return false
  and consider 12,13 k = 5 12%5 == 2 and 13%5 == 3 now sum of their modulo is divisible by k this means
  12,13 pair when summed up is also divisible by k so we check for this too if the rem_count[i] != rem_count[k-i] 
  then we return false if all these conditions are met then we return true*/
class Solution{
public:
    bool canArrange(vector<int>& arr,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int>remainder_count(k,0);
        for(int num:arr){
            int rem = num%k;
            if(rem<0){
                rem += k;
            }
            remainder_count[rem]++;
        }
        if(remainder_count[0]%2)return false;
        for(int i=1;i<=k/2;++i){
            if(remainder_count[i] != remainder_count[k-i]){
                return false;
            }
        }
        return true;
    }
};
