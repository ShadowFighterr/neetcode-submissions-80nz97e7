class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        set<char> s;
        for(char task : tasks){
            s.insert(task);
            freq[task-'A']++;
        }
        vector<int> vec;
        for(int val : freq){
            vec.push_back(val);}
        sort(vec.rbegin(), vec.rend());
        int max_freq = vec[0];
        int count_max = 0;
        for (int f : vec) {
            if (f == max_freq) count_max++;
        }
        int part_count = max_freq - 1;
        int part_length = n - (count_max - 1);
        int empty_slots = part_count * part_length;
        int available_tasks = tasks.size() - (max_freq * count_max);
        int idles = max(0, empty_slots - available_tasks);

        return tasks.size() + idles;
        }
};
