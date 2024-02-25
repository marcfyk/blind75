package main

import "sort"

func groupAnagrams(strs []string) [][]string {
	groups := make(map[string][]string, len(strs))
	for _, s := range strs {
		rs := []rune(s)
		sort.Slice(rs, func(i, j int) bool {
			return rs[i] < rs[j]
		})
		key := string(rs)
		if g, ok := groups[key]; !ok {
			groups[key] = []string{s}
		} else {
			groups[key] = append(g, s)
		}
	}
	result := make([][]string, 0, len(groups))
	for _, group := range groups {
		result = append(result, group)
	}
	return result
}
