/*approach
  priority_queue,simulation
  if its to sell then we compare with buy and vice versa so
  we use two pq one maxheap(sell) and one minheap(buy) depending on the
  type we check for elements in the pq and take that and take the min out of 
  amount and the sell/buy amount and subtract that from amount and sell/buy amount
  and push that back into that particular pq and after that we check if there is an amount and
  push the price,amount pair in the other pq and finally we take the amount from all the elements in
  both the pq's and modulo them with 1e9+7 and finally return the answer*/
class Solution{
    int MOD = 1e9+7;
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        priority_queue<pair<int,int>>buyPQ;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>sellPQ;
        for(auto& order:orders){
            int price = order[0], amount = order[1], type = order[2];
            if(type==0){//buy type so we use sellPQ
                while(amount>0 && !sellPQ.empty() && sellPQ.top().first<=price){
                    auto [sellPrice,sellAmount] = sellPQ.top();
                    sellPQ.pop();
                    int money = min(amount,sellAmount);
                    amount -= money;
                    sellAmount -= money;
                    if(sellAmount>0){
                        sellPQ.push({sellPrice,sellAmount});
                    }
                }
                if(amount>0){
                    buyPQ.push({price,amount});
                }
            }else{
                while(amount>0 && !buyPQ.empty() && buyPQ.top().first >= price){
                    auto [buyPrice,buyAmount] = buyPQ.top();
                    buyPQ.pop();
                    int money = min(amount,buyAmount);
                    amount -= money;
                    buyAmount -= money;
                    if(buyAmount>0){
                        buyPQ.push({buyPrice,buyAmount});
                    }
                }
                if(amount>0){
                    sellPQ.push({price,amount});
                }
            }
        }
        long long ans = 0;
        while(!sellPQ.empty()){
            ans = (ans+sellPQ.top().second)%MOD;
            sellPQ.pop();
        }
        while(!buyPQ.empty()){
            ans = (ans+buyPQ.top().second)%MOD;
            buyPQ.pop();
        }
        return ans;
    }
};
