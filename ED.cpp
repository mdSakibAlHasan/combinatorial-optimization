// Longest common subsequence
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

#define SIZE 100
#define UP -1
#define LEFT -2
#define CORNER -3
#define EQUAL -4

int operation_counter=0;

int len(char str[])         //length count because it start index 1
{
    int i=1,cnt=0;
    while(str[i]){
        cnt++;
        i++;
    }
    return cnt;
}

void print_operation(char strY[], char strX[], int r[][SIZE],int i, int j)
{
    if(i==0 && j==0)
        return ;

    if(r[i][j] == CORNER){
        print_operation(strY,strX,r,i-1,j-1);
        cout<<++operation_counter<<". Replace "<<strX[i]<<" by "<<strY[j]<<endl;                      //print LCS
    }
    else if(r[i][j] == UP){
        print_operation(strY,strX,r,i-1,j);
        cout<<++operation_counter<<". Delete "<<strX[i]<<" from first string\n";
    }
    else if(r[i][j] == LEFT){
        print_operation(strY,strX,r,i,j-1);
        cout<<++operation_counter<<". Insert "<<strY[j]<<" from second string \n";
    }
    else{
        print_operation(strY,strX,r,i-1,j-1);
    }
}

int main()
{
    char strX[SIZE], strY[SIZE];
    int p[SIZE][SIZE], r[SIZE][SIZE],m,n;
    freopen("input_ED.txt","r",stdin);

    cout<<"Input two string: ";
    scanf("%s%s",&strX[1],&strY[1]);
    m = len(strX);
    n = len(strY);

    for(int i=0;i<=n;i++){          //for first row and column
        p[0][i] = i;
        p[i][0] = i;
        r[0][i] = LEFT;
        r[i][0] = UP;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(strX[i] == strY[j]){
               p[i][j] = p[i-1][j-1];
               r[i][j] = EQUAL;
            }
            else if(p[i-1][j-1] <= p[i][j-1]  &&  p[i-1][j-1] <= p[i-1][j]){
                p[i][j] = p[i-1][j-1] + 1;
                r[i][j] = CORNER;
            }
            else if(p[i][j-1] <= p[i-1][j]){
                p[i][j] = p[i][j-1] + 1;
                r[i][j] = LEFT;
            }
            else{
                p[i][j] = p[i-1][j] + 1;
                r[i][j] = UP;
            }
        }
    }

    cout<<"\n\nThere needed following operation \n";
    print_operation(strY,strX, r, m, n);
}
