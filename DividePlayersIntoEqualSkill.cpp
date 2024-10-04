/*approach
  sorting, two pointer
  first we sort the given array 
  and we keep two pointers one at start and another at end of the array the sum of them both
  if the target as anything less than that means a element will be definitely left out so we keep
  that as sum and for every pair nums[left],nums[right] we check whether their sum is equal to the target
  if not we return -1 else we multiply them and add it to the answer*/
class Solution{
public:
    long long dividePlayers(vector<int>& skill){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        if(skill.size()==2)return skill[0]*skill[1];
        long long chemistry = 0;
        sort(skill.begin(),skill.end());
        int left = 0, right = skill.size()-1;
        long long sum = skill[left] + skill[right];
        while(left<right){
            long long currSum = skill[left] + skill[right];
            if(currSum != sum){
                return -1;
            }else{
                chemistry += (skill[left]*skill[right]);
            }
        }
        return chemistry;
    }
};
