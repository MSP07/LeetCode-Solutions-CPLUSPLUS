//approach
//we keep track of elements indices in hashmap
//when we encounter that element again we update ans with their difference
//after iteration if no elements found and ans is same as beginning we return -1 else ans
class Solution{
public:
    int minimumCardPickup(vector<int>& cards){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        unordered_map<int,int>lastSeen;
        int ans = INT_MAX;
        for(int i=0;i<cards.size();i++){
            if(lastSeen.count(cards[i])){
                ans = min(ans,i-lastSeen[cards[i]]+1);
            }
            lastSeen[cards[i]]=i;
        }
        return (ans==INT_MAX) ? -1 : ans;
    }
};
