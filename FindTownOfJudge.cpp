//approach
//we have to make two vectors one indegree and outdegree to keep track of each nodes of their respective indegree and outdegree.
//then the node with one less than total indegrees and 0 outdegrees is the judge
class Solution{
public:
    int findJudge(int n, vector<vector<int>>& trust){
        vector<int>indegree(n+1,0);
        vector<int>outdegree(n+1,0);
        for(auto betray:trust){
            indegree[betray[1]]++;
            outdegree[betray[0]]++;
        }
        for(int i=1;i<=n;i++){
            if(indegree[i]==n-1 && outdegree[i]==0)return i;
        }
        return -1;
    }
};
