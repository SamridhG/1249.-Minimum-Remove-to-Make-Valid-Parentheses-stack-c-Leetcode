class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>A;
        string result="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                A.push(make_pair(s[i],i));
            }
            else
            {   if(!A.empty() && A.top().first=='(' && s[i]==')')
                {
                    A.pop();
                }
             else if(s[i]==')')
                {
                    A.push(make_pair(s[i],i));
                }
            }
        }
         while(!A.empty())
            {
                s[A.top().second]='1';
                A.pop();
            }
         s.erase(remove(s.begin(), s.end(), '1'), s.end());  // interseting thing
        return s;
    }
};
