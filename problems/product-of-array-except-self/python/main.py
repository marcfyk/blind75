from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        products = [0] * len(nums)

        prefix_acc = 1
        for i, n in enumerate(nums):
            products[i] = prefix_acc
            prefix_acc *= n

        postfix_acc = 1
        for i, n in reversed(list(enumerate(nums))):
            products[i] *= postfix_acc
            postfix_acc *= n

        return products
