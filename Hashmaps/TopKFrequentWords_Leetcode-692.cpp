class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    // intuitive approach (not the best)
    unordered_map<string, int> freq;

    for (string s : words) {
      freq[s]++;
    }

    vector<string> uniqueWords;
    for (auto pair : freq) {
      uniqueWords.push_back(pair.first);
    }

    sort(uniqueWords.begin(), uniqueWords.end(), [&](string &a, string &b) {
      if (freq[a] == freq[b]) {
        return a < b;
      }

      return freq[a] > freq[b];
    });

    return vector<string>(uniqueWords.begin(), uniqueWords.begin() + k);
  }
};