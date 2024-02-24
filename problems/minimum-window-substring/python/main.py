class Window:
    def __init__(self, left: int, right: int) -> None:
        self.left = left
        self.right = right

    def __len__(self):
        return self.right - self.left + 1

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        targets = {}
        for c in t:
            targets[c] = targets.get(c, 0) + 1

        current_window = {}
        letters_satisfied = 0

        best_window = None

        left = 0
        for right, c in enumerate(s):
            current_window[c] = current_window.get(c, 0) + 1
            if current_window[c] == targets.get(c, 0):
                letters_satisfied += 1
            while letters_satisfied == len(targets):
                window_size = right - left + 1
                if best_window == None or window_size < len(best_window):
                    best_window = Window(left, right)
                current_window[s[left]] -= 1
                if current_window[s[left]] < targets.get(s[left], 0):
                    letters_satisfied -= 1
                left += 1

        return s[best_window.left: best_window.right + 1] if best_window != None else ""
