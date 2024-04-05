def main() -> None:
    A = [10, 3, 4, 9, 1, 11, 17, 3, 9]
    insertion_sort(A, len(A))
    print(str(A))


def insertion_sort(A: list[int], n: int) -> None:
    for i in range(1, n):
        key = A[i]
        j = i - 1
        while j >= 0 and A[j] > key:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = key


if __name__ == "__main__":
    main()
