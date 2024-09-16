/*approach
  we first convert the given time all to minutes and store it in a array
  then we sort that array and wecalculate min difference between two
  consecutive times minutes[1] - minutes[0] ...... and we consider the min
  from these to overall turnaround time which will be 24*60 + minutes.front() - minutes.back()
  and we return the min of them*/
class Solution{
public:
    int findMinDifference(vector<string>& timePoints){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = timePoints.size();
        vector<int> minutes(n);

        for(int i=0;i<n;++i){
            int hrs = stoi(timePoints[i].substr(0,2));
            int mins = stoi(timePoints[i].substr(3));
            minutes[i] = hrs * 60 + mins;
        }

        sort(minutes.begin(),minutes.end());
        int minDiff = INT_MAX;
        for(int i=0;i<n-1;++i){
            minDiff = min(minDiff,minutes[i+1]-minutes[i]);
        }

        minDiff = min(minDiff,24*60+minutes.front()-minutes.back());
        return minDiff;
    }
};
