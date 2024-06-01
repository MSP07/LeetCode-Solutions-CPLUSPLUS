//approach
//we find the missing number that should be multiplied to nums[i] to make it divisible by k
//that number is k/gcd(numa[i],k);
//we use hashmap to find that number
class Solution{
public:
    long long countPairs(vector<int>& nums,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int,int>factorCnt;
        long long res = 0;
        int prevCnt = 0;
        for(int i=0;i<nums.size();i++){
            int factor = gcd(nums[i],k);
            int missing = k/factor;
            if(missing==1)res += prevCnt;
            else{
                for(auto it=factorCnt.begin();it!=factorCnt.end();it++){
                    if(it->first%missing==0)res += it->second;
                }
            }
            factorCnt[factor]++;
            prevCnt++;
        }
        return res;
    }
};
