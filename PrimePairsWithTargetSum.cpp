/*approach
  we first mark all the prime numbers within the range of n using sieve method
  then we start from 2 and go on till n/2 to find i such that both i and n-i are primes
  if found we add both of them to answer and finally return the answer*/
class Solution{
private:
    void sieve(vector<int>&isPrime,int n){
        isPrime[0] = isPrime[1] = 0;
        for(int i=2;i<n;++i){
            if(isPrime[i]){
                for(int j=2*i;j<n;j+=i){
                    isPrime[j] = 0;
                }
            }
        }
    }
public:
    vector<vector<int>> findPrimePairs(int n){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        if(n==1)return {};
        vector<int>isPrime(n,1);
        sieve(isPrime,n);
        vector<vector<int>>ans;
        for(int i=2;i<=n/2;++i){
            if(isPrime[i] && isPrime[n-i]){
                ans.push_back({i,n-i});
            }
        }
        return ans;
    }
};
