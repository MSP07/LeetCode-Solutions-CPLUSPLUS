/*approach
  priority queue
  first we declare a minheap and then till we have k 
  we take the top element replace it to nums[i]*multiplier and again
  push into pq and finally return nums*/
class Solution{
public:
    vector<int> getFinalState(vector<int>& nums,int k,int multiplier){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        while(k--){
            auto temp = pq.top();
            nums[temp.second] = temp.first*multiplier;
            pq.push({nums[temp.second],temp.second});
        }
        return nums;
    }
};
