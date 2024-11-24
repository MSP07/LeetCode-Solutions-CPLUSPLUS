/*approach
  simulation,array
  aim is to find the element that has k wins
  to do that we start by keeping arr[0] as base and we compare all the
  elements in the array and if the base is greater than all then we increase the winStreak
  else we update the base and winStreak and at any time winStreak equals k we return the element
  in end also we return the last updated base as there is a chance that k is greater than n*/
class Solution{
public:
    int getWinner(vector<int>& arr,int k){
        int n = arr.size();
        int winStreak = 0, curr=arr[0];
        for(int i=1;i<n;i++){
            if(curr>arr[i]){
                ++winStreak;
            }else{
                winStreak = 1;
                curr = arr[i];
            }
            if(winStreak==k)return curr;
        }
        return curr;
    }
};
