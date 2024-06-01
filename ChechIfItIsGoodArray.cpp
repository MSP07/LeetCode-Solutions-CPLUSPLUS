//approach
//we iterate through the array while checking for gcd of the previous element(s) with current
//whenever the gcd becomes 1 then it means there are no common divisors between the element and the previous ones so somehow we can make the result 1 
//else then there is atleast one common divior between all the elements meaning any operations will end up in 0.
class Solution{
public:
    bool isGoodArray(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int g = 0;
        for(auto num:nums){
            g = __gcd(num,g);
            if(g==1)return true;
        }
        return false;
    }
};
