class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<int> result;
        queue<int> q;

        for (const auto& prereq : prerequisites) {
            adjList[prereq[1]].push_back(prereq[0]);
            inDegree[prereq[0]]++;
        }

        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            result.push_back(course);

            for (int neighbor : adjList[course]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (result.size() == numCourses) {
            return result;
        } else {
            return {};
        }
    }
};