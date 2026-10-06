#include <iostream>
using namespace std;

#define SIZE 10

class Parking
{
    int table[SIZE];

public:
    Parking()
    {
        for(int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    void parkVehicle(int vehicle)
    {
        int index = vehicle % SIZE;

        // Empty slot
        if(table[index] == -1)
        {
            table[index] = vehicle;
            cout << "Vehicle " << vehicle
                 << " parked at slot " << index << endl;
        }
        else
        {
            // Linear probing
            int i = (index + 1) % SIZE;

            while(i != index && table[i] != -1)
                i = (i + 1) % SIZE;

            if(i != index)
            {
                table[i] = vehicle;
                cout << "Vehicle " << vehicle
                     << " parked at slot " << i << endl;
            }
            else
                cout << "Parking Full!\n";
        }
    }

    void display()
    {
        cout << "\nParking Slots:\n";

        for(int i = 0; i < SIZE; i++)
        {
            cout << "Slot " << i << " : ";

            if(table[i] == -1)
                cout << "Empty";
            else
                cout << "Vehicle " << table[i];

            cout << endl;
        }
    }
};

int main()
{
    Parking p;
    int n, vehicle;

    cout << "Enter number of vehicles: ";
    cin >> n;

    cout << "Enter vehicle numbers:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> vehicle;
        p.parkVehicle(vehicle);
    }

    p.display();

    return 0;
}
