// Rod cutting problem

#include<bits/stdc++.h>
using namespace std;

#define SIZE 100

int cut[SIZE][2];


void print_cut_size(int n)
{
    if(cut[n][0] == n){
        cout<<n<<" ";
    }
    else if(cut[n][1] == 0){
        return ;
    }
    else{
        print_cut_size(cut[n][0]);
        print_cut_size(cut[n][1]);
    }
}

int memorized_cut_rod_aux(int p[], int r[], int n)
{
    int q,temp=-1;
    if(r[n]>=0)
        return r[n];

    if(n==0){
        q = 0;
    }
    else{
        q = -1;
        for(int i=1;i<=n;i++){
            q = max(q, p[i]+ memorized_cut_rod_aux(p, r, n-i));
            if(q!=temp){
                cut[n][0] = i;
                cut[n][1] = n-i;
                temp = q;
            }
        }
    }
    r[n] = q;
    return q;
}



int memorized_cut_rod(int p[], int r[], int n)
{
    for(int i=0;i<=n;i++){
        r[i] = -1;
    }
    return memorized_cut_rod_aux(p,r,n);
}

int main()
{
    int p[SIZE]={0}, r[SIZE]={0},n, temp, benefit;

    freopen("input_rod_cutting.txt","r",stdin);

    cout<<"Input total number: ";
    cin>>n;
    cout<<"Input size and price in pair"<<endl;
    for(int i=0;i<n;i++){
        cin>>temp;
        cin>>p[temp];
    }

    cout<<"Input number for benefit: ";
    cin>>n;


    benefit = memorized_cut_rod(p,r,n);
    cout<<"\n\nMaximum benefit for "<<n<<" is : "<<benefit<<endl;
    cout<<"Cutting rod size is: ";
    print_cut_size(n);                          //print which size of rod will cut

}
