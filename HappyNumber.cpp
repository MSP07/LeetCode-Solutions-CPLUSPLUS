/*approach
  slow fast pointers
  we follow the given instructions and add the square of each num in digits
  and we use slow fast pointer to navigate with ease and stop when both of them
  merge at a point or when fast becomes 1 and check whether fast as become 1
  if yes its a happy number else not*/
class Solution{
private:
    int getNext(int n){
        int totalSum = 0;
        while(n>0){
            int num = n%10;
            totalSum += num*num;
            n /= 10;
        }
        return totalSum;
    }
public:
    bool isHappy(int n){
        int slow = n;
        int fast = getNext(n);
        while(fast!=1 && slow!=fast){
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
};
