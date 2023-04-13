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
