/*approach
  we keep first index as 0 and iteratively update for each element
  winner = (winner+k)%i
  and finally we make it based on 0 indexing by adding 1*/
class Solution{
public:
    int findTheWinner(int n,int k){
        int winner = 0;
        for(int i=1;i<=n;++i){
            winner = (winner+k)%i;
        }
        return winner+1;
    }
};
