#include<bits/stdc++.h>
using namespace std;
 
int main(){
  long long n;  cin >> n;
  while(1){
    cout << n << " ";
    if(n==1)  break;
    if(n&1) n = 3*n + 1;
    else  n >>= 1;
  }
  cout << "\n";
  return 0;
}
