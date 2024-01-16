#include "ZooKeeper.hpp"

// Destructor
ZooKeeper::~ZooKeeper()
{
    if(this->assigned_enclosures != nullptr) delete[] this->assigned_enclosures;
}

/********************************************************************************
the method assigned_to_enclosures expect object of enclosure.

it will assigned the current zoo keeper to the enclosure the method get.

*********************************************************************************/

void ZooKeeper::assigned_to_enclosures(Enclosure enclosure)
{
    ++(this->num_of_assigned_enclosure);
    Enclosure *temp = new Enclosure[num_of_assigned_enclosure];
    if (temp == NULL)
    {
        cout << "Memory Allocation failed" << endl;
        --(this->num_of_assigned_enclosure);
    }
    for (int i = 0; i < num_of_assigned_enclosure - 1; i++)
    {
        temp[i] = this->assigned_enclosures[i];
    }
    temp[num_of_assigned_enclosure - 1] = enclosure;
    if (num_of_assigned_enclosure > 1 && this->assigned_enclosures != nullptr)
        delete[] this->assigned_enclosures;
    this->assigned_enclosures = temp;
}
