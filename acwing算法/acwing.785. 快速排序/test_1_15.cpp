#define _CRT_SECURE_NO_WARNINGS 1
/*acwing.785. 快速排序*/
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
int q[N];
void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;    //如果左边界大于右边界，则说明数组为空，直接return（判边界）

    int x = q[(l + r) >> 1], i = l - 1, j = r + 1; //取中间点为临界点 
    //int x = q[l], i = l-1, j = r+1;  //取左临界点
    //int x=  q[r], i=l,j=r-1//取右临界点

    while (i < j)  //迭代
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
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);//注意：用i不能用l做边界，用j不能用做边界，否则容易死循环
}
int main()
{
    scanf("%d", &n);//输入n个数
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
    return 0;
}