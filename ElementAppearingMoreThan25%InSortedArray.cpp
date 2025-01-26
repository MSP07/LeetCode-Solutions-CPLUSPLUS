/*approach
  array, sorting
  since given is a sorted array instead of using hashmap we can take advantage of the fact that 
  for an element to appear 25% in a sorted array then arr[i] and arr[i+size] (where size = 25% of 
  size of an array) will be same and so we use that to find the ans in one traversal rather than
  two if we use hashmap*/
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int size = arr.size()/4;
        for(int i=0;i<arr.size()-size;i++){
            if(arr[i]==arr[i+size])return arr[i];
        }
        return -1;   
    }
};
  
