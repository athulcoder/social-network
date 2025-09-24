#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <queue>
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
        vector<int> f1 = adj[userId_1];
        vector<int> f2 = adj[userId_2];
        vector<int> mutuals;

        for (int i = 0; i < f1.size(); i++)
        {
            for (int j = 0; j < f2.size(); j++)
            {

                if (f1[i] == f2[j])
                {
                    mutuals.push_back(f1[i]);
                    break;
                }
            }
        }

        // after getting the mutual map the userIds with the corresponding user

        User user1 = usersList[userId_1];
        User user2 = usersList[userId_2];

        cout << "Mutual friends between " << user1.name << " and " << user2.name << endl;

        for (int i = 0; i < mutuals.size(); i++)
        {
            cout << mutuals[i];
            User frnd = usersList[mutuals[i]];
            cout << "--> " << frnd.name << endl;
        }
    }

    void showFriendSuggestion_bfsTraversel(int userId)
    {

        vector<int> suggestionsList;

        vector<int, bool> visited; // array to store visited ids
<queue>
    }
};

int main()
{
    Graph g;
    g.addUser("alice");
    g.addUser("bob");
    g.addUser("athul");
    g.addUser("arun");
    g.addUser("kiran");

    g.addFriend(0, 1);
    g.addFriend(0, 2);
    g.addFriend(0, 3);
    g.addFriend(1, 2);
    g.addFriend(3, 2);
    g.displayFriends(0);
    g.displayFriends(3);

    g.findMutualFriends(0, 3);
}