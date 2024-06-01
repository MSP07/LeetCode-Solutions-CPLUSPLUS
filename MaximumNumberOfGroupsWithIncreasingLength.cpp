//approach
//we sort the given array as to consider the numbers with smaller usage
//then we iterate through the sorted array and initialise total = 0 and check whether sum of n+1 natural numbers encountered till the 
//ith element is greater than or equal to total.
//if it is greater then the total is large enough to increase the count
//finally we return the count
class Solution{
public:
    int maxIncreasingGroups(vector<int>& usageLimits){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        long long total = 0, count = 0;
        sort(usageLimits.begin(),usageLimits.end());
        for(int i=0;i<usageLimits.size();i++){
            total += usageLimits[i];
            if(total >= ((count+1)*(count+2))/2)count++;
        }
        return count;
    }
};
