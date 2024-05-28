//approach
//we use sliding window approach
//we keep track of cost while we iterate, whenever that cost goes higher than the currentcost we shrink the window
//we update the length for each iteration
class Solution{
public:
    int equalSubstring(string s,string t,int maxCost){
        int n = s.size();
        int start = 0, maxLength = 0, currentCost = 0;
        for(int end = 0;end < n; end++){
            currentCost += abs(s[end] - t[end]);
            while(currentCost>maxCost){
                currentCost -= abs(s[start] - t[start]);
                start++;
            }
            maxLength = max(maxLength,end-start+1);
        }
        return maxLength;
    }
};
