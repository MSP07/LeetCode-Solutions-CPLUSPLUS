/*apporoach
  sorting, hashmap, two pointers
  we sort the given array so we can have smallest and largest
  element at any given time and we keep two pointers one at start  
  and another at end we calculate their average and add it to hash set
  and keep moving pointers when they are no more elements we return the 
  distinct elements present in the hash set*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public: 
    int distinctAverages(vector<int>& nums){
        if(nums.size()==2)return 1;
        sort(nums.begin(),nums.end());
        int l = 0, r = nums.size()-1;
        unordered_set<double>hashi;
        while(l<r){
            hashi.insert(((double)nums[l]+nums[r])/2);
            l++;
            r--;
        }
        return hashi.size();
    }
};
