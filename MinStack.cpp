//approach
//initialise vector with pairs, first one will the org val and second will store the min val encountered so far
class MinStack{
private:
    vector<pair<int,int>>st;
public:
    MinStack(){

    }
    void push(int val){
        if(st.empty()){
            pair<int,int>p;
            p.first = val;
            p.second = val;
            st.push_back(p);
        }else{
            pair<int,int>p;
            p.first = val;
            p.second = min(val,st.back().second);
            st.push_back(p);
        }
    }
    void pop(){
        st.pop_back();
    }
    int top(){
        return st.back().first;
    }
    int getMin(){
        return st.back().second;
    }
};
