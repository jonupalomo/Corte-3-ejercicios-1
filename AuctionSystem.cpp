#include <unordered_map>
#include <set>

using namespace std; 
class AuctionSystem {
private:
    unordered_map<int, unordered_map<int, int>> bids;

    unordered_map<int, set<pair<int, int>>> orderedBids;

public:
    AuctionSystem() {
    }

    void addBid(int userId, int itemId, int bidAmount) {
        auto it = bids[itemId].find(userId);

        if (it != bids[itemId].end()) {
            orderedBids[itemId].erase({it->second, userId});
        }

        bids[itemId][userId] = bidAmount;
        orderedBids[itemId].insert({bidAmount, userId});
    }

    void updateBid(int userId, int itemId, int newAmount) {
        int oldAmount = bids[itemId][userId];

        orderedBids[itemId].erase({oldAmount, userId});

        bids[itemId][userId] = newAmount;
        orderedBids[itemId].insert({newAmount, userId});
    }

    void removeBid(int userId, int itemId) {
        int amount = bids[itemId][userId];

        orderedBids[itemId].erase({amount, userId});
        bids[itemId].erase(userId);

        if (bids[itemId].empty()) {
            bids.erase(itemId);
            orderedBids.erase(itemId);
        }
    }

    int getHighestBidder(int itemId) {
        auto it = orderedBids.find(itemId);

        if (it == orderedBids.end() || it->second.empty()) {
            return -1;
        }

        return it->second.rbegin()->second;
    }
};