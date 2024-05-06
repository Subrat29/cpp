#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Create an empty map to store the names of students as keys and their corresponding ages as values.
    unordered_map<string, int> mp;

    // Add three entries to the map from question 1: "Alice" with age 20, "Bob" with age
    mp["Alice"] = 20;
    mp["Bob"] = 22;
    mp["Charlie"] = 21;

    // Print the age of "Bob" from the map.
    cout << mp["Bob"] << endl;

    // Check if the map contains the key "Alice" and print the result.
    if (mp.count("Alice"))
        cout << "Alice is present in map" << endl;
    else
        cout << "Alice is absent in map" << endl;

    // Remove the entry for "Charlie" from the map.
    mp.erase("Charlie");
    cout << mp["Charlie"] << endl;

    // Check if the map is empty and print the result.
    if (mp.empty())
        cout << "map is empty";
    else
        cout << "map is not empty\n";

    for (auto &&i : mp)
    {
        cout << i.first << ": " << i.second << endl;
    }

    // Create another map to store employee IDs (as keys) and their
    // corresponding salaries (as values).
    unordered_map<int, int> employee;

    // Add two entries to the new map: ID 101 with salary 50000 and ID 102 with salary 60000.
    employee[101] = 50000;
    employee[102] = 60000;

    // Print the salary of employee with ID 101.
    cout << employee[101] << endl;

    // Print the salary of employee with ID 101.
    mp.clear();
    employee.clear();
    if (mp.empty())
        cout << "map mp is empty\n";
    else
        cout << "map mp is not empty\n";

    if (employee.empty())
        cout << "map employee is empty\n";
    else
        cout << "map employee is not empty\n";

    return 0;
}