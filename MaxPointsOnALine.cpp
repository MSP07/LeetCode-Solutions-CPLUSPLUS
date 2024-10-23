/*approach
  hashmap
  as per math two points are on the same line if their slopes are equal 
  so we calculate dx and dy then take gcd of them both to know if they are multiple of
  already present one if so we increase the count of duplicate then we make this as string
  and store it in hashmap and each iteration we update max no of points in the line and return it finally*/
class Solution{
private:
    int gcd(int a,int b){
        return b == 0 ? a : gcd(b,a%b);
    }
public:
    int maxPoints(vector<vector<int>>& points){
        int n = points.size();
        if(n<=2)return n;
        int ans = 0;
        for(int i=0;i<n;++i){
            unordered_map<string,int>slopes;
            int duplicate = 1;
            for(int j=i+1;i<n;++j){
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                if(dx==0 && dy==0){
                    duplicate++;
                    continue;
                }
                int val = gcd(dy,dx);
                dx /= val;
                dy /= val;
                if(dx<0){
                    dx = -dx;
                    dy = -dy;
                }
                string slope = to_string(dy) + "/" + to_string(dx);
                slopes[slope]++;
            }
            for(auto& [slope,count] : slopes){
                ans = max(ans,count+duplicate);
            }
        }
        return ans;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
