/*approach
  simulation
  we follow the steps and for odd indices we taje ans[i/2] + ans[i/2+1] since quotient will be the index
  we mist consider for even we take ans[i/2] and keep track of the max one and return it*/
class Solution{
public:
    int getMaximumGenerated(int n){
        if(n==0)return 0;
        if(n<=2)return 1;
        if(n==3)return 2;
        vector<int>ans;
        ans.reserve(n+1);
        ans[1]=1;
        int maxi = -1;
        for(int i=2;i<=n;i++){
            if(i%2){
                ans[i] = ans[i/2] + ans[i/2+1];
            }else{
                ans[i] = ans[i/2];
            }
            maxi = max(maxi,ans[i]);
        }
        return maxi;
    }
};
