//approach
//two variables one will be increased when we encounter 1 and simultaneously another will be updated if the first variable(cnt) is more than the second one
//the second variable will be returned

class Solution{
public:
    int findMaxConsecutiveOnes(vector<int>&nums){
        int cnt = 0, maxones = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
                if(cnt>maxones)maxones = cnt;
            }else cnt = 0;
        }
        return maxones;
    }
};
