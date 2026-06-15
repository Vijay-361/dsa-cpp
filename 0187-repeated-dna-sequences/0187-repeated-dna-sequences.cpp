class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string>ans;
        unordered_map<string,int>mp;
        if(s.length() < 10)return {};
        for(int i = 0; i <= s.length() - 10; i++)
        {
            string str = s.substr(i, 10);
            if(mp.find(str) != mp.end())
            {
              ans.insert(str);
            }
            mp[str]++;
        }
        vector<string>a;
        for(auto it:ans)
        {
            a.push_back(it);
        }
        return a;
    }
};