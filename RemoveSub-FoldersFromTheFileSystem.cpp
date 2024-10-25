/*approach
  sorting, greedy
  to identify the subfolders we need to check whether the first char(alphabet) is
  already present before to do this efficiently we can sort the given folder and  
  first element by default will be in answer as lexographically it is the first
  then we taje this first element as our prev then start iterating from the next 
  element and if we can find the prev+'/' in our curr element then that is not a 
  sub-folder of the given prev element since it is sorted it will be not sub folder of
  any upcoming element too so we add that to our answer and update the curr element as our prev*/
class Solution{
public:
    vector<string> removeSubFolders(vector<string>& folder){
        sort(folder.begin(),folder.end());
        vector<string>ans = {folder[0]};
        string prev = folder[0];
        for(int i=1;i<folder.size();++i){
            string curr = folder[i];
            if(curr.find(prev+'/')!=0){
                ans.push_back(curr);
                prev = curr;
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
