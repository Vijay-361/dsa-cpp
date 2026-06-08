class Solution {
public:
    bool consecutiveSetBits(int n) {
         int cnt = 0;
         int l = -1;
         while(n != 0)
         {
             int c = n % 2;
             if(l == 1 && c == 1)
             {
                cnt++;
             } 
             l = c;
             n /= 2;
         }
         return cnt == 1;
    }
};