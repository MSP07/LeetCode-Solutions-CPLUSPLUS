//approach
//simple bfs approach to keep track of visited nodes
//if all the nodes are visited from the start then there is a way else not
class Solution{
public:
    bool canVisitAllRooms(vector<vector<int>>&rooms){
        vector<int>visited(rooms.size(),0);
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int key = q.front();
            q.pop();
            visited[key]=1;
            for(int i=0;i<rooms[key].size();i++){
                if(!visited[rooms[key][i]])q.push(rooms[key][i]);
            }
        }
        for(int i=0;i<visited.size();i++){
            if(!visited[i])return false;
        }
        return true;
    }
};
