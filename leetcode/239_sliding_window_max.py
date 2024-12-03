# You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
# Return the max sliding window.
#  
# Example 1:
# Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
# Output: [3,3,5,5,6,7]
# Explanation: 
# Window position                Max
# ---------------               -----
# [1  3  -1] -3  5  3  6  7       3
#  1 [3  -1  -3] 5  3  6  7       3
#  1  3 [-1  -3  5] 3  6  7       5
#  1  3  -1 [-3  5  3] 6  7       5
#  1  3  -1  -3 [5  3  6] 7       6
#  1  3  -1  -3  5 [3  6  7]      7
# Example 2:
# Input: nums = [1], k = 1
# Output: [1]
#  
# Constraints:
# * 1 <= nums.length <= 105
# * -104 <= nums[i] <= 104
# * 1 <= k <= nums.length

from collections import deque

def slidingWindow(nums, k):
    n = len(nums)
    ans = []
    
    # window initialization
    window = deque([nums[0]])
    idxs = deque([0])
    for i in range(1, k):
        while len(window) > 0 and nums[i] > window[-1]:
            window.pop()
            idxs.pop()
        window.append(nums[i])
        idxs.append(i)
    ans.append(window[0])

    # iterate over remaining start indices i
    # idxs is strictly increasing indices, nums is weakly decreasing values
    for i in range(1, n-k+1):
        if i > idxs[0]: # the maximum is phased out
            window.popleft()
            idxs.popleft()
        # nums[i+k-1] is the new addition. remove all nums from right less than it, and add it on. 
        while len(window) > 0 and nums[i+k-1] > window[-1]:
            window.pop()
            idxs.pop() 
        window.append(nums[i+k-1])
        idxs.append(i+k-1)
        
        ans.append(window[0])

    return ans
    


def test():
    assert slidingWindow([1,3,-1,-3,5,3,6,7], 3) == [3,3,5,5,6,7]
    assert slidingWindow([5,6,100,1,2,3,4,5,6,7], 5) == [100,100,100,5,6,7]
    assert slidingWindow([5,6,100,99,2,3,4,5,6,7], 5) == [100,100,100,99,6,7]
    assert slidingWindow([5,6,100,99,2,3,4,5,98,7], 5) == [100,100,100,99,98,98]
    assert slidingWindow([1], 1) == [1]

    print("All test cases passed!")
    
test()

# have an O(nk) sol. (Assuming n >> k). O(k) per step. Want O(1) per step. 
# 100 = max(5, 6, 100, 1, 2)
# max(6, 100, 1, 2, 3)... up till we hit the maximum, only need to check against one other guy
# know 100 = max(6, 100, 1, 2) since 100 not cut out... so compare to 3, 100>3, 100 = max(6, 100, 1, 2, 3)
# max(100, 1, 2, 3, 4). Know max(100, 1, 2, 3) = 100 since 100 not cut out... so compare to 4, 100>4, so 100 = max(100,1,2,3,4)
# max(1, 2, 3, 4, 5). 100 cut out. 
# linked list vibe.. adding and removing one. would be nice if the answer was always the start of the linked list or something. 
# 5->6->100->99->2 
# if you are less than a guy <k ahead of you, you have no shot of being in the ans list. 
# i = 0: 5: nums: 100->99->2. idxs: 2->3->4. since 5,6 have no shot of being the max. ans = [100]
# i = 1: 6: add 3, and pop all guys starting from right less than 3. they have no shot of being the max, since 3 will mog them in later rounds.
# nums: 100->99->3. idxs: 2->3->5. ans = [100, 100]. 
# i = 2: 100: add 4, and pop all guys starting from right less than 4. they have no shot of being max, since 4 will mog them in later rounds.
# nums: 100->99->4, idxs: 2->3->6. ans = [100, 100, 100]
# i = 3: 99: we are past idxs[0], so delete it. nums: 99->4. idxs: 3->6. 
# add 5, and pop all guys starting from right less than 5. nums: 99->5, idxs: 3->7. ans: [100, 100, 100, 99]
# i = 4: 2: we are past idxs[0], so delete it. nums: 5, idxs: 7. 
# add 98, and pop all guys starting from right less than 98. nums: 98, idxs: 8. ans: [100, 100, 100, 99, 98]
# i = 5: 3: we are not past idxs[0], so do nothing. add 7, and pop all guys starting from right less than 7. 
# nums: 98, idxs: 8, ans: [100, 100, 100, 99, 98, 98]. 