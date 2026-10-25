#include <vector>
#include <algorithm>

using namespace std;
class ATM {
private:
    vector<long long> banknotes;
    vector<int> values = {20, 50, 100, 200, 500};

public:
    ATM() {
        banknotes = vector<long long>(5, 0);
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) {
            banknotes[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> used(5, 0);

        for (int i = 4; i >= 0; i--) {
            long long take = min(
                (long long)amount / values[i],
                banknotes[i]
            );

            used[i] = (int)take;
            amount -= (int)(take * values[i]);
        }

        if (amount != 0) {
            return {-1};
        }

        for (int i = 0; i < 5; i++) {
            banknotes[i] -= used[i];
        }

        return used;
    }
};