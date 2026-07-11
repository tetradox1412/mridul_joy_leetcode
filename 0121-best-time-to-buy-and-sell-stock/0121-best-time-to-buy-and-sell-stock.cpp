class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0, sell = 1;
        int max_profit = 0;

        while (sell < prices.size()) {
            if (prices[buy] < prices[sell]) {
                int curr_profit = prices[sell] - prices[buy];
                max_profit = max(max_profit, curr_profit);
            } else
                buy = sell;

            sell += 1;
        }

        return max_profit;
    }
};