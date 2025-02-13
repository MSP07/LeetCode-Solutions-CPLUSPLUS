/*approach
  priority queue, simulation
  with the help of priority queue(minheap) we take first two elements
  and do the given, increase the steps operation push them back
  to priority queue until the top element is less than k. if its
  greater then we return the steps as the req condition is met*/
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq(nums.begin(),nums.end());
        int steps = 0;
        while(pq.top()<k){
            if(pq.size()<2)break;
            long long x = pq.top();pq.pop();
            long long y = pq.top();pq.pop();
            long long add = min(x,y)*2+max(x,y);
            steps++;
            pq.push(add);
        }
        return steps;
    }
};
