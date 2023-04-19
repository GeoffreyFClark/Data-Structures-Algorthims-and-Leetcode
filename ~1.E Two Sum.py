# Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
# You may assume that each input would have exactly one solution, and you may not use the same element twice.
# You can return the answer in any order.

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        counter = 0
        for i in nums[counter:]:
            counter2 = counter+1
            for j in nums[counter2:]:
                if i + j == target:
                    answer = [counter,counter2]
                    return answer
                counter2+=1
            counter+=1

# TODO: Solve in less than O(n^2) complexity.
