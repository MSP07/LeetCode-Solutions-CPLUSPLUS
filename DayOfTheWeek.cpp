/*approach
  we use the inbuilt function and read the time and return
  it to the given date's corresponding day*/
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year){
        tm date = {0, 0, 0, day, month - 1, year - 1900};
        mktime(&date);
        const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        return days[date.tm_wday];
    }
};
