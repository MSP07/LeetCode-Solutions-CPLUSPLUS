/*approach
  sorting
  we sort the array and accordingly add gold,silver,bronze and remaining
  to answer array and return the array*/
class Solution{
public:
    vector<string> findRelativeRanks(vector<int>& score){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = score.size();
        vector<string>res(n);
        vector<int>index(n,0);
        for(int i=0;i<n;++i){
            index[i] = i;
        }
        sort(index.begin(),index.end(),[&score](int a,int b){
            return score[a] > score[b];
        });
        for(int i=0;i<n;i++){
            if(i==0){
                res[index[i]]="Gold Medal";
            }
            else if(i==1){
                res[index[i]]="Silver Medal";
            }
            else if(i==2){
                res[index[i]]="Bronze Medal";
            }
            else{
                res[index[i]]=to_string(i+1);
            }
        }
        return res;
    }
};
