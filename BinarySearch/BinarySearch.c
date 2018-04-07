#define MAX 10

//Assuming that array is presorted

int binarySearch(int array[], int x) {
    int mid = MAX / 2;
    for (int i = 1; i < MAX; i++) {
        if (array[mid] == x)
            return mid;
        else if (array[mid] > x)
            mid = mid / 2;
        else if (array[mid] < x)
            mid = (MAX + mid + 1) / 2;
    }
    return -1;
}