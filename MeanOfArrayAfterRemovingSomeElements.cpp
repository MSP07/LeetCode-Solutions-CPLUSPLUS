/*approach
  sorting
  to find the mean we first sort then find the 5 percent
  and we only sum the between elements excluding first 5 percent
  and last 5 percent and keep track of size finally returning the sum/cnt*/
class Solution{
public: 
    double trimMean(vector<int>& arr){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        sort(arr.begin(),arr.end());
        double ans = 0;
        int begin = arr.size()*0.05,cnt = 0;
        for(int i=begin;i<arr.size()-begin;i++){
            ans += arr[i];
            cnt++;
        }
        return ans/cnt;
    }
};
