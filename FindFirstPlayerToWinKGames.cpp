//approach
//iterate through array assuming first element to be the winner and increasing wins for every consecutive smaller elements
//if we find a greater element we update the maxskill to the current index and consecWins to 1(as this element is greater than prev and as won the battle)
//when the consecWins becomes k we return the maxSkill(the index that is strongest)
class Solution{
public:
    int findWinningPlayer(vector<int>& skills,int k){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = skills.size();
    int maxi = *max_element(skills.begin(),skills.end());
    if(skills[0]==maxi)return 0;
    int maxSkill = 0, consecWins = 0;
    for(int i=1;i<n;i++){
        if(skills[maxSkill]>skills[i]){
            consecWins++;
        }else{
            maxSkill=i;
            consecWins=1;
        }
        if(consecWins==k){
            return maxSkill;
        }
    }
    return maxSkill;
    }
};
