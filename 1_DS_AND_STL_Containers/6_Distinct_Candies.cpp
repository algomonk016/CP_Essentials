/*
Distinct Candies
  Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor.
  The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice.
  Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

Constraints:
n == candyType.length
2 <= n <= 10^4
n is even.
-10^5 <= candyType[i] <= 10^5
*/

int distributeCandies(vector<int> candies) {
  unordered_set<int> st;
  for(auto &i: candies){
    st.insert(i);
  }
  
  int n = candies.size();
  int nn = st.size();

  return min(n/2, nn);
}