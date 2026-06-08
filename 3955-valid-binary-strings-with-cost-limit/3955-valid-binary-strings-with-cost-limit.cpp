class Solution {
public:
 
    vector<string>ans;
    int nn,kk;
    void rec(int pos, bool ones, int cost, string & str)
    {
        if(cost > kk)
        {
            return;
        }
        if(pos == nn)
        {
            ans.push_back(str);
            return;
        }
        str.push_back('0');
        rec(pos + 1,false, cost, str);
        str.pop_back();

        if(!ones)
        {
            str.push_back('1');
            rec(pos + 1, true, cost + pos, str);
            str.pop_back();
        }
    }
    vector<string> generateValidStrings(int n, int k) {
       nn = n;
       kk = k;
       string str = "";
       rec(0, false, 0, str);
       return ans;
    }
};