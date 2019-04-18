#include <bits/stdc++.h>
using namespace std;

int lcs(string one, string two, int i, int j, int count){
  if(!i || !j)
    return count;
  if(one[i-1] == two[j-1])
    count = lcs(one, two, i-1, j-1, count+1);
  else
    count = max(count, max(lcs(one, two, i-1, j, count), lcs(one, two, i, j-1, count)));
  return count;
}

int main(){
  string one;
  string two;
  cout << "Enter the first string: ";
  cin >> one;
  cout << "Enter the second string: ";
  cin >> two;
  cout << lcs(one, two, one.length(), two.length(), 0);
  return 0;
}
