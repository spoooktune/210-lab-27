#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers;
    // key: villager name, data: friendship level, species, catchprase

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagers["Apollo"] = {7, "Eagle", "pah"};
    villagers["Carmen"] = {10, "Rabbit", "nougat"};
    villagers.insert({"Fang", {5, "Wolf", "cha-chomp"}});

    // access the map using a range-based for loop
    cout << "Villager Data (range-based for loop):" << endl;
    for (auto pair : villagers) {
        cout << pair.first << " [";
        cout << get<0>(pair.second) << ", " << get<1>(pair.second) << ", " << get<2>(pair.second) << "]" << endl;
    }
    cout << endl;

    // access the map using iterators
    
    cout << "Villager Data:" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagers.begin(); it != villagers.end(); ++it) {
        cout << it->first << ": ";
        auto [friendship, species, catchphrase] = it->second;
        cout << "[" << friendship << ", " << species << ", " << catchphrase << "]" << endl;
    }
    cout << endl;

    // delete an element
    villagers.erase("Carmen");
    cout << "Carmen deleted" << endl;

    // search for an element using .find() to avoid errors
    
    string searchKey = "Fang";
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s data" << endl;
        auto [friendship, species, catchphrase] = it->second;
        cout << "Friendship Level: " << friendship << endl;
        cout << "Species: " << species << endl;
        cout << "Catchphrase: " << catchphrase << endl;
    } else
        cout << endl << searchKey << " not found." << endl;
    cout << endl;

    // report size, clear, report size again to confirm map operations
    cout << "Size before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;

    return 0;
}
