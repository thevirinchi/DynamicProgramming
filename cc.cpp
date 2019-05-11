#include<bits/stdc++.h>
using namespace std;
int cc(int ar[],int n,int amt)
{
  int sol[n+1][amt+1],i,j;
  for(i = 0; i <=n; i++)
    sol[i][0] = 0;
  for(i=0;i<=amt;i++)
      {if(ar[0]>i)
        sol[0][i]=0;
      else
        sol[0][i]=1+sol[0][i-ar[0]];}
  for(i=1;i<=n;i++)
    for(j=1;j<=amt;j++)
    {

        if(ar[i]>j)
         sol[i][j]=sol[i-1][j];
         else
         sol[i][j]=min(sol[i-1][j],1+sol[i-1][j-ar[i]]);

    }

  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= amt; j++)
      cout << " " << sol[i][j] << " ";
    cout << endl;}
  return sol[n][amt];
}
int main()
{
int ar[]={1,2,5,6,10};
int amt=12;
cout<<cc(ar,5,amt);
return 0;
}
