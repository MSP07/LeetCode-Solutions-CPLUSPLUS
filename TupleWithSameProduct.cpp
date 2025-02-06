/*approach
  counting, hashmap
  goal is to find no of tuples a,b,c,d such that a*b = c*d
  the key point to notice here is no matter the tuple if the condition
  is held true then product is always same say 2,6,3,4 2*6 = 12 and 3*4 = 12
  so to solve this efficiently first we iterate through "pairs" and then store 
  the count of their product, if a product has more than or equal to a count of 2
  then tuples can be formed and the combinations will be (k*(k-1))*4 since it is a tuple
  after iterating through given array we iterate through the hashmap and perform this count check  
  and sum up the combinations of tuples and finally return it*/
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>hashi;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                int temp = nums[i]*nums[j];
                hashi[temp]++;
            }
        }
        int ans = 0;
        for(auto[prod,cnt] : hashi){
            if(cnt>=2){
                ans += (cnt*(cnt-1))*4;
            }
        }
        return ans;
    }
};

