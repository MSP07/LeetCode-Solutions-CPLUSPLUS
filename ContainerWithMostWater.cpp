/*approach
  two pointers, greedy
  to calculate the area of water in the container we need height and width
  the height is the min of both vals given in the array and the width will
  the difference in their positions. We can implement this using two for loops
  which will be inefficient for large inputs so we use two pointers one at start
  and another at end if the starting is less than ending (height[left]<height[right])
  then there is possibly another max height later in the array so we increase the left
  pointer else we decrease the right pointer this gives a 0(n) linear time solution*/
class Solution{
public:
    int maxArea(vector<int>& height){
        int left = 0,right=height.size()-1,maxi=0;
        while(left<right){
            int mini = min(height[left],height[right]);
            maxi = max(maxi,mini*(right-left));
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxi;
    }
};
