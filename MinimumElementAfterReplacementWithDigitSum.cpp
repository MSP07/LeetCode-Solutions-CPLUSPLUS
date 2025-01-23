/*approach
  array
  we simply find the digit sum of every number using modulo
  and division method and keep track of the min one and finally return it*/
class Solution {
private:
    int digit(int num){
        int temp = 0;
        while(num>0){
            temp += num%10;
            num /= 10;
        }
        return temp;
    }
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int num:nums){
            mini = min(mini,digit(num));
        }
        return mini;
    }
};
