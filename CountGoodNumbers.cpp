//approach
//so any given n the inputs are fixed 2,3,5 or 7 for odd places and 0 2 4 6 8 for even indices
//so we simply calculate the count of odd positions and even positions and calculate 5^even + 4^odd
//alternatively to min code complexity we can also use built in pow() function but that is not as significant as this
class Solution{
private:
    long long powers(long long num,long long n){
        long long ans = 1;
        while(n>0){
            if(n%2==1){
                ans *= num;
                ans %= 1000000007;
            }
            num *= num;
            num %= 1000000007;
            n /= 2;
        }
        return ans % 1000000007;
    }
public:
    int countGoodNumbers(long long n){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        long long odd = n/2;
        long long even = n/2 + n%2;
        long long result = (powers(5,even)*powers(4,odd))%1000000007;
        return result;
    }
};
