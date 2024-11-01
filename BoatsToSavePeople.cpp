/*approach
  greedy,sorting,two pointers
  first we sort the array to know the lightest and heaviest people and if their weights are below
  the limit then we can still increase people so we try that by incr left pointer and after that 
  we remove the heaviest as he/she definitely needs a boat also we increase the required boats and return them finally*/
class Solution{
public:
    int numRescueBoats(vector<int>& people,int limit){
        int boats = 0;
        sort(people.begin(),people.end());
        int left = 0, right = people.size()-1;
        while(left<=right){
            if(people[left]+people[right]<=limit){
                left++;
            }
            right--;
            ++boats;
        }
        return boats;
    }
};
