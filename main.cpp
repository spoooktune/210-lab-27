#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main_menu(){
    int option = 0;
    while (option != 1 && option != 2 && option != 3 && option != 4){
        cout << "1. Increase Friendship" << endl;
        cout << "2. Decrease Friendship" << endl;
        cout << "3. Search For Villager" << endl;
        cout << "4. Exit" << endl << endl;
        cout << "Choose an option: ";
        cin >> option;
    }
    return option;
}

int main() {
    // declarations
    // key: villager name, data: friendship level, species, catchprase
    map<string, tuple<int, string, string>> villagers;
    villagers["Apollo"] = {7, "Eagle", "pah"};
    villagers["Carmen"] = {10, "Rabbit", "nougat"};
    villagers.insert({"Fang", {5, "Wolf", "cha-chomp"}});

    int option = main_menu();
    while (option != 4){
        switch (option){
            case 1:
                for (auto& pair : villagers){
                    auto& tup = pair.second;
                    get<0>(tup)++;
                    if (get<0>(tup) > 10)
                        get<0>(tup) = 10;
                }
                break;
            case 2:
                for (auto& pair : villagers){
                    auto& tup = pair.second;
                    get<0>(tup)--;
                    if (get<0>(tup) < 1)
                        get<0>(tup) = 1;
                }
                break;
            case 3:
                string name;
                cout << "Enter villager name: ";
                cin >> name;
                auto it = villagers.find(name);
                if (it != villagers.end()) {  
                    cout << name << "'s data" << endl;
                    auto [friendship, species, catchphrase] = it->second;
                    cout << "> Friendship Level: " << friendship << endl;
                    cout << "> Species: " << species << endl;
                    cout << "> Catchphrase: " << catchphrase << endl;
                } 
                else
                    cout << endl << name << " not found." << endl;
                cout << endl;
                break;
        }
        cout << "Villager Data: " << endl;
        for (auto pair : villagers) {
            cout << pair.first << " [";
            cout << get<0>(pair.second) << ", " << get<1>(pair.second) << ", " << get<2>(pair.second) << "]" << endl;
        }
        cout << endl;
        option = main_menu();
    }
    /*
    // access the map using a range-based for loop
    cout << "Villager Data (range-based for loop):" << endl;
    for (auto pair : villagers) {
        cout << pair.first << " [";
        auto [friendship, species, catchphrase] = it->second;
        cout << "[" << friendship << ", " << species << ", " << catchphrase << "]" << endl;
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
    

    // report size, clear, report size again to confirm map operations
    cout << "Size before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;
    */
    return 0;
}
