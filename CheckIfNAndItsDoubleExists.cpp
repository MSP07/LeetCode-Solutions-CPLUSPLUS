/*approach
  two pointers
  we use two for loops and check whether either of them is double of the other 
  if so we return true else we return false we can optimise this more by using 
  a hashmap and keeping track of the seen elements*/
class Solution{
public:
    bool checkIfExist(vector<int>& arr){
        for(int i=0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]==2*arr[j] || arr[j]==2*arr[i])return true;
            }
        }
        return false;
    }
};
