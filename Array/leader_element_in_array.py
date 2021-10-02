def get_leader_elements(arr):
    size = len(arr)
    if size == 0:
        return []

    leader_arr = []
    max_from_right = arr[size - 1]
    leader_arr.append(max_from_right)
    for i in range(size - 2, -1, -1):
        if max_from_right < arr[i]:
            leader_arr.append(arr[i])
            max_from_right = arr[i]
    return leader_arr


# Driver function
if __name__ == "__main__":
    arr = [16, 17, 4, 3, 5, 2]
    print(get_leader_elements(arr))
