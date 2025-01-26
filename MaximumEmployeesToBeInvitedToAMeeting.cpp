/*approach
  topological sorting
  first we find the indegree of all the nodes and
  push the nodes with 0 indegrees in the queue and if the nodes
  as a depth or conitnuous edge of 2 we keep that and with that find the 
  longest one, finally retunrning the max btn longest cycle and that of depth nodes*/
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int>inDegree(n,0);
        for(int person=0;person<n;++person){
            inDegree[favorite[person]]++;
        }
        queue<int>q;
        for(int person=0;person<n;++person){
            if(inDegree[person] == 0){
                q.push(person);
            }
        }
        vector<int>depth(n,1); 
        while(!q.empty()){
            int currentNode = q.front();
            q.pop();
            int nextNode = favorite[currentNode];
            depth[nextNode] = max(depth[nextNode], depth[currentNode] + 1);
            if(--inDegree[nextNode] == 0){
                q.push(nextNode);
            }
        }
        int longestCycle = 0;
        int twoCycleInvitations = 0;
        for(int person=0;person<n;++person){
            if(inDegree[person] == 0)continue; 
            int cycleLength = 0;
            int current = person;
            while(inDegree[current] != 0){
                inDegree[current] = 0;  
                cycleLength++;
                current = favorite[current];
            }
            if(cycleLength == 2){
                twoCycleInvitations += depth[person] + depth[favorite[person]];
            }else{
                longestCycle = max(longestCycle, cycleLength);
            }
        }
        return max(longestCycle,twoCycleInvitations);
    }
};
