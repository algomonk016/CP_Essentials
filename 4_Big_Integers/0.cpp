#include <bits/stdc++.h>
using namespace std;

string addNumbers(string a, string b){
  if(a.length() > b.length()){
    swap(a, b);
  }

  string ans = "";
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  int rem = 0;
  for(int i=0; i<a.length(); i++){
    int d1 = a[i] - '0';
    int d2 = b[i] - '0';

    int sum = d1 + d2 + rem;
    if(sum >= 10){
      rem = sum/10;
      sum %= 10;
    }
    ans += sum + '0';
  }

  for(int i=a.length(); i<b.length(); i++){
    int d = b[i] - '0';
    int sum = d + rem;
    if(sum >= 10){
      rem = sum/10;
      sum %= 10; 
    }
    ans += sum + '0';
  }

  reverse(ans.begin(), ans.end());
  return ans;
}

void multiplyNumbers(vector<int> &a, int no, int &size){
  int carry = 0;

  for(int i=0; i<size; i++){
    int product = a[i]*no + carry;
    a[i] = product % 10;
    carry = product / 10;
  }

  //handle carry
  while(carry){
    a[size] = carry % 10;
    carry /= 10;
    size++;
  }
}

void bigFactorial(int n){
  vector<int> a(1000, 0);
  a[0] = 1;
  int size = 1;

  for(int i=2; i<=n; i++){
    multiplyNumbers(a, i, size);
  }

  for(int i=size-1; i>=0; i--){
    cout<<a[i];
  }
  cout<<endl;
}
