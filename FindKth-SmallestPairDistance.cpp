/*approach
  binary search
  brute force is to put two for loops and push it to
  vectors then sort it and return vector[k-1].
  optimal approach is to sort the given array and keep
  low and high pointers at 0 and last and we need to find whether
  there is count of pairs greater than or equal to k then shrink window
  to low to mid else mid+1 to high and count will be right - left.*/
class Solution{
public:
    int smallestDistancePair(vector<int>& nums,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        sort(nums.begin(),nums.end());
        int low = 0, high = nums.back() - nums.front();
        while(low<high){
            int mid = low + (high-low)/2;
            int count = 0, left = 0;
            for(int right=0;right<nums.size();++right){
                while(nums[right]-nums[low]>mid){
                    ++left;
                }
                count += right - left;
            }
            if(count>=k){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};
