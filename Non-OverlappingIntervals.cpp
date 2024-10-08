/*approach
  sorting,greedy
  we first sort the array based on the end value of range so as to detect overlapping easily
  then we keep first range end as start val then check whether any range's [0] val is less than
  this start if so then there will be a overlap so we incr the count and since i pointer will be
  iterating we dont need to spend time on removing that range. If not then that particular range's
  end val will be the limit and we will update our start to that, we do this till we exhaust our array
  and finally return the min no of intervals to be removed*/
class Solution{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
            return a[1] < b[1];
        });
        int minIntervals = 0;
        int start = intervals[0][1];
        for(int i=1;i<intervals.size();++i){
            if(intervals[i][0]<start){
                ++minIntervals;
            }else{
                start = intervals[i][1];
            }
        }
        return minIntervals;
    }
};
