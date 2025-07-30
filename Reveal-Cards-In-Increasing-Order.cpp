class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end()); // sort in increasing order

        queue<int> indexQueue;
        // Step 1: Fill queue with indices
        for (int i = 0; i < n; ++i)
            indexQueue.push(i);

        vector<int> res(n);
        // Step 2: Simulate the revealing process in reverse
        for (int i = 0; i < n; ++i) {
            int pos = indexQueue.front();
            indexQueue.pop();
            res[pos] = deck[i];

            if (!indexQueue.empty()) {
                // move the next index to the back of queue
                indexQueue.push(indexQueue.front());
                indexQueue.pop();
            }
        }

        return res;
    }
};