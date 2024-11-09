/*approach
  greedy, sorting
  start by starting array and iterate every 2 spaces so as to count the pairs
  then for every pair we incr the count by the min of both of them since we are sorting
  and iterating we take nums[i] and finally return the count*/
class Solution{
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i=0;i<nums.size();i+=2){
            sum += nums[i];
        }
        return sum;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
