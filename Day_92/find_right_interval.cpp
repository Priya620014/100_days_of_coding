class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> result(n, -1);
        vector<pair<int, int>> starts;
        
        for (int i = 0; i < n; i++) {
            starts.push_back({intervals[i][0], i});
        }
        
        sort(starts.begin(), starts.end());
        
        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            int left = 0, right = n - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (starts[mid].first < end) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            if (starts[left].first >= end) {
                result[i] = starts[left].second;
            }
        }
        
        return result;
    }
};