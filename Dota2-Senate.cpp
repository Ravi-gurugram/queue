class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        int n = senate.size();

        // Step 1: Fill initial positions
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }

        // Step 2: Simulate rounds
        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front(); radiant.pop();
            int d = dire.front(); dire.pop();

            // Whoever has smaller index bans the other and re-enters queue at end
            if (r < d)
                radiant.push(r + n);
            else
                dire.push(d + n);
        }

        // Step 3: Declare Winner
        return radiant.empty() ? "Dire" : "Radiant";
    }
};