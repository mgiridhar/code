# https://www.geeksforgeeks.org/sort-array-swapping-special-element-allowed/

def swap(x, y):
    return y, x

def sortBySwap(arr):
    # moving space at the end
    for i in range(0, len(arr)):
        if arr[i] == 999:
            arr[i], arr[len(arr) - 1] = arr[len(arr) - 1], arr[i]
            break
    
    i = 0
    while i < len(arr) - 1:
        if arr[i] == i + 1:
            i += 1
            continue
        j = arr[i] - 1
        #print arr
        # two swaps with the space
        arr[j], arr[len(arr) - 1] = swap(arr[j], arr[len(arr) - 1])
        #print arr
        arr[i], arr[j] = swap(arr[i], arr[j])
        #print arr
        arr[i], arr[len(arr) - 1] = swap(arr[i], arr[len(arr) - 1])
        #print arr
        #break


if __name__ == "__main__":
    arr = map(int, raw_input().strip().split(','))
    sortBySwap(arr)
    print arr
