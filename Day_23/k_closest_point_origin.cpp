class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int> > pq;
        for(int i=0;i<points.size();i++)
        {
            int xi=points[i][0];
            int yi=points[i][1];
        int dis= xi*xi+yi*yi;
        pq.push({dis,i});
        if(pq.size()>k)
        {
            pq.pop();
        }
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            pair<int,int> top=pq.top();
            pq.pop();
            int ind=top.second;
            ans.push_back(points[ind]);
        }
        return ans;
    }
};