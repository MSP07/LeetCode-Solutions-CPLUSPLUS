/*approach
  two pointers
  first we start by identifying start and end points of subarray not sorted
  we do that by traversing from left to right and finding the point where curr element is greater than next
  if no such point then the array is sorted so we return 0 and again we traverse from last finding a point
  where curr element is smaller than prev element and then for cases where there will be repeated elements
  we find min and max elements in that subarray and with that help we include outside elements of the array
  so that sorting can be done correctly and adjust the left and right pointers to that accordingly and return the length*/
class Solution{
public:
    int findUnsortedSubarray(vector<int>& nums){
        int n = nums.size();
        int left = 0, right = n-1;
        while(left<n-1 && nums[left]<=nums[left+1]){
            left++;
        }
        if(left==n-1){
            return 0;
        }
        while(right>0 && nums[right]>=nums[right-1]){
            right--;
        }
        int min_el = *min_element(nums.begin()+left,nums.begin()+right+1);
        int max_el = *max_element(nums.begin()+left,nums.begin()+right+1);
        while(left>0 && nums[left-1]>min_el){
            left--;
        }
        while(right<n-1 && nums[right+1]<max_el){
            right++;
        }
        return right-left+1;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
