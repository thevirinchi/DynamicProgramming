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
