// ther are some realojebst whcih are highlty dependnet on each oter  forex
// books  chapters,  house rooms etc

// i one is dextroude another have not independ usecases

#include<bits/stdc++.h>
using namespace std;

class Room {
private:
    std::string name;

public:
    Room(string name): name(move(name)) {}

    const string& getName() const {
        return name;
    }
};
class House {
private:
    std::vector<Room> rooms;

public:
    void addRoom( string & roomName) {
        rooms.emplace_back(roomName);
    }

    void showRooms() const {
        for (const auto& room : rooms) {
            cout << room.getName() << '\n';
        }
    }
};
int main() {

    House house;

    house.addRoom("Bedroom");
    house.addRoom("Kitchen");
    house.addRoom("Hall");

    house.showRooms();

}