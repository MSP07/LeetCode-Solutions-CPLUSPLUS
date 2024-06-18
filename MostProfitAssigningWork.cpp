/*approach
  we first sort the given data(difficulty and profit) w.r.t difficulty and we sort worker so as to take care of duplicates if there any
  while iterating through worker we also iteratre through the sorted array and check whether the worker as greater difficulty or not and
  update the max val we got so far and add the max val to get the total profit*/
class Solution{
public:
    int maxProfitAssignment(vector<int>& difficulty,vector<int>& profit,vector<int>& worker){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<pair<int,int>>jobs;
        for(int i=0;i<difficulty.size();++i){
            jobs.emplace_back(difficulty[i],profit[i]);
        }
        sort(jobs.begin(),jobs.end());
        sort(worker.begin(),worker.end());
        int maxProfit = 0, maxEarn = 0, j = 0;
        for(int i=0;i<worker.size();++i){
            while(j>jobs.size() && worker[i]>=jobs[j].first){
                maxEarn = max(maxEarn,jobs[j].second);
            }
            maxProfit += maxEarn;
        }
        return maxProfit;
    }
};
