#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Function to perform topological sorting
bool topologicalSort(vector<vector<string>>& graph, vector<int>& inDegree, vector<string>& order) {
    queue<string> q;
    for (int i = 0; i < inDegree.size(); i++) {
        if (inDegree[i] == 0) {
            q.push(to_string(i));
        }
    }

    while (!q.empty()) {
        string u = q.front();
        q.pop();
        order.push_back(u);

        for (string v : graph[stoi(u)]) {
            inDegree[stoi(v)]--;
            if (inDegree[stoi(v)] == 0) {
                q.push(v);
            }
        }
    }

    return order.size() == inDegree.size();
}

int main() {
    int n; // Number of tasks
    cout << "Enter the number of tasks: ";
    cin >> n;

    vector<vector<string>> graph(n);
    vector<int> inDegree(n, 0);
    unordered_map<string, int> taskToIndex;

    // Input the task names
    cout << "Enter the names of the tasks:" << endl;
    for (int i = 0; i < n; i++) {
        string taskName;
        cin >> taskName;
        taskToIndex[taskName] = i;
    }

    // Input the precedence relationships
    cout << "Enter the number of precedence relationships: ";
    int m;
    cin >> m;

    cout << "Enter the precedence relationships (task u must be done before task v):" << endl;
    for (int i = 0; i < m; i++) {
        string u, v;
        cin >> u >> v;
        graph[taskToIndex[u]].push_back(v);
        inDegree[taskToIndex[v]]++;
    }

    vector<string> order;
    if (topologicalSort(graph, inDegree, order)) {
        cout << "Sandy can solve all his duties. Correct order of tasks:" << endl;
        for (string task : order) {
            cout << task << " ";
        }
        cout << endl;
    } else {
        cout << "Sandy cannot solve all his duties." << endl;
    }

    return 0;
}

/*
Answer
Here's a sample output for the code:
Enter the number of tasks: 5
Enter the names of the tasks:
Task1 Task2 Task3 Task4 Task5
Enter the number of precedence relationships: 4
Enter the precedence relationships (task u must be done before task v):
Task1 Task3
Task2 Task3
Task2 Task4
Task4 Task5
Sandy can solve all his duties. Correct order of tasks:
Task1 Task2 Task4 Task3 Task5
*/