/*approach
  we need to find an array that gives us the sum = mean*(m+n) - sum of given array
  if that sum is less than n or greater than possible 6*n then we return {} else
  we adjust target to target -=n and we choose to add either 5 or target whomever is min
  then we add that to ans array and remove that from target and finally return ans array*/
class Solution{
public:
    vector<int> missingRolls(vector<int>& rolls,int mean,int n){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int>missingObservations(n);
        int m = rolls.size();
        int sum = (m+n)*(mean);
        int alreadyHave = accumulate(rolls.begin(),rolls.end(),0);
        int target = sum - alreadyHave;
        if(target<n || target > 6*n){
            return {};
        } 
        target -= n;
        for(int i=0;i<n&&target>0;++i){
            int add = min(5,target);
            missingObservations[i] += add;
            target -= add;
        }
        return missingObservations;
    }
};
