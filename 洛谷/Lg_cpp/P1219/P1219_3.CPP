#include <iostream>

using namespace std;

const int SIZE = 100;

bool col[14] = {0}, ld[SIZE] = {0}, rd[SIZE] = {0};
int step[14] = {0}, times = 0;
int n, ans = 0;

int queen(int row)
{
    if( row == n + 1 )
    {
        ans++;
        int i;
        if( times < 3 )
        {
            for( i = 1; i <= n ; i++ )
                cout << step[i] << ' ';
            cout << endl;
            times++;
        }

        return 0;
    }

    for ( int i = 1; i <= n; i++ )
    {
        if( !col[i] && !rd[i + row] && !ld[n - i + row] )
        {
            col[i] = true;
            rd[i + row] = true;
            ld[n - i + row] = true;
            step[row] = i;
            queen(row + 1);
            step[row] -= i;
            col[i] = false;
            rd[i + row] = false;
            ld[n - i + row] = false;
        }
    }
    return 1;
}

int main()
{
    cin >> n;

    queen(1);

    cout << ans;

    return 0;
}