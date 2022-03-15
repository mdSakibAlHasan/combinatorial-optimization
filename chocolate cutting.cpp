#include<bits/stdc++.h>
using namespace std;

#define SIZE 100

int cut_chocolate(int p[][SIZE], int r[][SIZE], int row, int column)
{
    int q;
    if(row ==0 || column==0){
        return 0;
    }

    if(r[row][column]>=0){
        return r[row][column];
    }
    else{
        q = -1;
        for(int i=1;i<=row;i++){
            for(int j=1;j<=column;j++){
                q = max (max( q, p[i][column] + cut_chocolate(p, r, row-i, column) ),max( q, p[row][j] + cut_chocolate(p, r, row, column-j) )) ;
            }
        }
        r[row][column] = q;
        p[row][column] = q;     //update p value
        return q;
    }
}


void maximize_cost(int p[][SIZE], int r[][SIZE], int row, int column)
{
    for(int i=0;i<=row;i++){
        for(int j=0;j<=column;j++){
            r[i][j] = -1;
        }
    }
    cout<<"\n\n maximum profit for"<<row<<" * "<<column<<" is: "<<cut_chocolate(p,r,row,column)<<endl;
}


int main()
{
    freopen("input_chocolate_cutting.txt","r",stdin);
    int p[SIZE][SIZE]={0}, r[SIZE][SIZE], row, column;

    cout<<"Input row and column: ";
    cin>>row>>column;

    cout<<row<<" "<<column<<endl;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=column;j++){
            cin>>p[i][j];
        }
    }
    cout<<"Which size chocolate you want to maximum profit (row - column): "<<endl;
    cin>>row>>column;
    maximize_cost(p,r,row,column);
}
