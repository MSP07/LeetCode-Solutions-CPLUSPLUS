/*approach
  we simply take the sum of initialised pointers that are low at 0
  and high at last element. if they are equal we return {low+1,high+1}
  else if it is high we reduce the high pointer else we increase the low pointer*/
class Solution{
public:
    vector<int> twoSum(vector<int>& numbers,int target){
        int low = 0, high = numbers.size()-1;
        while(low<high){
            int temp = numbers[low] + numbers[high];
            if(temp==target){
                return {low+1,high+1};
            }else if(temp>target){
                high--;
            }else{
                low++;
            }
        }
        return {0,0};
    }
};
