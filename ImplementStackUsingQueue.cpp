//approach
//initialise two queues and push one element from one queue to another if the queue is not empty
class MyStack{
private:
    queue<int>q1,q2;
public:
    void push(int x){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    int pop(){
        if(q1.empty())return -1;
        int top_element = q1.front();
        q1.pop();
        return top_element;
    }
    int top(){
        if(q1.empty())return -1;
        return q1.front();
    }
    bool empty(){
        return q1.empty();
    }
};
