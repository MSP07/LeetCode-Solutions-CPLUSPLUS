//approach
//since division is not allowed we will make two new vectors one for leftside product and another for rightside product
//for a given element we find leftside product, rightside product for that respective element and multiply them both and store in new result and return
class Solution{
public:
    vector<int> productExceptSelf(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        vector<int>leftProduct(n,1);
        vector<int>rightProduct(n,1);
        vector<int>result(n,1);
        for(int i=1;i<n;i++){
            leftProduct[i] = leftProduct[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            rightProduct[i] = rightProduct[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            result[i] = leftProduct[i]*rightProduct[i];
        }
        return result;
    }
};
