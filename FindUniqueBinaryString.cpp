/*approach
  backtracking,bit manipulation,string
  in backtracking we try all possible combos and return immediately the one that is
  not present in nums, in bit manipulation we do the same we try all possibilities with 
  the help of bits finally the optimized string approach is based on the fact that 
  nums.length == nums[i].length so to get a new one that is not present in nums we simply 
  change the nums[i][i] bit to its opposite that is nums[i][i] == '0' ? '1' : '0' and return the final string*/
class Solution{
private:
    string backtrack(string temp,unordered_set<string>& hashi,int n){
        if(temp.size()==n){
            if(!hashi.count(temp)){
                return temp;
            }
            return "";
        }
        for(char ch:{'0','1'}){
            temp.push_back(ch);
            string res = backtrack(temp,hashi,n);
            if(!res.empty())return res;
            temp.pop_back();
        }
        return "";
    }
public:
    string findDifferentBinaryString(vector<string>& nums){
        //backtracking
        int n = nums.size();
        unordered_set<string>hashi(nums.begin(),nums.end());
        return backtrack("",hashi,n);
        //bit manipulation
        for(int i=0;i<(1<<n);i++){
            string temp = bitset<16>(i).to_string().substr(16-n);
            if(!hashi.count(temp))return temp;
        }
        return "";
        //optimized string logic
        string ans = "";
        for(int i=0;i<nums.size();i++){
            ans += (nums[i][i]=='0') ? '1' : '0';
        }
        return ans;
    }
};
