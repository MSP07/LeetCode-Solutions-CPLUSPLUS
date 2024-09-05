/*approach
  we use priority queue to keep track of max element at the top
  we first push upto elements inside the queue then compare the 
  top element for rest of array if any ele is greater than top
  then we pop the top and add that element as new top and finally
  the new top will be the largest element*/
class Solution{
public:
    int findKthLargest(vector<int>& nums,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        priority_queue<int,vector<int>,greater<int>>minHeap;
        for(int i=0;i<k;++i){
            minHeap.push(nums[i]);
        }
        for(int i=k;i<nums.size();++i){
            if(nums[i]>minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};
