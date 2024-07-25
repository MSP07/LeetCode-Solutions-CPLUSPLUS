/*approach
  divide and conquer
  merge sort - we divide given array into two bits
  and then we compare the two divided arrays and place the 
  elements accordingly*/
class Solution{
private:
    void merge(vector<int>& nums,int left,int mid,int right){
        int n1 = left - mid + 1;
        int n2 = right - mid;
        vector<int>leftArray(n1);
        vector<int>rightArray(n2);
        int i = 0, j = 0, k = left;
        while(i < n1 && j < n2){
            if(leftArray[i]<=rightArray[j]){
                nums[k] = leftArray[i];
                i++;
            }else{
                nums[k] = rightArray[j];
                j++;
            }
            k++;
        }
        while(i < n1){
            nums[k] = leftArray[i];
            i++;
            k++;
        }
        while(j < n2){
            nums[k] = rightArray[j];
            j++;
            k++;
        }
    }
    void mS(vector<int>& nums,int low,int high){
        if(low>=high)return;
        int mid = low + (high-low)/2;
        mS(nums,low,mid);
        mS(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
public:
    vector<int> sortArray(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        mS(nums,0,nums.size()-1);
        return nums;
        //easy way
        sort(nums.begin(),nums.end());
        return nums;
    }
};
