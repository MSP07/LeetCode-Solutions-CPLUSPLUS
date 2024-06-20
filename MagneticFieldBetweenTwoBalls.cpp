/*approach
  we sort the given data
  we then check whether we can put the ball in the current index if yes we shrink the window to the later half 
  else we shrink it to first half, while iterating like this we update a var with possible positions and return it as it will
  hold the max of min value*/
class Solution{
private:
    bool isPossible(vector<int>& position,int m,int mid){
        int cnt = 1;
        int lastSeen = position[0];
        for(int i=1;i<position.size();++i){
            if(position[i]-lastSeen >= mid){
                cnt++;
                lastSeen = position[i];
                if(cnt==m)return true;
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position,int m){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        sort(position.begin(),position.end());
        if(m==2)return position[position.size()-1]-position[0];
        int low = 1;
        int high = position.back()-position.front();
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(position,m,mid)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};
