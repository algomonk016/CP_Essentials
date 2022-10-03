/*
Find K Closest Elements
  Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

  An integer a is closer to x than an integer b if:
  |a - x| < |b - x|, or |a - x| == |b - x| and a < b
*/

/* Approach 1, using vector and custom compare */ 
int targetNum;
bool compare(int x, int y){
  return abs(x - targetNum) < abs(y - targetNum);
}

vector<int> findClosestElements(vector<int> arr, int k, int x){
  targetNum = x;
  sort(arr.begin(), arr.end(), compare);

  vector<int> ans(k);
  for (int i = 0; i < k; i++){
    ans[i] = arr[i];
  }

  sort(ans.begin(), ans.end());

  return ans;
}

/* approach 2, using priority_queue */
vector<int> findClosestElements(vector<int> arr, int k, int x) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  
  for(auto &i: arr){
    pq.push({abs(i-x), i});
  }
  
  vector<int> ans(k);
  for(int i=0; i<k; i++){
    ans[i] = pq.top().second;
    pq.pop();
  }
  
  sort(ans.begin(), ans.end());
  
  return ans;
}