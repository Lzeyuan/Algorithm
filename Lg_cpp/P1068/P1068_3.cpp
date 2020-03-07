#include <iostream>
#include <algorithm>

using namespace std;

//范围
int const MAX_N = 5E3;
int const MAX_M = 5E3;
int const MAX_K = 9999;

struct Inter {
    int number;
    int exam;
}inter[MAX_N + 1];

//输入
int n;  //报名人数
int m;  //录取人数

//快排判断
bool cmp(Inter a, Inter b) {
    return a.number > b.number;
}

//冒泡
void Bublle() {
    bool flag = true;
    for (int i = 1; i <= n && flag; i++) {
        flag = false;
        for (int j = 1; j <= n - i; j++) {
            if (inter[j + 1].exam < inter[j].exam) {
                Inter t = inter[j + 1];
                inter[j + 1 ] = inter[j];
                inter[j] = t;
                flag = true; 
            }
        }
    }
}

int main() {
    int i;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> inter[i].number >> inter[i].exam;
    }

   
    sort(inter + 1, inter + n + 1, cmp);
    /* cout << "================================" << endl;
    for (i = n; i >= 1; i--) { 
        cout << inter[i].number << ' ' << inter[i].exam << endl;
    } */

    Bublle();

    m *= 1.5;

    int aim = inter[n - m + 1].exam;
    
    
    for (i = n; i >= 1; i--) {
        if (inter[i].exam < aim) {
            break;
        }
    }

    cout << inter[n - m + 1].exam << ' ' << n - i << endl;;

    for (i = n; i >= 1; i--) {
        if (inter[i].exam >= aim) {
            cout << inter[i].number << " " << inter[i].exam << endl;
        } else {
            break;
        }
    }

    return 0;
}