#include <cs50.h>
#include <stdio.h>

int binary_search(int arr[], int len, int n);

int main(void)
{
    int arr[] = { -20, -4, -1, 0, 3, 44, 45, 65, 77};
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("Pick a number from the array\n");
    for (int i = 0; i < len; i++)
    {
        if (i == len - 1)
            printf("%d", arr[i]);
        else
            printf("%d, ", arr[i]); 
    }
    printf("\n");
    
    while (1)
    {
        int n = get_int("Number: ");
        int index = binary_search(arr, len, n);
        printf("Index: %d\n", index);
    }
    return 0; 
}

int binary_search(int arr[], int len, int n)
{   
    int start = 0;
    int end = len - 1;
    int found = -1;
    while (start <= end)
    {
        int mid = (start+end) / 2;
        if (n == arr[mid])
        {
            found = mid;
            break;
        }
        else if (n > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return found;
}
