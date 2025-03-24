/*approach
  sorting
  we first sort the given array and the start and end will be[0] and [1] element
  we will count free as start-latest-1 and keep track of max latest and finally
  add days-latest to the free variable and return the free as ans*/
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int free = 0, latest = 0;
        sort(meetings.begin(),meetings.end());
        for(auto& meeting:meetings){
            int start = meeting[0], end = meeting[1];
            if(start>latest+1){
                free += start-latest-1;
            }
            latest = max(latest,end);
        }
        free += days - latest;
        return free;
    }
};
