#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
        cout << "User ID : " << id << " Name : " << name << endl;
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

    void showFriendSuggestions(int userId)
    {

        // Now SuggestionList contains the BFS traversel
        // now  have to remove ids of (user and ids of his friends from this list)

        vector<int> suggestionList = Bfs_Travsersel(userId);
        unordered_set<int> directFriends(adj[userId].begin(), adj[userId].end());

        cout << "Friends Suggestion for " << usersList[userId].name << endl;
        for (auto id : suggestionList)
        {
            if (userId != id && directFriends.find(id) == directFriends.end())
            {
                User user = usersList[id];
                user.displayUser();
            }
        }
    }

    vector<int> Bfs_Travsersel(int userId)
    {

        //
        vector<int> resultList;

        unordered_map<int, bool> visited; // array to store visited ids
        queue<int> q;

        q.push(userId);
        visited[userId] = 1; // true

        while (!q.empty())
        {
            int nodeId = q.front();
            q.pop();
            resultList.push_back(nodeId);

            for (int i = 0; i < adj[nodeId].size(); i++)
            { // loops trought all ids of a particular nodeId

                if (!visited[adj[nodeId][i]])
                {
                    visited[adj[nodeId][i]] = 1;
                    q.push(adj[nodeId][i]);
                }
            }
        }

        return resultList;
    }
};

int main()
{
    int choice;
    string name;
    int id, id1, id2;

    // Creating a graph object frist
    Graph g;
    do
    {
        cout << "\n===== Social Network Menu =====\n";
        cout << "1. Add User\n";
        cout << "2. Add Friend\n";
        cout << "3. Display Friends\n";
        cout << "4. Find Mutual Friends\n";
        cout << "5. Show Friend Suggestions\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {

            cout << "Enter user name: ";
            cin >> name;
            g.addUser(name);
            break;
        }
        case 2:
        {

            cout << "Enter two user IDs: ";
            cin >> id1 >> id2;
            g.addFriend(id1, id2);
            break;
        }
        case 3:
        {

            cout << "Enter user ID: ";
            cin >> id;
            g.displayFriends(id);
            break;
        }
        case 4:
        {

            cout << "Enter two user IDs: ";
            cin >> id1 >> id2;
            g.findMutualFriends(id1, id2);
            break;
        }
        case 5:
        {

            cout << "Enter user ID: ";
            cin >> id;
            g.showFriendSuggestions(id);
            break;
        }
        case 0:
            cout << "Exiting... Goodbye!\n";
            break;
        default:
            cout << "Invalid choice, try again.\n";
        }
    } while (choice != 0);

    return 0;
}

// int main()
// {
//     Graph g;
//     g.addUser("alice");
//     g.addUser("bob");
//     g.addUser("athul");
//     g.addUser("arun");
//     g.addUser("george");
//     g.addUser("micael");
//     g.addUser("midhun");
//     g.addUser("joseph");
//     g.addUser("mohan");

//     g.addFriend(0, 1);
//     g.addFriend(0, 2);
//     g.addFriend(1, 5);
//     g.addFriend(1, 7);
//     g.addFriend(2, 3);
//     g.addFriend(2, 4);
//     g.addFriend(5, 6);
//     g.addFriend(6, 8);
//     g.addFriend(7, 8);
//     g.displayFriends(4);
//     g.showFriendSuggestions(4);
//     g.findMutualFriends(0, 3);
// }