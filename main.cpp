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
};

class Graph
{

public:
    int v;
    vector<User> usersList;
    unordered_map<int, vector<int>> adj;

    Graph()
    {
        v = 0;
    }

    void addUser(string username)
    {

        usersList.push_back(User(v, username));
    }

    void addFriend(int u, int v, bool direction = false)
    {
        // default we set the friends are undirectional
        adj[u].push_back(v);

        if (!direction)
            adj[v].push_back(u);
    }

    void displayFriends(int userId)
    {

        User user = usersList[userId];
        cout << "Friends of " << user.name << " are : " << endl;

        for (int firendId : adj[userId])
        {
            User frnd = usersList[firendId];
            cout << "\t >" << frnd.name << endl;
        }
    }

    // This function is used to show mutual friends between to users
    void findMutualFriends(int userId_1, int userId_2)
    {
    }
};

int main()
{
    Graph g;
    g.addUser("alice");
    g.addUser("bob");
    g.addUser("athul");
    g.addUser("arun");

    g.addFriend(0, 1);
    g.addFriend(0, 2);
    g.addFriend(0, 3);

    g.displayFriends();
}