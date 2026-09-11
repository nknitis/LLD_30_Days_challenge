#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

enum class VehicleType { BIKE, CAR, TRUCK };
enum class SpotType { BIKE, CAR, TRUCK };

class Vehicle {
private:
    string vehicleNumber;
    VehicleType type;

public:
    Vehicle(string number, VehicleType type) : vehicleNumber(number), type(type) {}

    string getVehicleNumber() const { return vehicleNumber; }
    VehicleType getType() const { return type; }
};

class ParkingSpot {
private:
    int spotNumber;
    SpotType spotType;
    bool occupied;
    string vehicleNumber;

public:
    ParkingSpot(int number, SpotType type)
        : spotNumber(number), spotType(type), occupied(false) {}

    bool canPark(VehicleType type) const {
        if (occupied) return false;

        if (type == VehicleType::BIKE && spotType == SpotType::BIKE) return true;
        if (type == VehicleType::CAR && spotType == SpotType::CAR) return true;
        if (type == VehicleType::TRUCK && spotType == SpotType::TRUCK) return true;

        return false;
    }

    void parkVehicle(const string& number) {
        vehicleNumber = number;
        occupied = true;
    }

    void removeVehicle() {
        vehicleNumber.clear();
        occupied = false;
    }

    bool isOccupied() const { return occupied; }
    int getSpotNumber() const { return spotNumber; }
    string getVehicleNumber() const { return vehicleNumber; }
};

class Floor {
private:
    int floorNumber;
    vector<ParkingSpot> spots;

public:
    Floor(int number) : floorNumber(number) {}

    void addSpot(const ParkingSpot& spot) {
        spots.push_back(spot);
    }

    ParkingSpot* findAvailableSpot(VehicleType type) {
        for (auto& spot : spots) {
            if (spot.canPark(type)) return &spot;
        }
        return nullptr;
    }

    ParkingSpot* findSpot(int spotNumber) {
        for (auto& spot : spots) {
            if (spot.getSpotNumber() == spotNumber) return &spot;
        }
        return nullptr;
    }

    int getFloorNumber() const { return floorNumber; }
};

class ParkingLot {
private:
    vector<Floor> floors;

public:
    void addFloor(const Floor& floor) {
        floors.push_back(floor);
    }

    ParkingSpot* findParkingSpot(VehicleType type) {
        for (auto& floor : floors) {
            ParkingSpot* spot = floor.findAvailableSpot(type);
            if (spot != nullptr) return spot;
        }
        return nullptr;
    }

    ParkingSpot* findSpot(int spotNumber) {
        for (auto& floor : floors) {
            ParkingSpot* spot = floor.findSpot(spotNumber);
            if (spot != nullptr) return spot;
        }
        return nullptr;
    }
};

class ParkingTransaction {
private:
    string vehicleNumber;
    int spotNumber;
    time_t entryTime;
    time_t exitTime;
    double amount;

public:
    ParkingTransaction(const string& vehicle, int spot)
        : vehicleNumber(vehicle), spotNumber(spot),
          entryTime(time(nullptr)), exitTime(0), amount(0) {}

    void exitParking() { exitTime = time(nullptr); }
    void setAmount(double price) { amount = price; }

    string getVehicleNumber() const { return vehicleNumber; }
    int getSpotNumber() const { return spotNumber; }
    double getAmount() const { return amount; }
};

class PricingStrategy {
public:
    virtual double calculatePrice(VehicleType type, int hours) = 0;
    virtual ~PricingStrategy() {}
};

class NormalPricingStrategy : public PricingStrategy {
public:
    double calculatePrice(VehicleType type, int hours) override {
        double pricePerHour = 0;

        if (type == VehicleType::BIKE) pricePerHour = 20;
        else if (type == VehicleType::CAR) pricePerHour = 40;
        else if (type == VehicleType::TRUCK) pricePerHour = 60;

        return pricePerHour * hours;
    }
};

class PaymentStrategy {
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentStrategy() {}
};

class CashPayment : public PaymentStrategy {
public:
    void pay(double amount) override {
        cout << "Paid Rs. " << amount << " using Cash.\n";
    }
};

class UPIPayment : public PaymentStrategy {
public:
    void pay(double amount) override {
        cout << "Paid Rs. " << amount << " using UPI.\n";
    }
};

class ParkingManager {
private:
    ParkingLot* parkingLot;
    PricingStrategy* pricingStrategy;
    PaymentStrategy* paymentStrategy;

public:
    ParkingManager(ParkingLot* lot,
                   PricingStrategy* pricing,
                   PaymentStrategy* payment)
        : parkingLot(lot),
          pricingStrategy(pricing),
          paymentStrategy(payment) {}

    ParkingTransaction* parkVehicle(const Vehicle& vehicle) {
        ParkingSpot* spot = parkingLot->findParkingSpot(vehicle.getType());

        if (spot == nullptr) {
            cout << "No parking spot available.\n";
            return nullptr;
        }

        spot->parkVehicle(vehicle.getVehicleNumber());

        cout << "Vehicle parked successfully.\n";
        cout << "Vehicle: " << vehicle.getVehicleNumber() << "\n";
        cout << "Spot Number: " << spot->getSpotNumber() << "\n";

        return new ParkingTransaction(
            vehicle.getVehicleNumber(),
            spot->getSpotNumber()
        );
    }

    void exitVehicle(ParkingTransaction* transaction,
                     VehicleType vehicleType,
                     int hours) {
        if (transaction == nullptr) return;

        ParkingSpot* spot = parkingLot->findSpot(transaction->getSpotNumber());

        if (spot == nullptr) {
            cout << "Parking spot not found.\n";
            return;
        }

        transaction->exitParking();

        double amount = pricingStrategy->calculatePrice(vehicleType, hours);
        transaction->setAmount(amount);

        spot->removeVehicle();
        paymentStrategy->pay(amount);

        cout << "Vehicle exited successfully.\n";
        cout << "Vehicle: " << transaction->getVehicleNumber() << "\n";
        cout << "Spot Number: " << transaction->getSpotNumber() << "\n";
        cout << "Total Amount: Rs. " << transaction->getAmount() << "\n";
    }
};

int main() {
    ParkingLot parkingLot;

    Floor floor1(1);

    floor1.addSpot(ParkingSpot(1, SpotType::BIKE));
    floor1.addSpot(ParkingSpot(2, SpotType::CAR));
    floor1.addSpot(ParkingSpot(3, SpotType::CAR));
    floor1.addSpot(ParkingSpot(4, SpotType::TRUCK));

    parkingLot.addFloor(floor1);

    NormalPricingStrategy pricingStrategy;
    UPIPayment paymentStrategy;

    ParkingManager manager(
        &parkingLot,
        &pricingStrategy,
        &paymentStrategy
    );

    Vehicle car("DL01AB1234", VehicleType::CAR);

    ParkingTransaction* transaction = manager.parkVehicle(car);

    if (transaction != nullptr) {
        cout << "\n--- EXIT ---\n";
        manager.exitVehicle(transaction, car.getType(), 3);
        delete transaction;
    }

    return 0;
}
