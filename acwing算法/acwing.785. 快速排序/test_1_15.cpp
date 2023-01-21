#define _CRT_SECURE_NO_WARNINGS 1
/*acwing.785. ��������*/
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
int q[N];
void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;    //�����߽�����ұ߽磬��˵������Ϊ�գ�ֱ��return���б߽磩

    int x = q[(l + r) >> 1], i = l - 1, j = r + 1; //ȡ�м��Ϊ�ٽ�� 
    //int x = q[l], i = l-1, j = r+1;  //ȡ���ٽ��
    //int x=  q[r], i=l,j=r-1//ȡ���ٽ��

    while (i < j)  //����
    {
        do i++;
        while (q[i] < x);
        do j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
        /* if��i<j��
          {
             int t =q[i];
             q[i]=q[j];
             q[j]=t;
        }*/
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);//ע�⣺��i������l���߽磬��j���������߽磬����������ѭ��
}
int main()
{
    scanf("%d", &n);//����n����
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
    return 0;
}