//approach
//we use the xor property that gives 0 on operation with same number
//so we initially iterate and get the once appearing elements
//then we take diff in the rightmost bits of those two numbers
//we declare vector with linear space
//then we perform and operation with the elements in given array and the difference found, it that is possible then result[0] ^= num, else result[1] ^= num
//we return the vector finally
class Solution{
public:
    vector<int> singleNumber(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        long xor_res = 0;
        for(auto num:nums){
            xor_res ^= num;
        }
        long diff = xor_res & (-xor_res);
        vector<int>result(2,0);
        for(auto num:nums){
            if(num & diff)result[0] ^= num;
            else result[1] ^= num;
        }
        return result;
    }
};
