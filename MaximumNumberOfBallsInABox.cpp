/*approach
  array,hashmap
  we find sum of digits of given num and increase the count of 
  that num in our hashmap and finally return the max element in the hashmap*/
class Solution {
    private:
        int find(int num){
            int temp = 0;
            while(num>0){
                temp += num%10;
                num /= 10;
            }
            return temp;
        }
    public:
        int countBalls(int lowLimit, int highLimit) {
            vector<int>hashi(46,0);
            for(int i=lowLimit;i<=highLimit;i++){
                hashi[find(i)]++;
            }
            return *max_element(hashi.begin(),hashi.end());
        }
    };
