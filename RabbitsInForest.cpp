/*approach
  greedy
  if a rabbit says x count then there will be x+1 rabbits so that will be the groupSize
  now the no of groups will be total rabbits with groupSize and freq -1 / groupSize
  and totalRabbits will be the prod of groups and groupSize*/
class Solution{
public:
    int numRabbits(vector<int>& answers){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        unordered_map<int,int>count;
        for(int answer:answers){
            count[answer]++;
        }
        int totalRabbits = 0;
        for(auto [x,freq]:count){
            int groupSize = x+1;
            int groups = (freq+groupSize-1)/groupSize;
            totalRabbits += groups*groupSize;
        }
        return totalRabbits;
    }
};
