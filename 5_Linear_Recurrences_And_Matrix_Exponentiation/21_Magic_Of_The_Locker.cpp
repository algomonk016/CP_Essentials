/*
Magic of the Locker
  Bob, the clever businessman, sells the ropes to his customers at the rate of 1 rupee per meter. He can only sell an integer length of a rope to a customer. Also, he has a magic locker which functions this way:
  Suppose the locker has x rupees. Now if y rupees more are put into this locker, it multiplies them and total money in the locker now is x*y.This morning, Bob starts his business with n meters of rope. He puts 1 rupee in the locker as to have good luck. Find the maximum money he can earn today considering that he sold all of his rope at the end of the day.
  Return the required answer modulo(10^9 + 7).

Constraints:
  1 <= n <= 10^9

Example:
  Input: n = 4
  Output: 4
*/

const int mod = 1e9 + 7;

long long int power(long long a, long long n){
  long long p;

  if(n == 0){
    return 1;
  }

  p = power(a, n>>1);
  p = (p*p)%mod;

  if(n&1){
    p = (p*a)%mod;
  }

  return p;

}

int locker(int n){
  int ans;
  if(n < 2){
    ans = n;
  } else{
    int cnt = n/3;
    int rem = n%3;

    if(rem == 1){
      ans = (power(3, cnt-1)*4)%mod;
    } else if(rem == 2){
      ans = (power(3, cnt)*2)%mod;
    } else{
      ans = power(3, cnt);
    }
  }

  return ans;
}
