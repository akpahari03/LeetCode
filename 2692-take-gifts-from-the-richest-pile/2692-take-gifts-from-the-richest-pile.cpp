class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(),gifts.end());
        long long sum = 0;
        for(int &gift : gifts) {
            sum += gift;
        }
        while(k--) {
            int maxEl = pq.top();
            pq.pop();

            int remaining = sqrt(maxEl);
            sum -= (maxEl - remaining);
            pq.push(remaining);
        }
        return sum;
    }
};