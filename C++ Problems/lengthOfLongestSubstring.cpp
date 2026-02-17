#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> stored_vals;
        stored_vals.reserve(s.size());

        int start_index = 0;
        int size = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(stored_vals.count(s[i]) && stored_vals[s[i]] >= start_index)
            {
                start_index = stored_vals[s[i]] + 1;
            }
            stored_vals[s[i]] = i;
            size = max(size, i - start_index + 1);
        }
        return size;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb");

    return 0;
}