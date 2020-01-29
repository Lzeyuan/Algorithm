#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int const MAX = 0X7FFF;

//输入
int Test[MAX];
int n;

//冒泡排序
int BublleSort(int *Target, int count){
    printf("冒泡排序:\n");
    int flag = 1;
    int Swap = 0;

    for( int i = 1; i <= count - 1 && flag; i++){
        flag = 0;
        for( int j = 1; j <= count - i; j++ ){
            if( Target[j] > Target[j + 1] ){
                flag = 1;
                Swap = Target[j];
                Target[j] = Target[j + 1];
                Target[j + 1] = Swap;
            }
        }
    }

    for( int i = 1; i <= count; i++){
            printf("%5d", Target[i]);
    }
    printf("\n");
    return 0;
}

//快速排序
int QuickSort( int *Target, int Left, int Right){
    if( Right <= Left )
        return 0;

    int i = Left;
    int j = Right;
    int swap = 0;

    while( i < j ){
        while( Target[Left] <= Target[j] && i < j )     //检测右边的数，如果遇到比基准数小的停止
            j--;
        while( Target[Left] >= Target[i] && i < j )     //检测左边的数，如果遇到比基准数大的停止
            i++;
        
        if( i < j ){        //左边大的和右边小的交换，保证左小右大的顺序
            swap = Target[i];
            Target[i] = Target[j];
            Target[j] = swap;
        }
    }

    //第一个数（基准数）放到中间，中间那个数（比基准数小）放到第一位
    swap = Target[i];
    Target[i] = Target[Left];
    Target[Left] = swap;

    //重复上述过程，直到没有数可以拍序
    QuickSort( Target, Left, i - 1);
    QuickSort( Target, i + 1, Right);

    return 0;
}

//插入排序
int InsertSort(int *Target, int count){
    int temp;
    printf("插入排序:\n");
    for( int i = 1; i <= count; i++ ){
        temp = Target[i];
        for( int j = 1; j <= i - 1; j++ ){
            if( Target[i] < Target[j] ){
                for( int k = i; k <= j + 1; k++ ){
                    Target[k] = Target[k - 1];
                }
                Target[j] = temp;
                break;
            }
        }
    }

    for( int i = 1; i <= count; i++){
        printf("%5d", Target[i]);
    }
    printf("\n");

    return 0;
}

//输出数组
void Print(int start, int end){
    for( int i = start; i <= end; i++ ){
                printf("%5d", Test[i]);
        if( i % 30 == 0 )
            cout << endl;
    }
}

int main(){
    //输入
    cout << "\n============输入==========" << endl;
    printf("随机生成n个数(0 <= n < 1E3)：");
    cin >> n;
    printf("\n");

    cout << "============输出==========" << endl;
    //生产随机数列
    srand( (int)time(NULL) );       //保证每次启动程序的随机数不同
    int i;
    cout << "原数组为：\n";
    for( i = 1; i <= n; i++ ){
        Test[i] = rand() % ( n + 1 );       //n 以内的随机数用 rand() % (n + 1)
        printf("%5d", Test[i]);
        if( i % 30 == 0 )
            cout << endl;
    }

    //换行增加美观
    cout << endl;

    //复制原数组，防止原数组被修改
    int temp[MAX];
    memcpy( temp, Test, ( n + 1 )* sizeof(int) );

    //冒泡排序
    BublleSort( temp, n );

    //复制原数组，防止原数组被修改
    memcpy( temp, Test, ( n + 1 )* sizeof(int) );

    //快速排序
    printf("快速排序:\n");
    QuickSort( temp, 1, n );
    //输出排序结果
    for( int i = 1; i <= n; i++){
        printf("%5d", temp[i]);
    }

    cout << endl;

    //插入排序
    InsertSort(temp, n);

    return 0;
}