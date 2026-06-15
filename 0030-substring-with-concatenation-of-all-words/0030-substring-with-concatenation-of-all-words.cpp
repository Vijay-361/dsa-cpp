class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty())
            return {};

        vector<int> ans;

        unordered_map<string,int> mp;

        for(auto &word : words)
            mp[word]++;

        int m = words[0].length();
        int k = words.size();
        int window = k * m;

        if(s.length() < window)
            return ans;

        for(int i = 0; i < s.length() - k * m + 1; i++) {

            unordered_map<string,int> seen;
            int j;
             for( j = 0; j < k; j++)
             {
                const string& str = s.substr(i + j * m, m);

        

                if(++seen[str] > mp[str])
                    break;

             
            }

            if(j == k)
                ans.push_back(i);
        }

        return ans;
    }
};