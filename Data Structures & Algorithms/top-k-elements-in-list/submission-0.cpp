class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        
        // Step 2: Move to a vector of pairs
        vector<pair<int, int>> freqVec;
        for (auto& [num, freq] : mp) {
            freqVec.push_back({num, freq});
        }
        
        // Step 3: Sort the vector by frequency (highest first)
        // This is a new C++ trick. It uses a "lambda" function to compare the second element of the pairs.
        sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second; // > means descending (highest first)
        });
        
        // Step 4: Grab the top k elements
        vector<int> result;
        for (int i = 0; i < k; i++) {
            // freqVec[i].first is the number, freqVec[i].second is the frequency
            result.push_back(freqVec[i].first);
        }
        
        return result;
    }
};
