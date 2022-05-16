#include <iostream>
#include <cstring>
using namespace std;

enum Weapon { Sword, Bow, Spear, ShieldSword, HeavyAxe, Dagger };

class gladiator {
    Weapon weapon;
    double power;
    double learningRate;
public:
    gladiator() {};
    gladiator(Weapon, double, double);
    void winAgainst(gladiator b);
    double getPow() const;
    Weapon getWeapon() const;
};
//Allocate for Glads 100 element array

class colosseum {
    int count;
    gladiator* Glads;
public:
    colosseum();
    ~colosseum();
    void addGlad(gladiator);
    void addGlad(gladiator* a, int n = 1);
    gladiator getGlad(int n) const;
    void startFight(int, int);
};

gladiator::gladiator()
{
    this->power = 0;
    this->learningRate = 0;
}

gladiator::gladiator(Weapon weapon, double power, double learningRate)
{
    this->power = power;
    this->learningRate = weapon;
    this->weapon = weapon;
}

void gladiator::winAgainst(gladiator b)
{
    if (power > b.power) {
        this->power = b.power * (this->learningRate);
    }
}

double gladiator::getPow() const
{
    return this->power;
}

Weapon gladiator::getWeapon() const
{
    return this->weapon;
}

colosseum::colosseum()
{
    Glads = new gladiator[100];
    count = 0;
}

colosseum::~colosseum()
{
    delete[] Glads;
}

void colosseum::addGlad(gladiator a)
{
    gladiator* arr = new gladiator[count + 1];
    for (int i = 0; i < count; i++)
    {
        arr[i] = Glads[i];
    }
    Glads[count] = a;
    delete[] Glads; Glads = arr;
}

void colosseum::addGlad(gladiator* a, int n = 1)
{
    gladiator* arr = new gladiator[count + n];
    for (int i = 0; i < count; i++)
    {
        arr[i] = Glads[i];
    }
    for (int i = 0; i < count; i++)
    {
        Glads[count] = a[i];
    }
    delete[] Glads; Glads = arr;
}

gladiator colosseum::getGlad(int n) const
{
    for (int i = 0; i < n; i++)
    {
        cout << Glads[i];
    }
}


int main(int argv, char* argc[])
{
    
}
