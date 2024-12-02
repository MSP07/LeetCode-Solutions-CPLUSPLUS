/*approach
  simulation
  we calculate digits for every number in a iterative modulo, divisor manner
  and add it to the ans vector and then finally return the ans vector*/
class Solution{
private:
    void calc(vector<int>& ans,int num){
        if(num<=0)return;
        calc(ans,num/10);
        ans.push_back(num%10);
    }
public:
    vector<int> seperateDigits(vector<int>& nums){
        vector<int>ans;
        for(int num:nums){
            calc(ans,num);
        }
        return ans;
    }
};
