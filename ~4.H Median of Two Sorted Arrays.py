"""
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
"""

# O((m+n)log(m+n)
class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        merged_array = nums1 + nums2
        merged_array.sort()
        half_array_length = len(merged_array)//2
        if len(merged_array) % 2 != 0:
            median = merged_array[half_array_length]
        elif len(merged_array) % 2 == 0:
            median = (merged_array[half_array_length] + merged_array[half_array_length - 1])/2
        return median


# TODO: Solve in O(log(m+n))
class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        
        