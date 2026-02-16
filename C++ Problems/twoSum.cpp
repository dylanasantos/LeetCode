#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> stored_nums;
        for(int i = 0; i < nums.size(); i++)
        {
            int search_val = target - nums[i];
            if(stored_nums.count(search_val))
            {
                return {stored_nums[search_val], i};
            }
            else
            {
                stored_nums[nums[i]] = i; 
            }
        }
        return {};
    }
};

int main()
{
    vector<int> nums = {2,7,11,15}; //
    int target = 9;

    Solution s;
    vector<int> indexes = s.twoSum(nums, target);

    if (!indexes.empty())
    {
        cout << indexes.at(0) << " " << indexes.at(1) << endl;
    }
    else cout << "{}" << endl;

    return 0;
}
    