class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        stack<int>number_stack;
        string news = "";
        int number = 0;
        for (int i = 0 ; i < s.size() ; i++){
            if (isdigit(s[i])){
                number = number*10 + (s[i] - '0');
                if (i+1==s.size()||!isdigit(s[i+1])){
                    number_stack.push(number);
                    number = 0;
                }
            }
            else if (s[i]!=']'){
                string temp(1,s[i]);
                st.push(temp);
            }
            else{
                string repeated_String="";
                string temp2="";
                int num = number_stack.top();
                number_stack.pop();
                string temp3 (1 , '[');
                while (!st.empty()&&st.top()!=temp3){
                    temp2 = st.top() + temp2;
                    st.pop();
                }
                st.pop();
                for (int i = 0 ; i < num ; i++){
                    repeated_String += temp2;
                }
                st.push(repeated_String);
            }
        }
        while(!st.empty()){
            news =st.top() + news;
            st.pop();
        }
        return news;
    }
};
