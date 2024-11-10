/*approach
  linear traversal
  to solve this problem efficiently we can traverse the array two time one from left to right
  and another from right to left. left to right we calculate the prev or last occurence of index of c
  and update every other chars indices accordingly to i-prev now the left out elements are taken care
  when we iterate from right to left and calculate the same last occurence of c and update the remaining ones 
  that were left out in the first left to right traversal and finally return the ans array*/
class Solution{
public:
    vector<int> shortestToChar(string s,char c){
        vector<int>ans(s.size(),INT_MAX);
        int prev = -1;
        for(int i=0;i<s.size();++i){
            if(s[i]==c)prev=i;
            if(prev!=-1)ans[i]=i-prev;
        }
        prev=-1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==c)prev=i;
            if(prev!=-1)ans[i]=min(ans[i],prev-i);
        }
        return ans;
    }
};
