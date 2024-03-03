package main

type Window struct {
	left  int
	right int
}

func (w Window) Len() int {
	return w.right - w.left + 1
}

func minWindow(s string, t string) string {
	targets := make(map[rune]uint)
	for _, r := range t {
		targets[r]++
	}

	currentWindow := make(map[rune]uint)
	lettersSatisfied := 0

	var bestWindow *Window

	left := 0
	rs := []rune(s)
	for right, r := range rs {
		currentWindow[r] = currentWindow[r] + 1
		if currentWindow[r] == targets[r] {
			lettersSatisfied++
		}
		for lettersSatisfied == len(targets) {
			windowSize := right - left + 1
			if bestWindow == nil || windowSize < bestWindow.Len() {
				bestWindow = &Window{left: left, right: right}
			}
			currentWindow[rs[left]]--
			if currentWindow[rs[left]] < targets[rs[left]] {
				lettersSatisfied--
			}
			left++
		}
	}
	if bestWindow == nil {
		return ""
	}
	return string(rs[bestWindow.left : bestWindow.right+1])
}
