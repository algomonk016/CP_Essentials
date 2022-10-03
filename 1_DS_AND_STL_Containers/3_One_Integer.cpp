/*
One Integer
  You are given a list of integers nums. You can reduce the length of nums by taking any two integers, removing them, and appending their sum to the end. The cost of doing this is the sum of the two integers you removed.
  Return the minimum total cost of reducing nums to one integer.

Note : Cost can be negative also.
*/ 

int solve(vector<int> nums){
  priority_queue<int, vector<int>, greater<int>> p;

  int ans = 0, n = nums.size();
  for(auto &i: nums){
    p.push(i);
  }

  while(n > 1){
    int sum = p.top();
    p.pop();
    sum += p.top();
    p.pop();

    ans += sum;
    p.push(sum);
    n--;
  }

  return ans;
}
