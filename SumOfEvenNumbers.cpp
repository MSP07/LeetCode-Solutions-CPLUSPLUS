/*approach
  simulation
  we start by calculating the even val sum first
  then we start iterating in queries and on the given ind if the val is even we remove that val fro, evenSum
  and we add the val to that element this is becoz we already have that even in evenSum lets say after adding the val 
  to that element the elemnt is still even then there will be complications in changing evenSum that's why. Now after 
  adding the val to that element if the val is still even we add that to evenSum and push that into the ans vector
  and finally return that vector*/
class Solution{
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums,vector<vector<int>>& queries){
        int evenSum = 0;
        vector<int>ans;
        for(int num:nums){
            if(num%2==0){
                evenSum += num;
            }
        }
        for(int i=0;i<queries.size();i++){
            int val = queries[i][0];
            int ind = queries[i][1];
            if(nums[ind]%2==0){
                evenSum -= nums[ind];
            }
            nums[ind] += val;
            if(nums[ind]%2==0){
                evenSum += nums[ind];
            }
            ans.push_back(evenSum);
        }
        return ans;
    }
};
