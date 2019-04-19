#include <bits/stdc++.h>
using namespace std;

int infKnapSack(int val[], int wt[], int w, int n){
    int dp[w+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= w; i++)
      for(int j = 0; j < n; j++)
        if(wt[j] <= i)
          dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
    return dp[w];
}

int main(){
  int wt[] = {1, 3, 5};
  int val[] = {10, 5, 1};
  int w = 10;
  cout << infKnapSack(val, wt, w, sizeof(val)/sizeof(val[0]));
  return 0;
}
