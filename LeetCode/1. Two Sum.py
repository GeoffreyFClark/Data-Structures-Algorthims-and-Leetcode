"""
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
"""

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # counter = 0
        # for i in nums[counter:]:
        #     counter2 = counter+1
        #     for j in nums[counter2:]:
        #         if i + j == target:
        #             answer = [counter,counter2]
        #             return answer
        #         counter2+=1
        #     counter+=1

        mydict = {}
        for index, integer in enumerate(nums):
            if integer <= target:
                mydict[integer] = index
            if (target - integer) in mydict and mydict[target - integer] != index:
                answer = [mydict.get(target - integer), index]
                return answer
