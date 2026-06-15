class Solution {
public:
    multiset<long long>st;
    void insert(long long x)
    {
       st.insert(x);
    }
    void remove(long long x)
    {
        st.erase(st.find(x));
    }
    bool good(long long r, long long l, long long k)
    {
        return (*st.rbegin()-*st.begin())*(r - l + 1) <= k;
    }
    long long countSubarrays(vector<int>& nums, long long k) {
           long long n = nums.size();
           long long r = -1;
           long long cnt = 0;
     for(int i = 0; i < n; i++)
     {
         while(r + 1 < n)
         {
             insert(nums[r + 1]);
             r++;
             if(!good(r, i, k))
             {
                remove(nums[r]);
                r--;
                break;
             }
         }      
         cnt += (r - i) + 1;
         remove(nums[i]);
         
     }
      return cnt;
    }
};