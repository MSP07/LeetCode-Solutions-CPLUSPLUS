//approach
//keep a hashmap to store all prefixes
//check whether there is a prefix (currentSum - k) in the map
//if there exists cnt += mpp[toFind[
//else we just update the hashmap for the current value
//finally we return the cnt
class Solution{
public:
    int subarraySum(vector<int>&nums,int k){
        int n = nums.size();
        unordered_map<int,int>mpp;
        int currentSum = 0, cnt = 0;
        for(int i=0;i<n;i++){
            currentSum += nums[i];
            int toFind = currentSum - k;
            if(mpp.find(toFind)!=mpp.end()){
                cnt += mpp[toFind];
            }
            mpp[currentSum]++;
        }
        return cnt;
    }
};
