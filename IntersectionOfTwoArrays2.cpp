/*approach
  we first sort the given two arrays
  then we start from beginning of the two arrrays and iterate till we meet either one of ends
  we iterate till we find equal elements like if first array element is less then move to next
  else second array element is less then move its pointer to next element and when equal element found
  we add it to answer and return finally*/
class Solution{
public:
    vector<int> intersect(vector<int>& nums1,vector<int>& nums2){
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>intersectedArray;
        int i = 0, j = 0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                i++;
            }else if(nums1[i]>nums2[j]){
                j++;
            }else{
                intersectedArray.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return intersectedArray;
    }
};
