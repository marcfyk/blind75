package main

func containsDuplicate(nums []int) bool {
	s := make(map[int]struct{}, len(nums))
	for _, n := range nums {
		if _, ok := s[n]; ok {
			return true
		}
		s[n] = struct{}{}
	}
	return false
}
