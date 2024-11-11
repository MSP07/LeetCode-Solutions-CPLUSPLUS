/*appproach
  sieve method, two pointers
  since 1000 is the constraint we first find prime numbers till 1000 using sieve method
  then start iterating in nums if nums[i] < nums[i+1] already in increasing sequence so we
  continue else we keep a flag and reduce the element from that prime numbers and find whether
  reducing any prime number from it makes it increasing when it does we change the flag and after the
  iteration if there is a flag it means we cannot make it an increasing sequence so we return else 
  and if all the elements can be changed without this interruption finally we return true*/
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> prime(1000,true);
        for(int i=2;i *i<1000;i++){
            if(prime[i]){
                for(int j=2;j*i<1000;j++){
                    prime[j*i]=false;
                }
            } 
        }
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1])
            continue;
            else{
                bool flag=true;
                for(int j=2;j<nums[i];j++){
                    if(prime[j] && (nums[i]-j)<nums[i+1]){
                        nums[i]=nums[i]-j;
                        flag=false;
                        break;
                    }
                }
                if(flag)
                return false;
            }
        }
        return true;
    }
};
const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
