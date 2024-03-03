package main

func countSubstrings(s string) int {
	count := 0
	rs := []rune(s)
	for i := range rs {
		odd := expandAndCount(i, i, rs)
		even := expandAndCount(i, i+1, rs)
		count += odd + even
	}
	return count
}

func expandAndCount(left, right int, rs []rune) int {
	count := 0
	l, r := left, right
	for 0 <= l && r < len(rs) && rs[l] == rs[r] {
		count += 1
		l -= 1
		r += 1
	}
	return count
}
