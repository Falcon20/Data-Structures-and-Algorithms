# Python program to sort an array with
# 0, 1 and 2 in a single pass

# Function to sort array
def dutch_sorting_algo(arr):
    size = len(arr)
    if size == 0:
        return []
    lo = 0
    hi = size - 1
    mid = 0
    while mid <= hi:
        if arr[mid] == 0:
            arr[lo], arr[mid] = arr[mid], arr[lo]
            lo = lo + 1
            mid = mid + 1
        elif arr[mid] == 1:
            mid = mid + 1
        else:
            arr[mid], arr[hi] = arr[hi], arr[mid]
            hi = hi - 1
    return arr

# Driver Program
if __name__ == "__main__":
    arr = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
    arr = dutch_sorting_algo(arr)
    print(f"After sorting array is : {arr}")
