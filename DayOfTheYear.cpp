/*approach
  array
  take out date,year,month check for leap year then change the days array
  then add the no of days till the month has arrived and return the day*/
class Solution {
public:
    int dayOfYear(string date) {
        vector<int>days = {31,28,31,30,31,30,31,31,30,31,30,31};
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));
        if((year%4==0 && year%100!=0) || (year%400==0)){
            days[1] = 29;
        }
        int ans = day;
        for(int i=0;i<month-1;i++){
            ans += days[i];
        }
        return ans;
    }
};
