#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution{
    public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> ret;
        unordered_map<int, int> map;
        int len = nums.size();
        for(int i=0; i<len; i++){
            if(map.find(target-nums[i]) != map.end()){
                ret.push_back(map[target-nums[i]]);
                ret.push_back(i);
                break;
            }else{
                map[nums[i]] = i;
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> nums = {2,7,11,15};
    Solution s;
    vector<int> ret = s.twoSum(nums, 9);
    for (vector<int>::size_type i=0; i<ret.size(); i++){
        cout << ret[i] << ' ';
    }
}