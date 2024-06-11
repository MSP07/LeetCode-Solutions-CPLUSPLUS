/*approach
  we create a comparator which has two vectors that ensures that the elements in the rows of matrix with k distance
  gets sorted in descending order. so when we call the comparator with the sort function this condition ensures the
  descending order sorting*/
class Solution{
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        auto comaprator = [k](const vector<int>& a,const vector<int>& b){
            return a[k]>b[k];
        };
        sort(score.begin(),score.end(),comaprator);
        return score;
    }
};
