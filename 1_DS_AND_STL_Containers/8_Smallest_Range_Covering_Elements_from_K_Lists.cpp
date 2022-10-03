/*
Smallest Range Covering Elements from K Lists
  You have k lists of integers . Find the smallest range that includes at least one number from each of the k lists.
  We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

Constraints:
  nums.length == k
  1 <= k <= 3500
  1 <= nums[i].length <= 50
  -10^5 <= nums[i][j] <= 10^5
  nums[i] is not sorted in non-decreasing order.

Example :
  Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
  Output: [20,24]
*/ 

vector<int> smallestRange(vector<vector<int>> nums) {
  vector<pair<int, int>> vp;
  int k = nums.size();
  for(int i=0; i<k; i++){
    sort(nums[i].begin(), nums[i].end());
    for(auto &j: nums[i]){
        vp.push_back({ j, i });
    }
  }
  
  sort(vp.begin(), vp.end());
  int l = 0, r = 0;
  vector<int> res;
  
  map<int, int> mp;
  while(r < vp.size()){
    mp[vp[r].second]++;
    
    while(mp.size() == k){
      if(res.empty() || vp[r].first - vp[l].first < res[1] - res[0]){
        res = { vp[l].first, vp[r].first };
      }
      mp[vp[l].second]--;
      
      if(mp[vp[l].second] == 0){
        mp.erase(vp[l].second);
      }
      l++;
    }
    
    r++;
  }
    
  return res;
}