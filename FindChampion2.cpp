/*approach
  bit manipulation, graph
  the idea is that if 0 greater than 1 and 1 greater than 2 then 0 is automatically greater than 2
  now if we find a champion we try to check for the increased length, to do that we keep track of
  all the indices that we have seen and we use a bitset for that, then during storing at any place if
  the indices fail to follow the order then there are no champions so we return -1*/
class Solution{
public:
    int findChampion(int n,vector<vector<int>> &edges){
        bitset<100>loss;
        for(auto& edge:edges){
            loss.set(edge[1]);
        }
        int champion = -1;
        for(int i=0;i<n;i++){
            if(!loss[i]){
                if(champion!=-1)return -1;
                champion = i;
            }
        }
        return champion;
    }
};
