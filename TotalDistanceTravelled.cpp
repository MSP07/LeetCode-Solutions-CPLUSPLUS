/*approach
  array, counting
  if mainTank < 5 then we can directly return mainTank*10
  else we do changes to mainTank till mainTank >= 5 and additionalTank > 0
  we reduce mainTank by 5 and incr it by 1 else we can directly decr by 4 and 
  decr additionalTank by 1 and add appropriate distance for that and finally after the
  loop we calculate and add mileage for remaining mainTank to distance and finally return it*/
class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        if(mainTank<5)return mainTank*10;
        int distance = 0;
        while(mainTank>=5 && additionalTank>0){
            mainTank -= 4;
            additionalTank--;
            distance += 50;
        }
        distance += (mainTank*10);
        return distance;
    }
};
