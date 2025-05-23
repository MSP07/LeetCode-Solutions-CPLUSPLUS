/*approach
  we use hashmap to store values from highest to lowest manner with all possible int to roman
  then we iterate through the hashmap and from largest value we start adding roman to ans
  and simulataneously remove that exact val from integer we do this till num is exhausted
  and finally we return the ans string*/
class Solution{
public:
    string intToRoman(int num){
        vector<pair<int,string>>values = {
            {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},
            {90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}
        };
        string ans = "";
        for(auto& val:values){
            while(num>=val.first){
                ans += val.second;
                num -= val.first;
            }
        }
        return ans;
    }
};
