#include<bits/stdc++.h>
using namespace std;
template <typename _tp> inline _tp read(_tp&x){
	char ch=getchar(),sgn=0;x=0;
	while(ch^'-'&&!isdigit(ch))ch=getchar();if(ch=='-')ch=getchar(),sgn=1;
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();if(sgn)x=-x;return x;
}

int main(){
int b,a;
b=read(a);
cout << b;return 0;}

