class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
         auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            double gainA = (double)(a.first + 1) / (a.second + 1) - (double)(a.first) / a.second;
            double gainB = (double)(b.first + 1) / (b.second + 1) - (double)(b.first) / b.second;
            return gainA < gainB;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        for (auto& cls : classes) {
            pq.push({cls[0], cls[1]});
        }
        
        while (extraStudents--) {
            auto [pass, total] = pq.top();
            pq.pop();
            pq.push({pass + 1, total + 1});
        }
        
        double totalRatio = 0;
        
        while (!pq.empty()) {
            auto [pass, total] = pq.top();
            pq.pop();
            totalRatio += (double) pass / total;
        }
        
        return totalRatio / classes.size();
    }
};