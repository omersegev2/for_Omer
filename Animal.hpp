#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include <iostream>
#include <string>
using namespace std;

class Animal
{
private:
    string name;
    string species;
    int age;
public:
    Animal(string name = "none",string species = "none",int age = 0):
    name(name),species(species),age(age){}
    // ~Animal(){};
    string GetName(){return name;}
    void desplayDetails()const;
    void SetAnimal(string name,string species,int age);
};

#endif