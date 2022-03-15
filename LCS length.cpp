// Longest common subsequence
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

#define SIZE 100
#define UP -1
#define LEFT -2
#define CORNER -3


int len(char str[])         //length count because it start index 1
{
    int i=1,cnt=0;
    while(str[i]){
        cnt++;
        i++;
    }
    return cnt;
}

void print_LCS(char strX[], int r[][SIZE],int i, int j)
{
    if(i==0 || j==0)
        return ;

    if(r[i][j] == CORNER){
        print_LCS(strX,r,i-1,j-1);
        cout<<strX[j];                      //print LCS
    }
    else if(r[i][j] == UP){
        print_LCS(strX,r,i-1,j);
    }
    else{
        print_LCS(strX,r,i,j-1);
    }
}

int main()
{
    char strX[SIZE], strY[SIZE];
    int p[SIZE][SIZE], r[SIZE][SIZE],m,n;
    freopen("input_lcs.txt","r",stdin);

    cout<<"Input two string: ";
    scanf("%s%s",&strX[1],&strY[1]);
    n = len(strX);
    m = len(strY);

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(strY[i] == strX[j]){
               p[i][j] = p[i-1][j-1]+1;
               r[i][j] = CORNER;
            }
            else if(p[i-1][j]>=p[i][j-1]){
                p[i][j] = p[i-1][j];
                r[i][j] = UP;
            }
            else{
                p[i][j] = p[i][j-1];
                r[i][j] = LEFT;
            }
        }
    }

    cout<<"\n\nLongest common subsequence: ";
    print_LCS(strX, r, m, n);

}
