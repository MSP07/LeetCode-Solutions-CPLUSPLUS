/*approach
  maths, permutation
  we use mathematical permutation to find the kth permutation
  first we take all the integer in nums array and we start with fact
  and with that we perform factorial permutation and return the kth permutation*/
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>number;
        int fact = 1;
        for(int i=1;i<=n;i++){
            number.push_back(i);
            fact *= i;
        }
        k--;
        string ans = "";
        for(int i=0;i<n;i++){
            fact /= (n-i);
            int ind = k/fact;
            ans += to_string(number[ind]);
            number.erase(number.begin()+ind);
            k %= fact;
        }
        return ans;
    }
};
