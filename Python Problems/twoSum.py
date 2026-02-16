class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        stored_nums = {}
        for i in range(len(nums)):
            search_val = target - nums[i]

            if(search_val in stored_nums):
                return [stored_nums[search_val], i]
            else:
                stored_nums[nums[i]] = i
        
        return []

def main():
    nums = [2, 7, 11, 15]
    target = 9

    my_obj = Solution()
    print(my_obj.twoSum(nums, target))


if (__name__ == "__main__"):
    main()