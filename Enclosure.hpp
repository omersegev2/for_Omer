#ifndef _ENCLOSURE_H_
#define _ENCLOSURE_H_
#include "Animal.hpp"

class Enclosure
{
private:
    string id;
    int num_of_animals;
    void *zoo_keeper;
    Animal *animals;

public:
    Enclosure(string id = "none", int num = 0, void *zk = nullptr, Animal *animals = nullptr) : id(id), num_of_animals(num), zoo_keeper(zk), animals(animals){};
    ~Enclosure();
    void AddAnimal(Animal animal);
    void RemoveAnimal(Animal animal);
    Animal *GetAnimals() { return this->animals; }
    void SetZooKeeper(void *zooKeeper);
    string GetID() { return this->id; }
    void Set_Id(string id) { this->id = id; }
    void displayAnimals() const;
    int GetNumOfAnimals() { return num_of_animals; }
};

#endif