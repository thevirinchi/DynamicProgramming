/* QUESTION 1 */
#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c){
  if(isupper(c))
    c = tolower(c);
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int distVow(string s, int k = 1){
  int cnt[128];
  memset(cnt, 0, sizeof(cnt));
  int res = -1;
  int n = s.length();
  for(int i = 0, j = -1; i < n; ++i){
    char c = s[i];
    if(isVowel(c))
      if(++cnt[c] == 1)
        --k;
    while(k < 0){
      c = s[++j];
      if(isVowel(c))
        if(--cnt[c] == 0)
          ++k;
    }
    if(k == 0)
      res = max(res, i-j);
  }
  return res;
}

int main(){
  string one;
  cout << "Enter a string: ";
  cin >> one;
  cout << distVow(one, 1);
  return 0;
}


/* QUESTION 2 */
#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int W, int n, int val[], int wt[]){
    int dp[W+1];
    memset(dp, 0, sizeof dp);
    int ans = 0;
    for (int i=0; i<=W; i++)
      for (int j=0; j<n; j++)
         if (wt[j] <= i)
            dp[i] = max(dp[i], dp[i-wt[j]]+val[j]);

    return dp[W];
}

int main(){
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val)/sizeof(val[0]);
    cout << unboundedKnapsack(W, n, val, wt);
    return 0;
}

/* QUESTION 3 */
