#include <unordered_map>
#include <string>

using namespace std;

class UndergroundSystem {
private:
    // id -> {startStation, startTime}
    unordered_map<int, pair<string, int>> check_in_map;
    
    // "startStation->endStation" -> {totalTime, totalTrips}
    unordered_map<string, pair<double, int>> travel_map;

public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        check_in_map[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = check_in_map[id];
        check_in_map.erase(id); // Limpiamos el registro activo
        
        int duration = t - startTime;
        string routeKey = startStation + "->" + stationName;
        
        travel_map[routeKey].first += duration;
        travel_map[routeKey].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeKey = startStation + "->" + endStation;
        auto& [totalTime, totalTrips] = travel_map[routeKey];
        return totalTime / totalTrips;
    }
};
