/*approach
  bfs approach
  we keep a queue and we start by calculating nextPosition first it will be current pos + a
  if it is inside the bound and not in the given forbidden vector we add it to the queue next
  the nextPosition will be current pos - b and if this is also inside the bound we push it to the queue
  and we update the jumps and whether or not it is used back and if the pos reaches x we return jumps
  else we return -1*/
class Solution{
public:
    int minimumJumps(vector<int>& forbidden,int a,int b,int x){
        unordered_set<int>forbiddenSet(forbidden.begin(),forbidden.end());
        queue<tuple<int,int,bool>>q;
        forbiddenSet.insert(0);
        q.push({0,0,false});
        while(!q.empty()){
            auto [pos,jumps,usedBack] = q.front();
            q.pop();
            if(pos==x)return jumps;
            int nextPos = pos + a;
            if(nextPos<=6000 && forbiddenSet.find(nextPos)==forbiddenSet.end()){
                q.push({nextPos,jumps+1,false});
                forbiddenSet.insert(nextPos);
            }
            nextPos = pos - b;
            if(!usedBack && nextPos >= 0 && forbiddenSet.find(nextPos)==forbiddenSet.end()){
                q.push({nextPos,jumps+1,true});
            }
        }
        return -1;
    }
};
