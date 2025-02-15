/*approach
  backtracking
  aim to find the combination of numbers that when squared and summed 
  digit wise gives the index and the ans is the total of all such numbers
  to achieve this we can use backtracking we start by implementing target that is i
  and the number is i*i now we try out every possibilities. Since the limit is 1000
  we check whether sqr/10,sqr/100.sqr/1000 is possible and respectively org-(sqr%10),
  org-(sqr%100),org-(sqr%1000) if there in any possibility if there exist a case
  sqr == org we return true and hence we sum that i*i into ans else at any case org < 0
  or sqr < org we return false and finally return the ans*/
class Solution {
private:
    // bool isPossible(string s,int target,int ind,int sum){
    //     if(ind == s.size())return sum == target;
    //     int num = 0;
    //     for(int j=ind;j<s.size();j++){
    //         num = num*10 + (s[j]-'0');
    //         if(isPossible(s,target,j+1,sum+num))return true;
    //     }
    //     return false;
    // }
    bool isPossible(int sqr,int org){
        if(org<0 or sqr<org)return false;
        if(sqr == org)return true;
        return isPossible(sqr/10,org-sqr%10) || isPossible(sqr/100,org-sqr%100) || isPossible(sqr/1000,org-sqr%1000);
    }
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++){
            int temp = i*i;
            if(isPossible(temp,i)){
                ans += (i*i);
            }
        }
        return ans;
    }
};

// const auto init = [](){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();
