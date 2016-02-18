
#include <stdio.h>
#include <stdlib.h>
#define MAX 200000

struct Point{
    int x, y;
};
int compareByX(const void* a, const void* b)
{
    return ((struct Point*)a)->x - ((struct Point*)b)->x;
}

int n;
struct Point a[MAX];//all points
int ay[MAX];        //made of each point's y coordinate
int ordered;        //record how many ordered pairs that is ay[i] < ay[k], before sort ay[]


void merge(int dest[], int src[], int startIndex, int midIndex, int endIndex)
{
    int i = startIndex, j = midIndex + 1, k = startIndex;
    for(; i <= midIndex && j <= endIndex; ++k){
        if(src[i] > src[j]) dest[k] = src[j++];
        else{
            dest[k] = src[i++];
            ordered += endIndex - j + 1;  //here record how many ordered pairs in this segment
        }
    }
    for(; i <= midIndex; ++k, ++i) dest[k] = src[i];
    for(; j <= endIndex; ++k, ++j) dest[k] = src[j];
}

void mergeSort(int dest[], int src[], int startIndex, int endIndex, int mergeIntoSrc)
{
    if(startIndex == endIndex){
        dest[startIndex] = src[startIndex];
    }
    else{
        int midIndex = (startIndex + endIndex) >> 1;
        mergeSort(dest, src, startIndex, midIndex, !mergeIntoSrc);  //use as temporary storage
        mergeSort(dest, src, midIndex+1, endIndex, !mergeIntoSrc);  //use as temporary storage
        if(mergeIntoSrc) merge(src, dest, startIndex, midIndex, endIndex);//store the ordered array to src
        else merge(dest, src, startIndex, midIndex, endIndex);            //store the ordered array to dest
    }
}

void merge_sort(int a[], int n)
{
    static int help[MAX];         //helper space used in merge sort
    mergeSort(help, a, 0, n-1, 1);//use help as temporary storage, store the ordered array to a
}

int main()
{
    int i;
    //input
    scanf("%d", &n);
    for(i = 0; i < n; ++i) scanf("%d%d", &a[i].x, &a[i].y);
    if(n < 2){   //can not make any pair
        puts("0");
        return 0;
    }

    //sort by x, from small to big, then put each point's y into ay[]
    qsort(a, n, sizeof(a[0]), compareByX);
    for(i = 0; i < n; ++i) ay[i] = a[i].y;

    //count the number ordered pairs, which indicates that a[i].x < a[k].x && a[i].y < a[k].y
    ordered = 0;
    merge_sort(ay, n);
    printf("%d\n", ordered);

    return 0;
}
