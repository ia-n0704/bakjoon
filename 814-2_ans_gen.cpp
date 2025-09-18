# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int ch;
int go=8;
int mxnum=8099;
int real_mxnum;
int real_mx;
int X[10]={-1,-1,-1,0,1,1,1,0};
int Y[10]={-1,0,1,1,1,0,-1,-1};
int c[100];
int arr[10][20];
int brr[10][20]={
{},
{0,5,5,0,7,8,5,9,1,6,9,5,2,7,5},
{0,1,2,9,9,4,8,1,2,7,0,8,3,0,8},
{0,6,4,3,6,6,0,2,4,0,7,4,9,9,1},
{0,2,8,3,1,9,6,3,5,6,4,5,5,2,7},
{0,8,5,7,2,5,4,7,3,2,6,3,1,8,2},
{0,1,8,6,7,0,5,1,9,8,2,1,8,6,3},
{0,4,4,9,1,3,8,6,0,4,4,7,0,3,5},
{0,2,9,1,3,4,9,2,7,0,3,5,9,0,1},


};
int crr[10][20];
int mx;
void check(int num,int x,int y)
{
    //cout<<num<<" "<<x<<" "<<y<<'\n';
    if(ch) return;
    if(num==0)
    {
        ch=1;
        return;
    }
    for(int i=0;i<8;i++)
    {
        int nx=x+X[i];
        int ny=y+Y[i];
        if(nx<1 || nx>8 || ny<1 || ny>14) continue;
        if(arr[nx][ny]==num%10)
            check(num/10,nx,ny);
    }
}
int main()
{
    fastio;
    clock_t st,en;
    ofstream writeFile;
    ifstream readFile;
    readFile.open("mx.txt");
    readFile>>real_mx;
    readFile.close();
    mx=real_mx;
    readFile.open("814-2_ans.txt");
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=14;j++)
        {
            int a;
            readFile>>a;
            cout<<a<<" ";
            crr[i][j]=brr[i][j]=a;
        }
    }
    readFile.close();
    srand(time(NULL));
    int x,y;
    int cnnt=0;
    int cs=0;
    st=clock();
    while(1)
    {
        if(cnnt!=0 && cnnt%15000==0)
        {
            printf("-------------------\n");
            int flag=0;
            for(int i=1;i<=8;i++)
            {
                for(int j=1;j<=14;j++)
                    if(crr[i][j]!=brr[i][j]) flag=1;
            }
            for(int i=1;i<=8;i++)
            {
                for(int j=1;j<=14;j++)
                    brr[i][j]=crr[i][j];
            }
            if(flag==0)
            {
                if(cs)
                {
                    en=clock();
                    printf("case %d\n",cs);
                    printf("실행시간 : %llf\n",(double)(en-st)/CLOCKS_PER_SEC);
                    printf("최댓값 : %d\n",mx);
                    printf("-------------------\n");
                }
                for(int j=1;j<=rand()%5+1;j++)
                {
                    int x=rand()%8+1;
                    int y=rand()%14+1;
                    int n;
                    do
                    {
                        n=rand()%10;
                    }while(n==crr[x][y]);
                    if((x==3 || x==6) && (y==1 || y==4 || y==7 || y==10 || y==13)) continue;
                    crr[x][y]=n;
                }
                mx=0;
                st=clock();
            }
            cs++;
        }
        for(int i=1;i<=8;i++)
        {
            for(int j=1;j<=14;j++)
                arr[i][j]=crr[i][j];
        }
        if(cnnt%15000!=0)
        {
            for(int i=1;i<=rand()%50+1;i++)
            {
                int x=rand()%8+1;
                int y=rand()%14+1;
                int n=rand()%10;
                if((x==3 || x==6) && (y==1 || y==4 || y==7 || y==10 || y==13)) continue;
                arr[x][y]=n;
            }
        }
        cnnt++;
        //vector<pair<int,int>> vec;
        /*for(int i=1;i<=8;i++)
        {
            for(int j=1;j<=14;j++)
            {
                int t=rand()%10;
                if(t<0) continue;
                arr[i][j]=rand()%10;
            }
        }*/
        /*if(go==8)
        {
            go=0;
            x=rand()%8+1;
            y=rand()%14+1;
        }
        go++;
        arr[x][y]=go;*/
        int cnt=1;
        while(1)
        {
            //cout<<"| "<<cnt<<'\n';
            ch=0;
            for(int i=1;i<=8;i++)
            {
                for(int j=1;j<=14;j++)
                {
                    if(arr[i][j]!=cnt%10) continue;
                    ch=0;
                    check(cnt/10,i,j);
                    if(ch) break;
                    //cout<<'\n';
                }
                if(ch) break;
            }
            if(ch==0)
                break;
            else cnt++;
        }

        //new attempt
        /*vector<int> miss;
        int num=0;
        for(int r=1;r<=9999;r++)
        {
            int cnt=r;
            ch=0;
            for(int i=1;i<=8;i++)
            {
                for(int j=1;j<=14;j++)
                {
                    if(arr[i][j]!=cnt%10) continue;
                    ch=0;
                    check(cnt/10,i,j);
                    if(ch) break;
                    //cout<<'\n';
                }
                if(ch) break;
            }
            if(ch) num++;
            else miss.push_back(cnt);
        }*/

        //cout<<cnt<<'\n';
        if(cnt>mx) printf("%d (%.2llf프로 완료.)\n",cnt,(double)(cnt*100.0)/8140.0);
        if(cnt>=3001)
        {
            cout<<cnt<<'\n';
            break;
        }
        if(cnt>mx)
        {
            printf("\n");
            for(int i=1;i<=8;i++)
                for(int j=1;j<=14;j++)
                    crr[i][j]=arr[i][j];
            mx=cnt;
            if(real_mx<mx)
            {
                writeFile.open("814-2_ans.txt");
                for(int i=1;i<=8;i++)
                {
                    for(int j=1;j<=14;j++)
                        writeFile<<crr[i][j]<<" ";
                    writeFile<<"\n";
                }
                writeFile.close();
                writeFile.open("mx.txt");
                real_mxnum=mx;
                writeFile<<mx<<'\n';
                writeFile.close();
            }
        }
        /*if(num>mxnum)
        {
            printf("%d (%.2llf프로 완료.)\n",num,(double)(num*100.0)/9970.0);
        }
        if(mxnum<num)
        {
            //for(auto i:miss)
              //  printf("%d ",i);
            printf("\n");
            for(int i=1;i<=8;i++)
                for(int j=1;j<=14;j++)
                    crr[i][j]=arr[i][j];
            mxnum=num;
            if(real_mxnum<mxnum)
            {
                writeFile.open("814-2.txt");
                for(int i=1;i<=8;i++)
                {
                    for(int j=1;j<=14;j++)
                        writeFile<<crr[i][j]<<" ";
                    writeFile<<"\n";
                }
                writeFile.close();
                writeFile.open("mxnum.txt");
                real_mxnum=mxnum;
                writeFile<<mxnum<<'\n';
                writeFile.close();
            }
        }
        if(mxnum>=9970)
        {
            cout<<mxnum<<'\n';
            break;
        }*/
    }
    cout<<mx<<'\n';
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=14;j++)
            cout<<arr[i][j];
        cout<<'\n';
    }
}
