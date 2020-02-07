#include <iostream>

using namespace std;

//范围
int const MAX_N = 30;

//输入
int n;
int arry[MAX_N][MAX_N];


int BFS(int, int);
typedef struct {
    int x,y;
}Queue;

//slove
int slove(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arry[i][j] == 1) {
                return BFS(i, j);
            }
        }
    }
    return 0;
}

//填充
int BFS(int x, int y) {

    x += 1;
    y += 1;
    arry[x][y] = 2;

    //初始化队列
    Queue queue[MAX_N * MAX_N * 10];
    int head, tail;
    head = tail = 0;
    queue[head].x = x;
    queue[head].y = y;
    tail++;

    //下右左上
    int step[5] = {0, 1, 0, -1, 0};
    int now_x, now_y;
    while( head < tail ) {
        for (int i = 0; i < 4; i++) {
            now_x = step[i] + queue[head].x;
            now_y = step[i + 1] + queue[head].y;

            //判断越界
            if(1 <= arry[now_x][now_y])
                continue;

            //圈内为0
            if(0 == arry[now_x][now_y]) {
                //填2
                arry[now_x][now_y] = 2;

                //入队
                queue[tail].x = now_x;
                queue[tail].y = now_y;
                tail++;
            }
        }
        //出队
        head++;
    }

    return 0;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arry[i][j];
        }
    }

    //填充
    slove();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arry[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}