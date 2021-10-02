# Minimum number of platforms needed

def min_platform_needed(arrival, depature) -> int:
    if len(arrival) != len(depature) or len(arrival) == 0:
        return -1

    size = len(arrival)
    arrival.sort()
    depature.sort()

    res, c = 1, 1
    i, j = 1, 0
    while i<size and j<size:
        if arrival[i] <= depature[j]:
            i += 1
            c += 1
        else:
            j += 1
            c -= 1
        res = max(c, res)

    return res

if __name__ == "__main__":
    arrival = [0,10,20,13,15,18]
    departure = [5,13,15,21,17,28]

    print(min_platform_needed(arrival, departure))
