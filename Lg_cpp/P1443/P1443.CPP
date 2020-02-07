#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

//范围
int const MAX_N = 400;  //行
int const MAX_M = 400;  //列

//输入
int n, m;
int arry[MAX_N + 1][MAX_M + 1];
int start_x, start_y;

int DFS(int step, int x, int y);

//slove
int slove(){
    memset(arry, -1, sizeof(arry));

    //起点为0
    arry[start_x][start_y] = 0;

    //DFS探路
    DFS(1, start_x, start_y);

    return 0;
}

//马走日,右下左上
int step[8][2] = 
{
    {-2, -1},
    {-2, 1},
    {-1, 2},
    {1, 2},
    {2, 1},
    {2, -1},
    {1, -2},
    {-1, -2}
};

//DFS
int DFS(int s,int x, int y){
    //试探坐标
    int t_x, t_y;

    for (int i = 0; i < 8; i++) {
        t_x = x + step[i][0];
        t_y = y + step[i][1];

        //判断越界
        if (t_x < 1 || t_x > n || t_y < 1 || t_y > m) {
            continue;
        }

        //判读步数
        if (arry[t_x][t_y] > s || -1 == arry[t_x][t_y]) {   //如果步数比该空低，则填入
            arry[t_x][t_y] = s;     //填入
            //printf("%d %d\n", t_x, t_y);
            DFS(s + 1, t_x, t_y);
        }
    }

    return 0;
}

int main(){
    cin >> n >> m;
    cin >> start_x >> start_y;

    //判断
    slove();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", arry[i][j]);
        }
        printf("\n");
    }

    return 0;
}