class Solution:
    def productExceptSelfOn2(self, nums):
        res = []
        m = {}
        for i in range(len(nums)):
            res.append(1)
            for j in range(len(nums)):
                if i == j:
                    continue
                res[i] *= nums[j]
        return res

    def productExceptSelf(self, nums):
        res = [1] * (len(nums))
        pref = 1
        for i in range(len(nums)):
            res[i] = pref
            pref *= nums[i]
        postf = 1
        for i in range(len(nums) - 1, -1, -1):
            res[i] *= postf
            postf *= nums[i]
        return res


nums = [1, 2, 3, 4]
# nums = [-1, 1, 0, -3, 3]
print(Solution.productExceptSelf(Solution, nums))
