/*approach
  for each element in customers we take element at its index 0 as arrival time
  and at index 1 as preparation time. initially our time is 0 and total waiting time
  is also 0. Now if in any case the arrival time is grater than current time then we
  take into consideration the arrival time only so the current time becomes arrival time
  and we increase the currentTime by preparation time as total time
  then we update our totalWaitingTime to be += (currentTime - arrivalTime)
  then finally we return the decimal value of it*/
class Solution{
public:
    double averageWaitingTime(vector<vector<int>>& customers){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = customers.size();
        long long currentTime = 0;
        long long totalWaitingTime = 0;
        for(const auto&customer:customers){
            int arrivalTime = customer[0];
            int preparationTime = customer[1];
            if(currentTime < arrivalTime){
                currentTime = arrivalTime;
            }
            currentTime += preparationTime;
            totalWaitingTime += (currentTime - arrivalTime);
        }
        return static_cast<double>(totalWaitingTime)/n;
    }
};
