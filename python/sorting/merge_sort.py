def main() -> None:
    A = [10, 3, 4, 9, 1, 11, 17, 3, 9]
    merge_sort(A, 0, len(A))
    print(str(A))


def merge_sort(A: list[int], left: int, right: int) -> None:
    if left >= right:
        return

    mid = (left + right) // 2
    merge_sort(A, left, mid)
    merge_sort(A, mid + 1, right)
    merge(A, left, mid, right)


def merge(A: list[int], left: int, mid: int, right: int) -> None:
    L = A[left:mid]
    R = A[mid:right]

    i, j, k = 0, 0, left
    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
        k += 1

    while i < len(L):
        A[k] = L[i]
        i += 1
        k += 1

    while j < len(R):
        A[k] = R[j]
        j += 1
        k += 1


if __name__ == "__main__":
    main()
