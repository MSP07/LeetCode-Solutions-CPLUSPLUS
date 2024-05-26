//approach
//keep a visited array
//call a recursive function whenever 1 is encountered
//increase count each time we call the function when it is not visited
class Solution{
private:
    void NoOfEnclaves(vector<vector<int>>&adjList,int&cnt,vector<int>&visited,int i){
        visited[i]=1;
        for(auto it:adjList[i]){
            if(!visited[it]){
                NoOfEnclaves(adjList,cnt,visited,it);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected){
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int>visited(n,0);
        vector<vector<int>>adjList(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                NoOfEnclaves(adjList,cnt,visited,i);
            }
        }
        return cnt;
    }
};
