/*approach
  instead of iterating over and over again we find the value that needs to checked for one iteration
  that will be k % totalSum and with this val we iterate once if at some point k becomes less than chalk[i]
  then that index student must replace it else we simpl chalk[i] from k*/
class Solution{
public:
    int chalkReplacer(vector<int>& chalk,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        long long sum = accumulate(chalk.begin(),chalk.end(),0LL);
        k %= sum;
        for(int i=0;i<chalk.size();++i){
            if(k < chalk[i])return i;
            k -= chalk[i];
        }
        return -1;
    }
};
