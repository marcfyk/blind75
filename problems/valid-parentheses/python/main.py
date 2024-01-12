class Solution:
    def isValid(self, s: str) -> bool:
        PAREN_OPEN = "("
        PAREN_CLOSE = ")"
        BRACKET_OPEN = "["
        BRACKET_CLOSE = "]"
        BRACE_OPEN = "{"
        BRACE_CLOSE = "}"

        stack = []
        for c in s:
            if c == PAREN_OPEN:
                stack.append(c)
            if c == BRACKET_OPEN:
                stack.append(c)
            if c == BRACE_OPEN:
                stack.append(c)
            if c == PAREN_CLOSE:
                if len(stack) == 0:
                    return False
                if stack.pop() != PAREN_OPEN:
                    return False
            if c == BRACKET_CLOSE:
                if len(stack) == 0:
                    return False
                if stack.pop() != BRACKET_OPEN:
                    return False
            if c == BRACE_CLOSE:
                if len(stack) == 0:
                    return False
                if stack.pop() != BRACE_OPEN:
                    return False

        return len(stack) == 0
