class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto &a, auto &b) {return a[1]<b[1];});
        priority_queue<int> maxHeap;
        int total_duration=0;
        for(vector<int> course: courses) {
            int duration = course[0], lastDay = course[1];
            total_duration+=duration;
            maxHeap.push(duration);
            if(total_duration>lastDay) {
                total_duration-=maxHeap.top();
                maxHeap.pop();
            }
        }
        return maxHeap.size();
    }
};