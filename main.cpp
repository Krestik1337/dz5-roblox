
#include <iostream>
#include <string>

using namespace std;

class Bike {
protected:
    string* name;
    int* speeds;
    double* wheel;
    bool* brake;

public:
    Bike() {
        cout << "[Bike] конструктор без параметров" << endl;
        name = new string("NoName");
        speeds = new int(1);
        wheel = new double(26.0);
        brake = new bool(false);
    }

    Bike(string n, int s, double w, bool b) {
        cout << "[Bike] конструктор с параметрами" << endl;
        name = new string(n);
        speeds = new int(s);
        wheel = new double(w);
        brake = new bool(b);
    }

    virtual ~Bike() {
        cout << "[Bike] деструктор" << endl;
        delete name;
        delete speeds;
        delete wheel;
        delete brake;
    }

    string getName() { return *name; }
    int getSpeeds() { return *speeds; }
    double getWheel() { return *wheel; }
    bool getBrake() { return *brake; }

    virtual void ride() {
        cout << "Едем на " << *name << ", скоростей: " << *speeds << endl;
    }
};

class MountainBike : public Bike {
private:
    bool* suspension;

public:
    MountainBike() : Bike() {
        cout << "[MountainBike] конструктор" << endl;
        suspension = new bool(false);
    }

    MountainBike(string n, int s, double w, bool b, bool susp)
        : Bike(n, s, w, b) {
        cout << "[MountainBike] конструктор с параметрами" << endl;
        suspension = new bool(susp);
    }

    ~MountainBike() override {
        cout << "[MountainBike] деструктор" << endl;
        delete suspension;
    }

    bool getSuspension() { return *suspension; }

    void ride() override {
        cout << "Горный велосипед " << *name
            << ", амортизация: " << (*suspension ? "есть" : "нет") << endl;
    }
};

class CityBike : public Bike {
private:
    bool* basket;

public:
    CityBike() : Bike() {
        cout << "[CityBike] конструктор" << endl;
        basket = new bool(false);
    }

    CityBike(string n, int s, double w, bool b, bool bas)
        : Bike(n, s, w, b) {
        cout << "[CityBike] конструктор с параметрами" << endl;
        basket = new bool(bas);
    }

    ~CityBike() override {
        cout << "[CityBike] деструктор" << endl;
        delete basket;
    }

    bool getBasket() { return *basket; }

    void ride() override {
        cout << "Городской велосипед " << *name
            << ", корзина: " << (*basket ? "есть" : "нет") << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Обычный велосипед:" << endl;
    Bike* b = new Bike("Forward", 18, 27.5, false);
    b->ride();
    delete b;

    cout << endl;
    cout << "Горный велосипед:" << endl;
    MountainBike* m = new MountainBike("Trek", 21, 29.0, false, true);
    m->ride();
    delete m;

    cout << endl;
    cout << "Городской велосипед:" << endl;
    CityBike* c = new CityBike("Aist", 7, 28.0, false, true);
    c->ride();
    delete c;

    cout << endl;
    cout << "Выберите велосипед (1-Bike, 2-MountainBike, 3-CityBike): ";
    int choice;
    cin >> choice;

    Bike* userBike = nullptr;

    if (choice == 1) {
        userBike = new Bike("UserBike", 10, 26.0, false);
    }
    else if (choice == 2) {
        userBike = new MountainBike("UserMountain", 21, 29.0, false, true);
    }
    else if (choice == 3) {
        userBike = new CityBike("UserCity", 7, 28.0, false, true);
    }
    else {
        cout << "Неверный выбор" << endl;
        userBike = new Bike();
    }

    userBike->ride();

    delete userBike;

    cout << endl;
    cout << "Раннее связывание:" << endl;

    Bike staticBike("StaticBike", 6, 26.0, false);
    MountainBike staticMountain("StaticMountain", 18, 29.0, false, true);
    CityBike staticCity("StaticCity", 3, 28.0, true, true);

    staticBike.ride();
    staticMountain.ride();
    staticCity.ride();

    return 0;
}
