package main

func productExceptSelf(nums []int) []int {
	products := make([]int, len(nums))

	prefixAcc := 1
	for i, n := range nums {
		products[i] = prefixAcc
		prefixAcc *= n
	}

	postfixAcc := 1
	for i := len(nums) - 1; i >= 0; i-- {
		products[i] *= postfixAcc
		postfixAcc *= nums[i]
	}

	return products
}
