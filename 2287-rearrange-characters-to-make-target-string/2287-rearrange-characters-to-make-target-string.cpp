class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> sMap;
        unordered_map<char, int> tActual;
        unordered_set<char> tUnique;
        for (auto x : target) {
            sMap[x] = 0;
            tUnique.insert(x);

            if (tUnique.contains(x))
                tActual[x]++;
            else
                tActual[x] = 0;
        }

        for (auto x : s)
            if (tUnique.contains(x))
                sMap[x]++;

        vector<int> count;
        for (auto x : tUnique)
            count.push_back((int)sMap[x] / tActual[x]);

        int ans = s.size();
        for (auto x : count)
            ans = min(x, ans);
        return ans;
    }
};