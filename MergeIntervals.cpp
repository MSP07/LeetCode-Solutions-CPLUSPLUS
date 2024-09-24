/*approach
  we first sort the given array w.r.t the first element of all sub vectors inside the vector
  then we initialise a vector with first element of intervals we iterate on intervals if we find that
  curr index first element is less than our initialised vector second element then there is a overlap
  so we change initalised vector's second element to max of initialised second element or curr index second element
  if not there is no overlap so we add the initialised vector to ans and update the initialisation to current index vector and continue
  after full iteration we add the last initialised vector to ans and return the ans*/
class Solution{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        int n = intervals.size();
        if(n==1)return intervals;
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
            return a[0] < b[0];
        });
        vector<vector<int>>ans;
        vector<int>currInterval = intervals[0];
        for(int i=1;i<n;++i){
            if(currInterval[1]>intervals[i][0]){
                currInterval[1] = max(currInterval[1],intervals[i][1]);
            }else{
                ans.push_back(currInterval);
                currInterval = intervals[i];
            }
        }
        ans.push_back(currInterval);
        return ans;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
