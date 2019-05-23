class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dict;
        for (int i = 0; i < (int)nums.size(); i++)
            dict[nums[i]] = i;
        for (int i = 0; i < (int)nums.size(); i++) {
            auto mElem = dict.find(target - nums[i]);
            if (mElem != dict.end() && i != mElem->second) {
                vector<int> ans = {i, mElem->second}; return ans;
            }
        }
        return {};
    }
};
