/*approach
  simulation
  since its a marathon if the runner is in first half of round we push the round
  from start to end else we push from 1 to end and from start to all the way to n
  and finally return the vector*/
class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int>ans;
        int start = rounds[0], end = rounds[rounds.size()-1];
        if(start<=end){
            for(int i=start;i<=end;i++){
                ans.push_back(i);
            }
        }else{
            for(int i=1;i<=end;i++){
                ans.push_back(i);
            }
            for(int i=start;i<=n;i++){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
