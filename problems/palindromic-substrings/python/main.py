class Solution:
    def countSubstrings(self, s: str) -> int:
        count = 0
        for i in range(len(s)):
            odd = expandAndCount(i, i, s)
            even = expandAndCount(i, i + 1, s)
            count += odd + even
        return count


def expandAndCount(left: int, right: int, s: str) -> int:
    count = 0
    l, r = left, right
    while 0 <= l and r < len(s) and s[l] == s[r]:
        count += 1
        l -= 1
        r += 1
    return count
