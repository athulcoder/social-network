#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class User
{

public:
    int id;
    string name;

    User()
    {
    }

    User(int id, string name)
    {
        this->id = id;
        this->name = name;
    }

    void displayUser()
    {
        cout << "User ID : " << id << " Username : " << name << endl;
    }

}

class Graph
{
    int v;
    unordered_map<User, vector<User>> adj;

public:
}