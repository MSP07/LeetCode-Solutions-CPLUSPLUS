/*approach
  hashmap
  we use hashmap to keep count of all elements in nums1 and nums2
  and we use them to check nums in nums1 and nums2 that are not present
  on the other one and add that to a temp and add that temp to ans and finally return it*/
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq1,freq2;
        vector<int> unq1,unq2;
        for(int num : nums1){
            freq1[num]++;
        }

        for(int num : nums2){
            freq2[num]++;
        }
        for(auto &pair : freq1){
            if(freq2.find(pair.first) == freq2.end()){
                unq1.push_back(pair.first);
            }  
        }
        for(auto &pair : freq2){
            if(freq1.find(pair.first) == freq1.end()){
                unq2.push_back(pair.first);
            }  
        }
        return {unq1,unq2};
    }
};
