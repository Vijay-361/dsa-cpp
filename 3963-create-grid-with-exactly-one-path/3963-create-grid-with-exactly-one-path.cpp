class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>str;
        for(int i = 0; i < m ;i++)
        {
            string s="";
            for(int j = 0; j < n; j++)
            {
                if(i == 0)
                {
                    s += '.';
                }
                else if(j == n -1)
                {
                    s += '.';
                }
                else
                {
                    s+='#';
                }
            }
            str.push_back(s);
        }
        return str;
    }
};