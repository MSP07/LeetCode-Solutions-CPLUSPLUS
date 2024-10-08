/*approach
  sorting
  to make all the elements equal we need to look for the median element from where all the
  other elements is min to reach in terms of addition or subtraction for that we sort and 
  choose the centre element, then we iterate through the array and caculate the abs diff
  of each element w.r.t median the reason abs is whether we add 1 or subtract 1 moves incr by 1
  so lets say median is 5 regardless whether element is 2 or 8 our moves will be 3 so abs(5-2) = abs(5-8)
  and finally we return the sum of the diff as moves*/
class Solution{
public:
    int minMoves2(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int median = nums[n/2];
        int minMoves = 0;
        for(int num:nums){
            minMoves += abs(median-num);
        }
        return minMoves;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
