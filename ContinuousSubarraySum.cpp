//approach
//we keep a haskmap to keep track of all the prefixes encountered
//so when a visited prefix is encountered then any of the continuous past elements must be divisible by k
//if we come across something like that and its size is greater than 1 we return true
//else we update in the matrix 
//after iterating through matrix if there are no elements or prefixes like that we return false
class Solution{
public:
    bool checkSubarraySum(vector<int>&nums,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(nums.size()==1)return false;
        unordered_map<int,int>mod_map;
        mod_map[0]=-1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int ans = sum % k;
            if(mod_map.find(ans)!=mod_map.end()){
                if(i-mod_map[ans]>1)return true;
            }else mod_map[ans] = i;
        }
        return false;
    }
};
