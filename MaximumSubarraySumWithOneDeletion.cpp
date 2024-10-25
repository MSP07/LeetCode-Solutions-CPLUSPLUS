/*approach
  dp
  we keep track of sum that will be max with deletion and another with max without deletion
  max with deletion we take max of max without deletion or max with deletion with curr element
  max without deletion we take max of max without deletion + curr element or curr element
  and we keep track of max of both of them and finally return it*/
class Solution{
public:
    int maximumSum(vector<int>& arr){
        int maxWithDel = 0, maxWithoutDel = arr[0], maxi = arr[0];
        for(int i=1;i<arr.size();++i){
            maxWithDel = max(maxWithoutDel,maxWithDel+arr[i]);
            maxWithoutDel = max(maxWithoutDel+arr[i],arr[i]);
            maxi = max({maxi,maxWithDel,maxWithoutDel});
        }
        return maxi;
    }
};
