package main

func isValid(s string) bool {
	const (
		parenOpen    = '('
		parenClose   = ')'
		bracketOpen  = '['
		bracketClose = ']'
		braceOpen    = '{'
		braceClose   = '}'
	)

	stack := make([]rune, 0, len(s))
	for _, r := range s {
		switch r {
		case parenOpen, bracketOpen, braceOpen:
			stack = append(stack, r)
		case parenClose:
			if len(stack) == 0 {
				return false
			}
			if stack[len(stack)-1] != parenOpen {
				return false
			}
			stack = stack[:len(stack)-1]
		case bracketClose:
			if len(stack) == 0 {
				return false
			}
			if stack[len(stack)-1] != bracketOpen {
				return false
			}
			stack = stack[:len(stack)-1]
		case braceClose:
			if len(stack) == 0 {
				return false
			}
			if stack[len(stack)-1] != braceOpen {
				return false
			}
			stack = stack[:len(stack)-1]
		}
	}
	return len(stack) == 0
}
