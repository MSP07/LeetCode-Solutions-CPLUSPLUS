/*approach
  priority queue, simulation
  our task is to leave the sqrt of the highest number after every iteartion
  so we use a maxHeap that keeps max numbers at the top and then we  replace 
  the org numbers with their sqrt for k times and then find calculate their
  total and return it finally*/
class Solution{
public:
    long long pickGifts(vector<int>& gifts,int k){
        long long leftbehind = 0;
        priority_queue<int>maxHeap(gifts.begin(),gifts.end());
        while(k-->0){
            const int maxi = sqrt(maxHeap.top());
            maxHeap.push(maxi);
        }
        while(!maxHeap.empty()){
            leftbehind += maxHeap.top();
            maxHeap.pop();
        }
        return leftbehind;
    }
};
