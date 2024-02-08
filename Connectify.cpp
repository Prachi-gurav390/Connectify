#include <bits/stdc++.h>
using namespace std;

class SN
{
private:
    unordered_map<string, set<string>> n;

public:
    void addFriend(const string &u, const string &f)
    {
        n[u].insert(f);
        n[f].insert(u);
    }

    void removeFriend(const string &u, const string &f)
    {
        n[u].erase(f);
        n[f].erase(u);
    }

    void suggestConnections(const string &u)
    {
        set<string> suggestions;

        for (const string &f : n[u])
        {
            for (const string &suggestedf : n[f])
            {
                if (suggestedf != u && n[u].find(suggestedf) == n[u].end())
                {
                    suggestions.insert(suggestedf);
                }
            }
        }

        cout << "Suggestions for " << u << ":\n";
        for (const string &suggestedf : suggestions)
        {
            cout << suggestedf << "\n";
        }
    }

    void findShortestPath(const string &s, const string &e)
    {
        unordered_map<string, string> parent;
        queue<string> q;
        set<string> visited;

        q.push(s);
        visited.insert(s);

        while (!q.empty())
        {
            string current = q.front();
            q.pop();

            if (current == e)
            {
                vector<string> path;
                string node = e;

                while (node != s)
                {
                    path.push_back(node);
                    node = parent[node];
                }

                path.push_back(s);

                cout << "Best path between " << s << " and " << e << ":\n";
                for (int i = path.size() - 1; i >= 0; --i)
                {
                    cout << path[i] << " ";
                }
                cout << "\n";
                return;
            }

            for (const string &frnd : n[current])
            {
                if (visited.find(frnd) == visited.end())
                {
                    q.push(frnd);
                    visited.insert(frnd);
                    parent[frnd] = current;
                }
            }
        }
        cout << "No path found between " << s << " and " << e << ".\n";
    }

    void displayMutualFriends(const string &u1, const string &u2)
    {
        set<string> mutualFriends;

        for (const string &frnd : n[u1])
        {
            if (n[u2].count(frnd))
            {
                mutualFriends.insert(frnd);
            }
        }

        cout << "Mutual friends between " << u1 << " and " << u2 << ":\n";
        for (const string &mutualFrnd : mutualFriends)
        {
            cout << mutualFrnd << "\n";
        }
    }
};

int main()
{
    SN n;
    int s;

    while (true)
    {
        // cout << "Give a command (add, remove, suggest, path, mutual, quit): ";
        cout << "Give a command \n";
        cout << "Press 1 to add\n      2 to remove\n      3 to suggest\n      4 to Find out best path\n      5 to find out mutual friends\n      6 to quit\n";
        cin >> s;

        if (s == 1)
        {
            string u, f;
            cout << "Enter usernames (user, friend): ";
            cin >> u >> f;
            n.addFriend(u, f);
        }
        else if (s == 2)
        {
            string u, f;
            cout << "Enter usernames (user. friend): ";
            cin >> u >> f;
            n.removeFriend(u, f);
        }
        else if (s == 3)
        {
            string u;
            cout << "Enter username: ";
            cin >> u;
            n.suggestConnections(u);
        }
        else if (s == 4)
        {
            string s, e;
            cout << "Enter start and end usernames: ";
            cin >> s >> e;
            n.findShortestPath(s, e);
        }
        else if (s == 5)
        {
            string u1, u2;
            cout << "Enter usernames (user1, user2): ";
            cin >> u1 >> u2;
            n.displayMutualFriends(u1, u2);
        }
        else if (s == 6)
        {
            break;
        }
        else
        {
            cout << "Invalid command\n";
        }
    }

    return 0;
}
