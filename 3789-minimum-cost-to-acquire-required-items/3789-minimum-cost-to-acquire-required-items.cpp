class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long mine = min(need1, need2);
        long long ans = min(mine * costBoth, mine * (cost1 + cost2));
        long long maxe = max(need1, need2);
        return ans + min((maxe - mine) * costBoth, ((need1 - mine) * cost1) + ((need2 - mine) * cost2));
    }
};