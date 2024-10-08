/*approach
  sorting,greedy
  first we sort the given array w.r.t highest range so that we can group the end
  then we start of with 1 arrow (bcoz we need atleast 1 arrow in any case) then
  if we find a range which starts with greater number than the prev range we will 
  need a extra arrow so we add an arrow and update the end to that range's highest val
  if not then the range we are in can also be penetrated through by our arrow and so
  we do nothing. Finally we return the arrows*/
class Solution{
public:
    int findMinArrowShots(vector<vector<int>>& points){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int arrows = 1;
        sort(points.begin(),points.end(),[](const vector<int>& a,const vector<int>& b){
            return a[1] < b[1];
        });
        int end = points[0][1];
        for(int i=1;i<points.size();++i){
            if(points[i][0]>end){
                ++arrows;
                end = points[i][1];
            }
        }
        return arrows;
    }
};
