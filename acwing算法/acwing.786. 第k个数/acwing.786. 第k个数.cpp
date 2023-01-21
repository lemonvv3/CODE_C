#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
const int N = 1e6 + 10;// 数据范围:1≤n≤100000    1≤k≤n
int q[N];
int quick_sort(int q[], int l, int r, int k)
{
    // 区间只有一个元素，且k在区间中，则k即为该元素，直接返回即可

    if (l >= r) return q[l];

    int x = q[(l + r) >> 1], i = l - 1, j = r + 1;
    while (i < j)//迭代
    {
        do i++;
        while (q[i] < x);
        do j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
        /* if（i<j）
          {
             int t =q[i];
             q[i]=q[j];
             q[j]=t;
        }*/
    }

    if (j - l + 1 >= k)
        return quick_sort(q, l, j, k);
    // // 除去了j-l+1个比k小的数，那么k是剩下数中的第 k - (j-l+1)大的数
    else return quick_sort(q, j + 1, r, k - (j - l + 1));
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    cout << quick_sort(q, 0, n - 1, k) << endl;
    return 0;
}