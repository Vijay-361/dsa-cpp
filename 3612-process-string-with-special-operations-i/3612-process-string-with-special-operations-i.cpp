class Solution {
public:
    string processStr(string s) {
        string str;
        int n = s.length();
        for(int i = 0; i < n ; i++)
        {
            if(s[i] == '#')
            {
                str+=str;
            }
            else if(s[i] == '*')
            {
                if(!str.empty())
                {
                    str.pop_back();
                }
            }
            else if(s[i] == '%')
            {
                reverse(str.begin(),str.end());
            }
            else
            {
                str+=s[i];
            }
        }
        return str;
    }
};