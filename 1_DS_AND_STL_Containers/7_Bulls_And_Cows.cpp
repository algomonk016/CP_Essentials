/*
Bulls and Cows
  You are playing the Bulls and Cows game with your friend.
  You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:
  The number of "bulls", which are digits in the guess that are in the correct position.
  The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
  Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.
  The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

Constraints
  1 <= secret.length, guess.length <= 1000
  secret.length == guess.length

Input: secret = "1123", guess = "0111"
Output: "1A1B"

*/ 

string getHint(string secret, string guess) {
  int bulls = 0, cows = 0;
  int n = secret.length();
  map<char, int> mp1, mp2;
  
  for(int i=0; i<n; i++){
    if(secret[i] == guess[i]){
      bulls++;
    } else{
      mp1[secret[i]]++;
      mp2[guess[i]]++;
    }
  }
  
  for(auto &i: mp1){
    auto [ch, cnt] = i;
    cows += min(cnt, mp2[ch]);
  }
  
  string ans = "";
  ans += to_string(bulls);
  ans += "A";
  ans += to_string(cows);
  ans += "B";
  
  return ans;
}