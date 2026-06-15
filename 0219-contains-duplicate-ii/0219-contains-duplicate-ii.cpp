#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>a;
        for(int i=0;i<nums.size();i++)
        {
            if(a.count(nums[i]))
            {
                return true;
            }
            a.insert(nums[i]);
            if(a.size()>k)
            {
                a.erase(nums[i-k]);
            }
        }
        return false;
    }
};
