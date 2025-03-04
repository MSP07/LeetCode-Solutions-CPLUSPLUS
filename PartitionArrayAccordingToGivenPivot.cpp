/*approach
  linear traversal, two pointers, simulation
  we need to preserve the order in which the elements appear in the org array
  so we do three traversals it will be 0(3n) first traversal we take elements < pivot
  next one elements == pivot and finally elements > pivot append them to an ans array and return it
  to do this in one traversal we can use linear search and 3 arrays while traversing if elements less than
  comes we append that to first array and if equal to then append to second array and finally greater to third array
  we combine three arrays and return the answer since the combined array length will be equal to org array size will be 0(n)*/
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;
        for(int num:nums){
            if(num<pivot){
                ans.push_back(num);
            }
        }
        for(int num:nums){
            if(num==pivot){
                ans.push_back(num);
            }
        }
        for(int num:nums){
            if(num>pivot){
                ans.push_back(num);
            }
        }
        return ans;
    }
};
