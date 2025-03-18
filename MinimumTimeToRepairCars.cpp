/*approach
  binary search
  first we take low as 1 and high as cars*cars*ranks[0] and perform
  binary search on them where carsrepair will be += sqrt(1.0*mid/rank)
  if low we shrink the search to mid+1,high else shrink to low,mid and
  finally return low*/
class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            long long low = 1, high = 1LL*cars*cars*ranks[0];
            while(low<high){
                long long mid = low + (high-low)/2, carsRep = 0;
                for(auto rank:ranks){
                    carsRep += sqrt(1.0*mid/rank);
                }
                if(carsRep<cars){
                    low = mid+1;
                }else{
                    high = mid;
                }
            }
            return low;
        }
    };
