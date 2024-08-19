#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> all;
int total = 0;
set<int> st;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node *createLinkedList(int arr[], int n)
{
    if (n == 0)
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *curr = head;

    for (int i = 1; i < n; i++)
    {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

Node *reverse(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next; // save
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
int length(Node *head)
{
    int cnt = 0;
    Node *curr = head;
    while (curr != nullptr)
    {
        cnt++;
        curr = curr->next;
    }
    return cnt;
}

void print(Node *head)
{
    Node *curr = head;

    while (curr != nullptr)
    {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << endl;
}

int fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

void generateCombinations(int cb, int nboxes, int ssf, int ritems, vector<int> &asf, vector<int> &items)
{
    if (cb > nboxes)
    {
        if (ssf == ritems)
        {
            for (int i : asf)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }
    asf.push_back(items[cb - 1]);
    generateCombinations(cb + 1, nboxes, ssf + 1, ritems, asf, items);
    asf.pop_back();
    generateCombinations(cb + 1, nboxes, ssf, ritems, asf, items);
}

void generatePermutations(map<int, int> &fmap, vector<int> &current, int n)
{
    if (current.size() == n)
    {
        for (int i : current)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for (auto pair : fmap)
    {
        if (pair.second > 0)
        {
            pair.second--;
            current.push_back(pair.first);
            generatePermutations(fmap, current, n);
            current.pop_back();
            pair.second++;
        }
    }
}

void permutations(Node *head)
{
    

    Node *curr = head;
    map<int, int> fmap;
    
    while (curr != nullptr)
    {
        st.insert(curr->data);
        all.push_back(curr->data);
        fmap[curr->data]++;
        total++;
        curr = curr->next;
    }
    int totalFactorial = fact(total);

    int freqFactorialProduct = 1;
    for (const auto &pair : fmap)
    {
        freqFactorialProduct *= fact(pair.second);
        cout << pair.first << " appears " << pair.second << endl;
    }

    int distinctPermutations = totalFactorial / freqFactorialProduct;
    cout << "\nNo of distinct permutation is " << distinctPermutations << endl;

    vector<int> current;
    generatePermutations(fmap, current, total);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *head = createLinkedList(arr, n);
    print(head);
    int len = length(head);
    cout << "Length is " << len << endl;
    permutations(head);

    vector<int> asf;
    cout << "The combinations are:-" << endl;
    generateCombinations(1, total, 0, st.size(), asf, all);

    cout << endl
         << endl;
    Node *nhead = reverse(head);
    print(nhead);

    return 0;
}