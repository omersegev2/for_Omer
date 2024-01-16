#ifndef _Z00_H_
#define _Z00_H_
#include "Enclosure.hpp"
#include "ZooKeeper.hpp"

class Zoo
{
private:
    int num_of_enclosure;
    int num_of_zookeeper;
    Enclosure* enclosures;
    ZooKeeper* zookeepers;
public:
    Zoo(int num_of_enclosure = 0,int num_of_zookeeper = 0, Enclosure* E = nullptr, ZooKeeper* ZK = nullptr):
    num_of_enclosure(num_of_enclosure),num_of_zookeeper(num_of_zookeeper), enclosures(E), zookeepers(ZK){};
    ~Zoo();
    void AddAnimal(string name, string species, int age);
    void AddAnimal(Animal animal,string id_enclosure);
    void AddEnclosure(string id_enclosure);
    void RemoveAnimal(string name_animal, string id_enclosure);
    void RemoveAnimal(Animal animal,string id_enclosure);
    void RemoveEnclosure(Enclosure enclosure);
    void DisplayAnimals()const;
    void assigned_Zoo_keeper(string name_zookeeper,string id_enclosure);
    Animal* FindAnimal(string name,string species);

};
#endif