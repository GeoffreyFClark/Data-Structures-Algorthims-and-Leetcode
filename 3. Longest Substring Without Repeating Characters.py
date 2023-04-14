class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest = 0
        counter = 0
        prior_letters = []
        for letter in s:
            if letter not in prior_letters:
                counter +=1
                prior_letters.append(letter)
            elif letter in prior_letters:
                if counter > longest:
                    longest = counter
                counter = 1
        return longest