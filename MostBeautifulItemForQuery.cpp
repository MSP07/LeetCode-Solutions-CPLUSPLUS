/*approach
  binary search, sorting
  first we sort the items array ascending order for our convenience and modify the items array
  [price,beauty] we keep the max beauty for the particular price everywhere in the array then for
  each query[i] we find the max Beauty such that price<=query[i] using binary search if the price
  is greater than query[i] shrink the window to left else find the max beauty by shrinking to right
  and right and finally return that beauty*/
class Solution{
private:
    int bs(vector<vector<int>>& items,int target){
        int low = 0, high = items.size()-1;
        int beauty = 0;
        while(low<=high){
            int mid = low+ (high-low)/2;
            if(items[mid][0]>target){
                high = mid-1;
            }else{
                beauty = max(beauty,items[mid][1]);
                low = mid+1;
            }
        }
        return beauty;
    }
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,vector<int>& queries){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = queries.size();
        vector<int>ans(n);
        sort(items.begin(),items.end());
        int maxi = items[0][1];
        for(int i=1;i<items.size();++i){
            maxi = max(maxi,items[i][1]);
            items[i][1] = maxi;
        }
        for(int i=0;i<n;++i){
            ans[i] = bs(items,queries[i]);
        }
        return ans;
    }
};
