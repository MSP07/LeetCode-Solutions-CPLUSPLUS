/*approach
  sorting
  after sorting the first pair difference will be min diff
  and after that we compare consec pairs and if any matches the min diff
  we add that to ans vector and finally return it*/
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        int mini = INT_MAX;
        for(int i=1;i<arr.size();i++){
            mini = min(mini,arr[i]-arr[i-1]);
        }
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]==mini){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};
