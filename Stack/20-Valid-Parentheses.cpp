class Solution {
public:
    bool isValid(string s) {
       stack<int> s1;
       
       for(int i=0;i<s.length();i++)
       {
           if(s[i]=='('||s[i]=='['||s[i]=='{')
           s1.push(s[i]);
           else if(s[i]==')')
           {
               if(!s1.empty() && s1.top()=='(')
               {
                   s1.pop();
               }
               else
               return false;
               
           }
            else if(s[i]==']')
           {
               if(!s1.empty() && s1.top()=='[')
               {
                   s1.pop();
               }
              else
              return false;
           }
            else if(s[i]=='}')
           {
               if(!s1.empty() && s1.top()=='{')
               {
                   s1.pop();
               }
               else
               return false;
           }
           else
           return false;


       }
       if(s1.empty())
       return true;
       return false; 
    }
};