/*approach
  string
  from the entire format we calculate how much leap year and accordingly take 
  365 or 366 days and add that many days to answer and add the remaining days
  and finally return the ans*/
class Solution {
private:
    bool isLeap(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    int daysFromStart(string date) {
        int year, month, day;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int totalDays = 0;
        for (int y = 1971; y < year; y++) {
            totalDays += isLeap(y) ? 366 : 365;
        }
        for (int m = 0; m < month - 1; m++) {
            totalDays += daysInMonth[m];
            if (m == 1 && isLeap(year)) totalDays++; 
        }
        totalDays += day;
        return totalDays;
    }
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(daysFromStart(date1) - daysFromStart(date2));
    }
};
