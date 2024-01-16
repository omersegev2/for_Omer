#include "Zoo.hpp"

void menu();
int main()
{
    Zoo *the_zoo = new Zoo();
    int choice = 999;
    while (choice != 0)
    {
        menu();
        cin >> choice;
        switch (choice)
        {
        case 0:
            delete the_zoo;
            exit(0);
            break;
        case 1:{
            string name,species;
            int age;
            cout<<"PLease Enter the name of the Animal you want to add: ";
            cin>>name;
            cout<<"Please Enter the species of the Animal you want to add: ";
            cin>>species;
            cout<<"Please Enter the age of the Animal you want to add: ";
            cin>>age;
            //the_zoo->AddAnimal(the_zoo->CreateAnimal(name,species,age),species);
            the_zoo->AddAnimal(name,species,age);
        }
            
            break;
        case 2:{
            string Enclosure_id,name_animal;
            cout<< "Please enter the name of the enclosure you want do delete: "<<endl;
            cin>>Enclosure_id;
            cout<<"Please enter the name of the animal you want to delete: "<<endl;
            cin>>name_animal;
            the_zoo->RemoveAnimal(name_animal,Enclosure_id);
        }
            break;
        case 3:
            the_zoo->DisplayAnimals();
            break;
        case 4:{
            string id_enclosure,name_zoo_keeper;
            cout<<"Please enter the id_enclosure: ";
            cin>>id_enclosure;
            cout<<"Please enter the name zookeeper: ";
            cin>>name_zoo_keeper;
            the_zoo->assigned_Zoo_keeper(name_zoo_keeper,id_enclosure);
        }
            break;
        default:
            cout << "Invalid choice, please try again " << endl;
            cout << "********************************" << endl;
            menu();
            cin >> choice;
            break;
        }
    }
}
void menu()
{
    cout << endl;
    cout << "Hello :) " << endl;
    cout << "Welcome to the Zoo:" << endl;
    cout << "*************************************" << endl;
    cout << "Menu options: " << endl;
    cout << "0. Exit" << endl;
    cout << "1. Add Animal to the zoo" << endl;
    cout << "2. Remove Animal from the zoo" << endl;
    cout << "3. display all the Animals" << endl;
    cout << "4. Allocation of Zoo keeper to the enclosure" << endl;
    cout << "Please enter your choice: ";
}
