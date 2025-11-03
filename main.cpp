#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main_menu(){
    int option = 0;
    while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6){
        cout << "1. Add Villager" << endl;
        cout << "2. Delete Villager" << endl;
        cout << "3. Increase Friendship" << endl;
        cout << "4. Decrease Friendship" << endl;
        cout << "5. Search For Villager" << endl;
        cout << "6. Exit" << endl << endl;
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
    string n, s, cp;
    int fl;
    while (option != 6){
        switch (option){
            case 1:
                cout << "Villager Name: ";
                cin >> n;
                cout << "Friendship Level: ";
                cin >> fl;
                cout << "Species: ";
                cin >> s;
                cout << "Catchphrase: ";
                cin >> cp;
                villagers.insert({n, {fl, s, cp}});
                cout << n << " added" << endl << endl;
                break;
            case 2:
                cout << "Choose villager to be deleted: ";
                cin >> n;
                villagers.erase(n);
                cout << n << " deleted" << endl << endl;
                break;
            case 3:
                for (auto& pair : villagers){
                    auto& tup = pair.second;
                    get<0>(tup)++;
                    if (get<0>(tup) > 10)
                        get<0>(tup) = 10;
                }
                break;
            case 4:
                for (auto& pair : villagers){
                    auto& tup = pair.second;
                    get<0>(tup)--;
                    if (get<0>(tup) < 1)
                        get<0>(tup) = 1;
                }
                break;
            case 5:
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

    return 0;
}
