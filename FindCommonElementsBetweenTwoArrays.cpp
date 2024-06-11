/*approach
  use a set and insert values of given two vectors 
  if any values of first vector found in second set cnt1++ and any val of second vector found in first set cnt2++
  return cnt1 and cnt2*/
class Solution{
public:
    vector<int> findIntersectionValues(vector<int>& nums1,vector<int>& nums2){
        int cnt1 = 0, cnt2 = 0;
        unordered_set<int>set1(nums1.begin(),nums1.end());
        unordered_set<int>set2(nums2.begin(),nums2.end());
        for(int num:nums1){
            if(set2.find(num)!=set2.end())cnt1++;
        }
        for(int num:nums2){
            if(set1.find(num)!=set1.end())cnt2++;
        }
        return {cnt1,cnt2};
    }
};
