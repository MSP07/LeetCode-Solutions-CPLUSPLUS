/*approach
  bfs, sorting, priority queue
  we traverse through levels using queue(bfs) then we store in hashmap then to vector and sort it
  descending order and we can return the kth largest element if we go through sorting
  to recue the sorting, extra vector and hashmap we can use minHeap where we directly add the lvlSum to
  the minHeap if the k level is not reached and if the curr lvlSum is greater than the top we push that
  lvlSum to minHeap and finally if the minHeap is of k size then we return the top val that will be kth
  greatest element else we return -1*/
class Solution{
public:
    int long long kthLargestLevelSum(TreeNode* root,int k){
        priority_queue<long long,vector<long long>,greater<long long>>minHeap;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            long long lvlSum = 0;
            for(int i=0;i<size;++i){
                TreeNode* curr = q.front();
                q.pop();
                lvlSum += curr->val;
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            if(minHeap.size()<k){
                minHeap.push(lvlSum);
            }else if(lvlSum > minHeap.top()){
                minHeap.pop();
                minHeap.push(lvlSum);
            }
        }
        return minHeap.size() == k ? minHeap.top() : -1;
    }
};
