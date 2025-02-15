/*approach
  sorting
  we start from last with -1 as our maxi
  and on the way from right to left if we encounter another maxi
  we change maxi to that store that as max element in the arr and return it*/
class Solution{
public: 
    vector<int> replaceElements(vector<int>& arr){
        int maxi = -1;
        for(int i=arr.size()-1;i>=0;i--){
            int newmaxi = max(maxi,arr[i]);
            arr[i] = maxi;
            maxi = newmaxi;
        }
        return arr;
    }
};
