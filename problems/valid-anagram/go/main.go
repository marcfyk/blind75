package main

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	counts := make(map[rune]int)
	sr := []rune(s)
	tr := []rune(t)
	for i := range len(sr) {
		counts[sr[i]]++
		counts[tr[i]]--
	}
	for _, c := range counts {
		if c != 0 {
			return false
		}
	}
	return true
}
