class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        i = 0
        while True:
            if nums[i] == i:
                i += 1
                continue
            
            if nums[nums[i]] == nums[i]:
                return nums[i]

            self.swap(nums, i, nums[i])

            
    def swap(self, nums, lindex, rindex):
        a = nums[lindex]
        nums[lindex] = nums[rindex]
        nums[rindex] = a 

