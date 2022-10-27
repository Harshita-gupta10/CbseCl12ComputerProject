#include <bits/stdc++.h>
using namespace std;

void merge(int nums1[], int n, int nums2[], int m, int arr3[])
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (nums1[i] < nums2[j])
        {
            arr3[k++] = nums1[i++];
        }
        else
        {
            arr3[k++] = nums2[j++];
        }
    }

    while (i < n)
    {
        // copy elements of first array
        arr3[k++] = nums1[i++];
    }

    while (j < m)
    {
        // copy elements of second array
        arr3[k++] = nums1[j++];
    }
}

int print(int arr3[], int n)
{
    for (int i = 0; i< n; i++)
    {
        cout<< arr3[i]<< " ";
    }
    cout<<endl;
}

int main()
{
    int arr1[]= {1,3,5,7,9};
    int arr2 [] = {2,4,6};
    int arr3[8]= {0};

    merge(arr1, 5, arr2, 3, arr3);
    print(arr3, 8);
    return 0;
}
