class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for (auto a : asteroids){
            while (!st.empty()&&a<0&&st.top()>0){
                int sum = a + st.top();
                if (sum==0){
                    st.pop();
                    a=0;
                }
                else if (sum < 0){
                    st.pop();
                }
                else{
                    a = 0;
                }
            }
            if (a!=0){
            st.push(a);
            }
        }
        vector<int>result;
        while(!st.empty()){
            if (st.top()!=0){
            result.push_back(st.top());
            st.pop();
            }
            else{
                st.pop();
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
