class Solution {
public:
  int maxFrequencyElements(vector<int> &nums) {
    // intuitive
    unordered_map<int, int> m;

    for (int i : nums) {
      m[i]++;
    }

    int total = 0;
    int maxi = 0;
    for (auto i = m.begin(); i != m.end(); i++) {
      if (i->second > maxi) {
        maxi = i->second;
        total = maxi;
      } else if (i->second == maxi) {
        total += maxi;
      }
    }
    return total;
  }
};