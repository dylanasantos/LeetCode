class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        stored_vals = {}

        size = 0
        start = 0

        for i in range(len(s)):
            if( (s[i] in stored_vals) and (stored_vals[s[i]] >= start) ):
                start = stored_vals[s[i]] + 1

            stored_vals[s[i]] = i
            size = max(size, i - start + 1)
        return size

def main():
    s = "abcadefgh"

    my_obj = Solution()
    print(my_obj.lengthOfLongestSubstring(s))


if (__name__ == "__main__"):
    main()  