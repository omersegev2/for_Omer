#include "Zoo.hpp"

// Destructor:
Zoo::~Zoo()
{
    if (this->enclosures != nullptr)
        delete[] this->enclosures;
    if (this->zookeepers != nullptr)
        delete[] this->zookeepers;
    // delete[] this->enclosures;
    // delete[] this->zookeepers;
}

/********************************************************************************
the method AddAnimal expect the name of the animal,it's species and age.

it will create a new object of animal and check for memory leak .

then call the method AddAnimal with the new animal object as a parameter.
*********************************************************************************/

void Zoo::AddAnimal(string name, string species, int age)
{
    Animal new_animal(name, species, age);
    cout << "New Animal Create" << endl;
    this->AddAnimal(new_animal, species);
}

/********************************************************************************
the method AddAnimal expect a animal object and the id of the enclosure that the
animal is associated with.

it will search the enclosure to see if a enclosure object already exist
with the same id .

if it does then return the animal.
otherwise, create a enclosure from the provided information and add the animal
object to the enclosure

*********************************************************************************/

void Zoo::AddAnimal(Animal animal, string id_enclosure)
{

    for (int i = 0; i < num_of_enclosure; i++)
    {
        if (enclosures[i].GetID() == id_enclosure)
        {
            this->enclosures[i].AddAnimal(animal);
            return;
        }
    }
    this->AddEnclosure(id_enclosure);
    this->AddAnimal(animal, id_enclosure);
}

/********************************************************************************
the method AddEnclosure expect the id of the enclosure.

it will create a new object of enclosure and check for memory leak .

*********************************************************************************/

void Zoo::AddEnclosure(string id_enclosure)
{
    ++(this->num_of_enclosure);
    Enclosure *temp = new Enclosure[this->num_of_enclosure];

    if (temp == NULL)
    {
        cout << "Memory Allocation failed" << endl;
        --(this->num_of_enclosure);
        return;
    }

    for (int i = 0; i < this->num_of_enclosure - 1; i++)
    {
        temp[i] = this->enclosures[i];
    }

    temp[this->num_of_enclosure - 1].Set_Id(id_enclosure);

    if (num_of_enclosure > 1 && this->enclosures != nullptr)
        delete[] this->enclosures;

    this->enclosures = temp;
}

/********************************************************************************
the method RemoveAnimal expect the animal object and the id of the enclosure that
the animal is associated with.

it will search the animal with the animal name the method receive,then
it will search the enclosure with the id the method receive.

if it does then call the method RemoveAnimal(animal).
In addition,it will check the number of animals in the current enclosure,
if the number is zero than call the method remove enclosure and delete the
current enclosure.
*********************************************************************************/

void Zoo::RemoveAnimal(Animal animal, string id_enclosure)
{

    if (animal.GetName() == "none")
    {
        cout << "This Animal doesn't exist" << endl;
        return;
    }
    for (int i = 0; i < num_of_enclosure; i++)
    {
        if (enclosures[i].GetID() == id_enclosure)
        {
            this->enclosures[i].RemoveAnimal(animal);
            if (enclosures[i].GetNumOfAnimals() == 0)
            {
                RemoveEnclosure(enclosures[i]);
            }
        }
    }
}

/********************************************************************************
the method remove animal expect the name of the animal and the id of the
enclosure the animal assigned to.

it will call the other RemoveAnimal method and send the function FindAnimal with
the same parameters and the id of the enclosure.

*********************************************************************************/

void Zoo::RemoveAnimal(string name_animal, string id_enclosure)
{
    Animal *animal = this->FindAnimal(name_animal, id_enclosure);
    if (animal)
    {
        this->RemoveAnimal(*animal, id_enclosure);
    }
    else
    {
        cout << "animal not found..." << endl;
    }
}

/********************************************************************************
the method display

display all animal object in the enclosures array.
for each enclosure call the DisplayDetails method so the animal object display itself.

*********************************************************************************/

void Zoo::DisplayAnimals() const
{
    for (int i = 0; i < num_of_enclosure; i++)
    {
        cout << "Enclosure: " << enclosures[i].GetID() << endl;
        cout << "************************************" << endl;
        this->enclosures[i].displayAnimals();
    }
}

/********************************************************************************
the method assigned_Zoo_keeper expect the name of the zoo keeper and the id
of the enclosure he assigned to.

it will search the enclosure by his id.

it it does,the method will check if the Zoo keeper exist, if it does the method
assigned the current zoo keeper to the current enclosure .
if it doesn't exist, the method create a new object of zoo keeper and than
assigned the new zoo keeper to the current enclosure.

*********************************************************************************/

void Zoo::assigned_Zoo_keeper(string name_zookeeper, string id_enclosure)
{
    int enclosure_index = 0;
    for (enclosure_index = 0; enclosure_index < num_of_enclosure; enclosure_index++)
    {
        if (enclosures[enclosure_index].GetID() == id_enclosure)
        {
            break;
        }
        if (enclosure_index == num_of_enclosure - 1)
        {
            cout << "this enclosure doesn't exist" << endl;
            return;
        }
    }

    for (int i = 0; i < num_of_zookeeper; i++)
    {
        if (this->zookeepers[i].GetName() == name_zookeeper)
        {
            this->zookeepers[i].assigned_to_enclosures(enclosures[enclosure_index]);
            enclosures[enclosure_index].SetZooKeeper(&zookeepers[i]);
            cout << "ZooKeeper Assigned to enclosure" << endl;
            return;
        }
    }

    ZooKeeper zooKeeper(name_zookeeper);
    ++(this->num_of_zookeeper);
    ZooKeeper *temp = new ZooKeeper[this->num_of_zookeeper];
    if (temp != NULL)
    {
        for (int i = 0; i < this->num_of_zookeeper - 1; i++)
        {
            temp[i] = this->zookeepers[i];
        }
        temp[num_of_zookeeper - 1] = zooKeeper;
        if (num_of_zookeeper > 1 && this->zookeepers != nullptr)
        {
            delete[] this->zookeepers;
        }
        this->zookeepers = temp;
    }
    else
    {
        cout << "Memory Allocation failed" << endl;
        --(this->num_of_zookeeper);
    }
    this->num_of_zookeeper++;
    cout << "New zoo keeper Create" << endl;

    zooKeeper.assigned_to_enclosures(enclosures[enclosure_index]);
    enclosures[enclosure_index].SetZooKeeper(&zooKeeper);
    cout << "ZooKeeper Assigned to enclosure" << endl;
}

/********************************************************************************
the method Enclosure expect the enclosure object.

it will search the enclosure with the enclosure id.

if it does then delete the current enclosure
*********************************************************************************/

void Zoo::RemoveEnclosure(Enclosure enclosure)
{
    --(this->num_of_enclosure);
    Enclosure *temp = new Enclosure[num_of_enclosure];
    if (temp == NULL)
    {
        cout << "Memory Allocation failed" << endl;
        ++(this->num_of_enclosure);
    }
    for (int i = 0; i < num_of_enclosure + 1; i++)
    {
        if (enclosure.GetID() != this->enclosures[i].GetID())
        {
            temp[i] = this->enclosures[i];
        }
        else
        {
            cout << "This Enclosure doesn't exist " << endl;
        }
    }

    if (num_of_enclosure > 0 && this->enclosures != nullptr)
        delete[] this->enclosures;

    this->enclosures = temp;
}

/********************************************************************************
the method FindAnimal expect the animal name and the animal species.

it will search the enclosure with the species the method receive
(enclosure id = species).

if it does then search the animal with the method GetName.
then return animal object.
*********************************************************************************/

Animal *Zoo::FindAnimal(string name, string species)
{
    for (int i = 0; i < num_of_enclosure; i++)
    {
        if (enclosures[i].GetID() == species)
        {
            Animal *animals = enclosures[i].GetAnimals();
            for (int j = 0; j < enclosures[i].GetNumOfAnimals(); j++)
            {
                if (animals[j].GetName() == name)
                {
                    return &animals[j];
                }
            }
        }
    }
    return nullptr;
}
