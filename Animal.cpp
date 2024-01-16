#include "Animal.hpp"

//destructor:
// Animal::~Animal(){}

/********************************************************************************
the method display

display all animal details: name, species, age.
for each enclosure call the DisplayDetails method so the animal object display itself.

*********************************************************************************/

void Animal::desplayDetails()const{
    cout<<"Animal details: "<<endl;
    cout<<"Name: "<<this->name<<endl;
    cout<<"Species: "<<this->species<<endl;
    cout<<"Age: "<<this->age<<endl;
    cout<<endl;
}

/********************************************************************************
the method SetAnimal expect the name of the animal,the species and the age.

it will update the attributes of an existing live object

*********************************************************************************/

void Animal::SetAnimal(string name,string species,int age){
    this->name = name;
    this->species = species;
    this->age = age;
}