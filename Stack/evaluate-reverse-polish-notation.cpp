class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(const string& c : tokens)
        {
            
            if (c == "+" || c == "-" || c == "*" || c == "/") {

                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                
                if (c == "+") {
                    st.push(left + right);
                } else if (c == "-") {
                    st.push(left - right);
                } else if (c == "*") {
                    st.push(left * right);
                } else {
                    st.push(left / right);
                }
            } 
            else {
                st.push(std::stoi(c));
            }
        }
        
        return st.top();
    }
};
