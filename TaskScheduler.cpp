/*approach
  greedy approach
  we find the char that has max count using hashmap
  then we identify how many chars have that max count
  then ((max_freq-1)*(n+1) + count of max occuring char) or the given arrays size
  whichever is greater we return them*/
class Solution{
public:
    int leastInterval(vector<char>& tasks, int n){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        if(n==0)return tasks.size();
        unordered_map<char,int>task_count;
        for(auto& task:tasks){
            task_count[task]++;
        }
        int max_freq = 0;
        for(auto& task:task_count){
            max_freq = max(max_freq,task.second);
        }
        int count_freq = 0;
        for(auto& entry:task_count){
            if(max_freq == entry.second){
                count_freq++;
            }
        }
        int part_count = max_freq - 1;
        int part_length = n + 1;
        int empty_slots = part_count*part_length;
        int total_slots = empty_slots + count_freq;
        return max(static_cast<int>(tasks.size()),total_slots);
    }
};
