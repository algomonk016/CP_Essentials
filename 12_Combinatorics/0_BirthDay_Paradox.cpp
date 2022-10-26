/*
Birth Day Paradox
minimum number of people such that probability of having two people with same bday is 50%

p(having same bday) = 1 - p(having diff bday)

p(having diff bday)
  1 -> 365/365 -> 1
  2 -> 1 * (364/365) -> 0.97
  3 -> 0.97 * (363/365) -> 0.91
  ..
  p -> 0.4....
*/
#include "bits/stdc++.h"
using namespace std;

void solve() {
  double ans = 1;
  int cnt = 1;
  for(double i = 364.0; i >= 1.0; i--){
    ans *= (i/365);
    cnt++;
    if(ans < .50){
      break;
    }
  }

  cout<<cnt<<endl;
}
