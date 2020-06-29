#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
    void dfs(unordered_map<string, multiset<string>> &from_to_map, string location, vector<string> &current_itinerary,
             vector<string> &final_itinerary, int stations) {
        current_itinerary.push_back(location);
        if (from_to_map[location].size() == 0) {
            if (current_itinerary.size() == stations) {
                final_itinerary = current_itinerary;
            }
            current_itinerary.erase(--current_itinerary.end());
            return;
        }

        vector<string> dests(from_to_map[location].begin(), from_to_map[location].end());

        for (int i = 0; i < dests.size(); ++i) {
            auto new_location = dests[i];
            auto it = from_to_map[location].begin();
            for (int t = i; t > 0; t--) {
                ++it;
            }
            from_to_map[location].erase(it);

            dfs(from_to_map, new_location, current_itinerary, final_itinerary, stations);

            if (final_itinerary.size() > 0) {
                return;
            }

            from_to_map[location].insert(new_location);
        }
        current_itinerary.erase(--current_itinerary.end());
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        // Todo: [可以提升的点] multiset是插入时排序的，这个题可以全部插入再排序，这样时间复杂度会小一些
        unordered_map<string, multiset<string>> from_to_map;

        for (auto &ticket : tickets) {
            auto &from = ticket[0];
            auto &to = ticket[1];

            from_to_map[from].insert(to);
        }
        int stations = tickets.size() + 1;
        vector<string> current_itinerary;
        vector<string> final_itinerary;
        dfs(from_to_map, "JFK", current_itinerary, final_itinerary, stations);
        return final_itinerary;
    }
};


int main() {
    Solution solution;

//    vector<vector<string>> tickets {
//            {"MUC", "LHR"},
//            {"JFK", "MUC"},
//            {"SFO", "SJC"},
//            {"LHR", "SFO"}
//    };

//    vector<vector<string>> tickets {
//            {"JFK", "KUL"},
//            {"JFK", "NRT"},
//            {"NRT", "JFK"}
//    };

    vector<vector<string>> tickets{
            {"EZE", "AXA"},
            {"TIA", "ANU"},
            {"ANU", "JFK"},
            {"JFK", "ANU"},
            {"ANU", "EZE"},
            {"TIA", "ANU"},
            {"AXA", "TIA"},
            {"TIA", "JFK"},
            {"ANU", "TIA"},
            {"JFK", "TIA"}
    };


    auto ans = solution.findItinerary(tickets);

    return 0;
}