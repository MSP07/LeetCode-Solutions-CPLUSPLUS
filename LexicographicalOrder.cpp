/*approach
  to implement this in constant space we start with 1 and iteratively calculate the 
  next children elements by the similarity The "children" of a number x are x * 10,
  x * 10 + 1, ..., x * 10 + 9 as long as they are ≤ n. After finishing possibility at 1
  we move to 2 and till n and finally return the answer*/
class Solution{
public:
    vector<int> lexicalOrder(int n){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int>ans;
        int curr = 1;
        for(int i=0;i<n;++i){
            ans.push_back(curr);
            if(curr*10<=n){
                curr *= 10;
            }else{
                while(curr%10 == 9 || curr+1 > n){
                    curr /= 10;
                }
                curr++;
            }
        }
        return ans;
    }
};
