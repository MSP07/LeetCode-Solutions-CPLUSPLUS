/*approach
  sorting
  add all elements to a vector sort them and return ans[k-1] because we need kth smallest element 
  not kth distinct element
  else we can use priority queue and push elements accordingly w.r.t k and find the kth smallest element*/
class Solution{
public:
    int kthSmallest(vector<vector<int>>& matrix,int k){
        vector<int>ans;
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[i].size();++j){
                ans.push_back(matrix[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};
