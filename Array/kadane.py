#program to find the sum of contiguous subarray of numbers that has the largest sum
def maxSubArraySum(arr):
    size = len(arr)
    if size == 0:
        return 0

    max_so_far = float('-inf')
    max_ending_here = 0

    for i in range(0, size):
        max_ending_here = max_ending_here + arr[i]
        if (max_so_far < max_ending_here):
            max_so_far = max_ending_here

        if max_ending_here < 0:
            max_ending_here = 0
    return max_so_far

if __name__ == '__main__':
    arr = [-4, 2, 2, -5, 8, 4, 3]
    print(maxSubArraySum(arr))
