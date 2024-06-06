//approach
//we sort the array to get consecutive elements
//we start with the current element and find the next consecutive element, we initially make the element as marked by making it -1
//if we find the next element in the array we make it -1 and increase the cnt and update the next to hands[i]+1
//if the cnt becomes groupSize then there is a group 
//if we successfully create groups for all elements in the array we return true else false
class Solution{
private:
    bool successor(vector<int>& hands,int i,int groupSize,int cnt){
        int next = hands[i]+1;
        hands[i] = -1;
        i += 1;
        cnt++;
        while(i<hands.size() && cnt<groupSize){
            if(hands[i]==next){
                next = hands[i]+1;
                hands[i]=-1;
                cnt++;
            }
            i++;
        }
        return cnt == groupSize;
    }
public:
    bool isNStraightHands(vector<int>&hands,int groupSize){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int cnt = 0;
        sort(hands.begin(),hands.end());
        for(int i=0;i<hands.size();i++){
            if(!successor(hands,i,groupSize,cnt))return false;
        }
        return true;
    }
};
