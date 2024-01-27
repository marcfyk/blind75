class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_length = 0
        seen = set()
        left = 0
        for right, c in enumerate(s):
            if c in seen:
                while s[left] != c:
                    seen.remove(s[left])
                    left += 1
                left += 1
            else:
                seen.add(c)
            max_length = max(max_length, right - left + 1)
        return max_length
