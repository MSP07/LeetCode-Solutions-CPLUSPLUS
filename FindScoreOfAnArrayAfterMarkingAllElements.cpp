/*approach
  sorting, hashmap
  first we add all the elements with their indices and sort them based on the elements 
  then we take the smallest or the first element and add it to the ans and then we mark
  the indices of index+1 and index-1 of that element's index to ensure that it does not go
  out of bound we take the max of (0,index-1) and min of (index+1,n-1) and finally return 
  the ans saving space and time*/
class Solution{
public:
    long long findScore(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        long long ans = 0;
        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++){
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end());
        vector<int>marked(n,0);
        for(int i=0;i<n;i++){
            if(!marked[temp[i].second]){
                ans += temp[i].first;
                marked[temp[i].second]=1;
                marked[max(0,temp[i].second-1)]=1;
                marked[min(temp[i].second+1,n-1)]=1;
            }
        }
        return ans;
    }
};
