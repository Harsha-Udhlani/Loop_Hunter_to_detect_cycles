#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = nullptr;
    }
    Node(int d)
    {
        this->data = d;
        next = nullptr;
    }
};
Node *createLL()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    int data = 0;

    while (data != -1)
    {

        cout << "Enter the data of SLL and -1 to terminate the list" << endl;
        cin >> data;
        if (data != -1)
        {
            if (head == nullptr && tail == nullptr)
            {
                head = new Node(data);
                tail = head;
            }
            else
            {
                tail->next = new Node(data);
                tail = tail->next;
            }
        }
    }
    char ch;
    cout << "Do you want to create cycle?";
    cin >> ch;
    if (ch == 'y')
    {
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = head;
    }
    return head;
}
void detectLLCycleUsingSet()
{
    Node *head = createLL();
    Node *temp = head;
    set<Node *> st;
    while (temp)
    {
        if (st.find(temp) == st.end())
        {
            st.insert(temp);
            temp = temp->next;
        }
        else
        {
            cout << "Cycle is Present" << endl;
            return;
        }
    }
    cout << "Cycle is not Present!!" << endl;
    return;
}
void detectLLCycleUsingTwoPointer()
{
    Node *head = createLL();
    if (head == nullptr)
    {
        cout << "LL is empty!!";
        return;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout << "Cycle is Present" << endl;
            return;
        }
    }
    cout << "Cycle is Not Present" << endl;
    return;
}
vector<vector<int>> createUndirectedGraph()
{
    int n, e;
    cout << "Enter the number of nodes";
    cin >> n;
    cout << "Enter number of Edges:" << endl;
    cin >> e;
    int u, v;
    vector<vector<int>> adjL(n);
    for (int i = 0; i < e; i++)
    {
        cout << "Enter u:";
        cin >> u;
        cout << "Enter v:";
        cin >> v;
        if (u < 0 || v < 0 || u >= n || v >= n)
        {
            cout << "Invalid edge!" << endl;
            i--;
            continue;
        }
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }
    return adjL;
}

void detectCycleUsingBFS()
{

    vector<vector<int>> adjL = createUndirectedGraph();
    queue<pair<int, int>> q;
    vector<bool> vis(adjL.size(), false);
    for (int i = 0; i < adjL.size(); i++)
    {
        if (!vis[i])
        {
            q.push({i, -1});
            vis[i] = true;
            while (!q.empty())
            {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for (auto it : adjL[node])
                {
                    if (!vis[it])
                    {
                        q.push({it, node});
                        vis[it] = true;
                    }
                    else if (it != parent)
                    {
                        cout << "Cycle is Present!!" << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "Cycle not present!!" << endl;
    return;
}

vector<vector<int>> createDirectedGraph()
{
    int n, e;
    cout << "Enter number of nodes ";
    cin >> n;
    cout << "Enter the number of Edges";
    cin >> e;
    int u, v;
    vector<vector<int>> adjL(n);
    for (int i = 0; i < e; i++)
    {
        cout << "Enter u:";
        cin >> u;
        cout << "Enter v:";
        cin >> v;
        if (u < 0 || v < 0 || u >= n || v >= n)
        {
            cout << "Invalid edge!" << endl;
            i--;
            continue;
        }
        adjL[u].push_back(v);
    }
    return adjL;
}
void detectCycleUsingTopo()
{
    vector<vector<int>> adjL = createDirectedGraph();
    int n = adjL.size();
    vector<int> Indeg(adjL.size(), 0);
    for (int i = 0; i < adjL.size(); i++)
    {
        for (auto it : adjL[i])
        {
            Indeg[it]++;
        }
    }
    queue<int> q;
    vector<int> ans;

    for (int i = 0; i < Indeg.size(); i++)
    {
        if (Indeg[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it : adjL[node])
        {
            Indeg[it]--;
            if (Indeg[it] == 0)
            {
                q.push(it);
            }
        }
    }
    if (ans.size() == n)
    {
        cout << "Cycle not Present!!" << endl;
        return;
    }
    cout << "Cycle is Present!!" << endl;
    return;
}
bool dfsHelper(int node, vector<bool> &vis, vector<vector<int>> &adjL, int p)
{

    vis[node] = true;
    for (auto it : adjL[node])
    {
        if (!vis[it])
        {
            if (dfsHelper(it, vis, adjL, node))
                return true;
        }
        else
        {
            if (it != p)
                return true;
        }
    }

    return false;
}
void detectCycleUsingDFS()
{
    vector<vector<int>> adjL = createUndirectedGraph();
    vector<bool> vis(adjL.size(), false);
    for (int i = 0; i < adjL.size(); i++)
    {
        if (!vis[i])
        {
            if (dfsHelper(i, vis, adjL, -1))
            {
                cout << "Cycle is Present" << endl;
                return;
            }
        }
    }
    cout << "Cycle is not present!!" << endl;
    return;
}
int main()
{
    int choice;

    while (true)
    {
        cout << "1. Detect cycle in Singly Linked List\n";
        cout << "2. Detect cycle in Graph\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "a. Using Set\nb. Using Slow-Fast Pointer\n";
            char ch;
            cin >> ch;
            if (ch == 'a')
            {
                detectLLCycleUsingSet();
                cout << "Best Case Time Complexity: O(N)\nWorst Case Time Complexity: O(N)\nAverage Case Time Complexity: O(N)\nSpace Complexity: O(N) for the set" << endl;
            }
            else if (ch == 'b')
            {
                detectLLCycleUsingTwoPointer();
                cout << "Best Case Time Complexity (BC): O(N)\nWorst Case Time Complexity (WC): O(N)\nAverage Case Time Complexity (AC): O(N)\nSpace Complexity: O(1) (constant space)" << endl;
            }
            else
                cout << "Invalid method!\n";
        }
        else if (choice == 2)
        {
            cout << "a. BFS (Undirected)\nb. DFS (Directed/Undirected)\nc. Topological Sort (Directed)\n";
            char ch;
            cin >> ch;
            if (ch == 'a')
            {

                detectCycleUsingBFS();
                cout << "Best Case Time Complexity (BC): O(N)\nWorst Case Time Complexity (WC): O(N+E)\nAverage Case Time Complexity (AC): O(N+E)\nSpace Complexity: O(N) " << endl;
            }
            else if (ch == 'b')
            {
                detectCycleUsingDFS();
                cout << "Best Case Time Complexity (BC): O(N)\nWorst Case Time Complexity (WC): O(N+E)\nAverage Case Time Complexity (AC): O(N+E)\nSpace Complexity: O(N) " << endl;
            }
            else if (ch == 'c')
            {
                detectCycleUsingTopo();
                cout << "Best Case Time Complexity (BC): O(N+E)\nWorst Case Time Complexity (WC): O(N+E)\nAverage Case Time Complexity (AC): O(N+E)\nSpace Complexity: O(N) " << endl;
            }
            else
                cout << "Invalid method!\n";
        }
        else if (choice == 3)
            break;
        else
            cout << "Invalid Choice!\n";
    }
}