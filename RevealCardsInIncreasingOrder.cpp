/*approach
  sorting, simulation
  we first the given array and then start adding elements
  we do so in the logic that the elements should fit in inside the indices that leaves no remainder
  if the sorted array is appended in this order then we will get the required answer. This can also be
  implemented using queue*/
class Solution{
public:
    vector<int> deckRevealincreasing(vector<int>& deck){
        int n = deck.size();
        vector<int>ans(n,0);
        sort(deck.begin(),deck.end());
        int i=0,j=0,k=0;
        while(j<n){
            if(ans[i%n]==0 && k==0){
                ans[i%n] = deck[j++];
                k=1;
            }else if(ans[i%n] && k==1){
                k=1;
            }else{
                k=0;
            }
            i++;
        }
        return ans;
    }
};
