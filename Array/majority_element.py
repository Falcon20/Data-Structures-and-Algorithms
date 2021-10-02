# Moore's algorithm - Find majority element in array in 2 passes

def find_majority_element(arr):
    size = len(arr)
    if size == 0:
        return -1
    element = -1
    cnt = 0
    for item in arr:
        if cnt == 0:
            element = item
        cnt = cnt + 1 if element == item else cnt - 1
    cnt = 0
    for item in arr:
        if item == element:
            cnt += 1
    if cnt >= size/2:
        return element
    return -1


if __name__ == "__main__":
    arr = [1,2,1,4,1,5,1,6]
    majority_element = find_majority_element(arr)
    if majority_element != -1:
        print(f"Majority element is: {majority_element}")
    else:
        print("No majority element in array")
