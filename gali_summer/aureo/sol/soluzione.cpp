// @check-accepted: esempi N_100,V_i>=0 N_100 V_i>=0 full
#include <vector>
#include <iostream>
using namespace std;

#define ST_SIZE 210000
#define OFFSET 100000
#define MOD 1000000007
struct Node
{
    long long value, active;
    Node *left;
    Node *right;
    Node()
    {
        value = 0;
        active = 0;
        left = nullptr;
        right = nullptr;
    }
};
vector<Node> pool;
int loc = 0;
Node *getNode()
{
    pool[loc] = Node();
    return &pool[loc++];
}
struct segtree
{
    int N;
    Node *st;

    void init(int s)
    {
        N = s;
        st = getNode();
    }

    void build(Node *node, int l, int r)
    {
        if (l == r)
            return;

        int mid = (l + r) / 2;
        node->left = getNode();
        node->right = getNode();

        build(node->left, l, mid);
        build(node->right, mid + 1, r);
    }

    void update(Node *node, int l, int r, int target)
    {

        if (l > target || r < target)
            return;

        if (l == r)
        {
            node->value += l - OFFSET;
            node->active++;
            return;
        }

        int mid = (l + r) / 2;
        update(node->left, l, mid, target);
        update(node->right, mid + 1, r, target);

        node->value = node->left->value + node->right->value;
        node->active = node->left->active + node->right->active;
    }

    long long query(Node *node, int l, int r, int tl, int tr)
    {
        if (l > tr || r < tl)
            return 0;
        if (l >= tl && r <= tr)
            return node->value;

        int mid = (l + r) / 2;
        return query(node->left, l, mid, tl, tr) +
               query(node->right, mid + 1, r, tl, tr);
    }

    long long query_smaller(Node *node, int l, int r, int tl, int tr)
    {
        if (l > tr || r < tl)
            return 0;
        if (l >= tl && r <= tr)
            return node->active;

        int mid = (l + r) / 2;
        return query_smaller(node->left, l, mid, tl, tr) +
               query_smaller(node->right, mid + 1, r, tl, tr);
    }
};

long long sortedSum(vector<long long> a)
{
    pool.resize(3000000);
    segtree tree;
    tree.init(ST_SIZE);
    tree.build(tree.st, 0, ST_SIZE - 1);
    long long ans = 1;
    long long prev = 0;
    long long t = 0;

    for (int i = 0; i < a.size(); i++)
    {
        t += prev;
        t += tree.query(tree.st, 0, ST_SIZE - 1, (long long)a[i] + 1 + OFFSET, ST_SIZE - 1);

        t += (tree.query_smaller(tree.st, 0, ST_SIZE - 1, 0, (long long)a[i] + OFFSET) + 1ll) * (long long)a[i];

        prev = t;
        t = abs(t) % MOD;
        ans *= t;
        ans %= MOD;
        tree.update(tree.st, 0, ST_SIZE - 1, (long long)a[i] + OFFSET);
        t = 0;
    }
    return ans;
}
int main()
{
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    cout << sortedSum(A) << "\n";
}
