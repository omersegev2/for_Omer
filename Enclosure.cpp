#include "Enclosure.hpp"

// Destructor:
Enclosure::~Enclosure()
{
    if(this->animals != nullptr) delete[] this->animals;
}

/********************************************************************************
the method AddAnimal expect a animal object.

it will add the animal to the animals array.

*********************************************************************************/
void Enclosure::AddAnimal(Animal animal)
{
    ++(this->num_of_animals);
    Animal *temp = new Animal[num_of_animals];
    if (temp == NULL)
    {
        cout << "Memory Allocation failed" << endl;
        --(this->num_of_animals);
        return;
    }
    for (int i = 0; i < num_of_animals - 1; i++)
    {
        temp[i] = this->animals[i];
    }
    temp[num_of_animals - 1] = animal;

    if (this->animals != nullptr) delete[] this->animals;
    
    this->animals = temp;

    cout << "the Animal: " << animal.GetName() << " Added Successfully to the: '" << this->id << "' enclosure." << endl;
}

/********************************************************************************
the method RemoveAnimal expect the animal object.

it will search the animal with the animal name.

if it does then delete the current animal.
*********************************************************************************/

void Enclosure::RemoveAnimal(Animal animal)
{
    int j = 0;
    --(this->num_of_animals);
    Animal *temp = new Animal[num_of_animals];
    if (temp == NULL)
    {
        cout << "Memory Allocation failed" << endl;
        ++(this->num_of_animals);
        return;
    }
    for (int i = 0; i < num_of_animals + 1; i++)
    {
        if (animal.GetName() != this->animals[i].GetName())
        {
            temp[j] = this->animals[i];
            j++;
        }
    }
    // cout<< "This Animal doesn't exist "<<endl;
    if (num_of_animals > 0 && this->animals != nullptr) delete[] this->animals;

    this->animals = temp;

    cout << "The animal: " << animal.GetName() << " remove successfully" << endl;
}

/********************************************************************************
the method SetZooKeeper expect the Zoo Keeper object

it will set the Zoo Keeper to the current enclosure.
*********************************************************************************/

void Enclosure::SetZooKeeper(void *zooKeeper)
{
    this->zoo_keeper = zooKeeper;
}

/********************************************************************************
the method displayAnimals

display all animal object in the animals array.
for each animal call the DisplayDetails method in the animal object .
*********************************************************************************/

void Enclosure::displayAnimals() const
{
    for (int i = 0; i < num_of_animals; i++)
    {
        animals[i].desplayDetails();
    }
}