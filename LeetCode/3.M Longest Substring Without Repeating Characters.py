"""
Given a string s, find the length of the longest 
substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
"""

# Sliding window technique
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0

        longest_length = 0
        first_unrepeated = 0
        prior_chars = {}

        for current_index, char in enumerate(s):
            if char in prior_chars and prior_chars[char] >= first_unrepeated:
                first_unrepeated = prior_chars[char] + 1
            prior_chars[char] = current_index
            longest_length = max(longest_length, current_index - first_unrepeated + 1)
        return longest_length