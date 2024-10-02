class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
             string output="";
        unordered_map<char,int> mp = {{'^',3},{'*',2},{'/',2},{'+',1},{'-',1},{'(',0}};
        stack<char> st;
        for(auto ch : s){
            if(ch!='^' && ch!='*' && ch!='+' && ch!='-' && ch!='/' && ch!='(' && ch!=')'){
                output += ch;
            }
            else if(ch=='('){
                st.push(ch);
            }
            else if(ch==')'){
                while(st.top()!='('){
                    char a = st.top();
                    st.pop();
                    output += a;
                }
                st.pop();
            }else{
                if(st.size()==0){
                    st.push(ch);
                }else if(mp[ch]>mp[st.top()]){
                    st.push(ch);
                }else{
                    while(st.size()!=0 && mp[st.top()]>=mp[ch]){
                        char b = st.top();
                        st.pop();
                        output += b;
                    }
                    st.push(ch);
                }
            }
        }
        while(st.size()!=0){
            char c = st.top();
            output += c;
            st.pop();
        }
        return output;
    }
};
