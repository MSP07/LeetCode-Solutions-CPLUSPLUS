//approach
//no odd number is perfect number till 10^5 so we return false if the given num is odd
//iterate till sqrt(num) check for the divisors and add them up
//next we iterate from sqrt(num) to 2 since 1 is already added and we add num/i if we encounter a divisor
//finally we check and return whether sum == num
class Solution{
public:
    bool checkPerfectNumber(int num){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int sum = 0;
        if(num%2!=0)return false;
        for(int i=1;i<sqrt(num);i++){
            if(num%i==0) sum += i;
        }
        for(int i=sqrt(num);i>1;i--){
            if(num%i==0) sum += num/i;
        }
        return sum==num;
    }
};
