/*approach
  two pointer, simulation
  we keep two pointers one at start and another at end 
  we convert them to string first to concatenate and convert them again
  to integer to take the sum and if the pointers or not at the centre or not equal
  we concatenate both nums[i] and nums[j] and move pointer else we append only nums[i]
  and finally return the sum*/
class Solution {
    public:
        long long findTheArrayConcVal(vector<int>& nums) {
            long long ans = 0;
            int i = 0, j = nums.size()-1;
            while(i<=j){
                string help = "";
                if(i!=j){
                    help += to_string(nums[i]);
                    help += to_string(nums[j]);
                    i++;j--;
                }else{
                    help += to_string(nums[i]);
                    i++;j--;
                }
                ans += stoi(help);
                help = "";
            }
            return ans;
        }
    };
