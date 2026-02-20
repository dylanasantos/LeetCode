#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> numerals =
        {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        if(s.size() < 1) return 0;
        if(s.size() == 1) return numerals[s[0]];

        int sum = 0;

        for(int i = 0; i < s.size() - 1; i++)
        {
            int curr_val = numerals[s[i]];
            int next_val = numerals[s[i + 1]];

            if(next_val > curr_val)
            {
                sum -= curr_val;
            }
            else
            {
                sum += curr_val;
            }
        }
        return sum + numerals[s[s.size() - 1]];
    }
};

int main()
{
    string numeral = "MCMXCIV";

    Solution s;
    cout << "Result: " << s.romanToInt(numeral);

    return 0;
}