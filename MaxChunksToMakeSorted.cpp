/*approach
  linear search
  in order to find the chunks that will make up min sorting
  we just find the highest element comapred to prev element
  and if the highest element is in the same index then from
  [0, index] becomes a chunk so we incr the chunks to be sorted
  and finally return the count*/
class Solution{
public:
    int maxChunksToSorted(vector<int>& arr){
        int n = arr.size();
        int chunks = 0, maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,arr[i]);
            if(maxi==i)++chunks;
        }
        return chunks;
    }
};
