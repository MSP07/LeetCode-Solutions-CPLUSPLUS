//approach
//we first sort the given array
//we iterate throught the array
//when we come across an element that is greater than or equal to i(0 to n) then cnt will be n - position of element as the nums is sorted all the elements after that element will be obviously greater
//then we check whether cnt == i.
//if yes we return i else -1
class Solution{
public:
    int specialArray(vector<int>&nums){
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<=n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(nums[j]>=i){
                    cnt = n - j;
                    break;
                }
            }
            if(cnt == i)return i;
        }
        return -1;
    }
};
