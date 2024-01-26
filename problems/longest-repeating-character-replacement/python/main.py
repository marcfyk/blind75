class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        max_length = 0
        counts = [0] * 26
        window_begin = 0
        for window_end, c in enumerate(s):
            counts[charIndex(c)] += 1
            window_length = getWindowLength(window_begin, window_end)
            if window_length - max(counts) > k:
                counts[charIndex(s[window_begin])] -= 1
                window_begin += 1
            else:
                max_length = max(max_length, window_length)
        return max_length


def charIndex(c: str) -> int:
    return ord(c) - ord("A")


def getWindowLength(start: int, end: int) -> int:
    return end - start + 1
