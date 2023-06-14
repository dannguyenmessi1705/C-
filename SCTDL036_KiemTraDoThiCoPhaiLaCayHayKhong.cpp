#include <bits/stdc++.h>
using namespace std;
// Tao struct la 1 canh
struct Edge
{
    int u; // Dinh dau
    int v; // Dinh cuoi
};
int n, m;          // Khai bao so dinh, so canh
int sz[10001];     // Khai bao kich thuoc cua 1 tap hop
int parent[10001]; // Khai bao mang cha cua cac dinh
vector<Edge> canh; // Tao vector chua tap canh(struct)
// Khoi tao gia tri ban dau, cac dinh co cha la chinh no, ban dau chua tap hop voi dinh nao nen kich thuoc tap hop la 1
void make_set()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}
// Ham tim dinh cha
int findParent(int x)
{
    if (x == parent[x])
        return x;                             // Neu dinh cha cua X la chinh no thi tra ve ket qua
    return parent[x] = findParent(parent[x]); // Neu thi ta truy vet nguoc lai len tren de tim, dong thoi gan cac dinh da truy vet nay bang voi dinh cha khi tim duoc
}
// Ham kiem tra, hop lai cac dinh
bool Union(int x, int y)
{
    x = findParent(x); // Tim dinh cha cua X
    y = findParent(y); // Tim dinh cha cua Y
    if (x == y)
        return false; // Neu X va Y co chung dinh cha, thi 2 dinh nay thuoc 1 tap hop, nen ko the gop lai
    else
    { // Nguoc lai, X va Y ko cung dinh cha
        // Code toi uu duong
        if (sz[x] >= sz[y])
        {                   // Neu tap hop cua X chua nhieu dinh hon tap hop cua Y
            parent[y] = x;  // Cho dinh Y hop vao tap cua X, dong thoi lay dinh cha cua X lam dinh cha cho minh
            sz[x] += sz[y]; // Tang kich thuoc tap hop cua X len
        }
        else
        {                   // Nguoc lai
            parent[x] = y;  // Cho dinh X hop vao tap cua Y, dong thoi lay dinh cha cua Y lam dinh cha cho minh
            sz[y] += sz[x]; // Tang kich thuoc tap hop cua Y len
        }
    }
    return true;
}
// Ham nhap
void Nhap()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        canh.push_back({u, v});
    }
}
void Kruskal()
{
    // Tao tap canh cay khung ban dau rong
    vector<Edge> Tree;
    // tim cay khung nho nhat
    for (int i = 0; i < n - 1; i++)
    {
        {                     // Nguoc lai
            Edge e = canh[i]; // Chon canh dau tien
            if (Union(e.u, e.v))
            {                      // Neu canh co 2 dinh co kha nang tap hop duoc voi nhau
                Tree.push_back(e); // Them canh vao cay khung
            }
        }
    }
    if (Tree.size() != n - 1)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
    }
    canh.clear();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while (test--)
    {
        Nhap();
        make_set();
        Kruskal();
    }
    return 0;
}
// Input
/*
6 9
1 2 12
1 3 4
2 3 1
2 4 5
2 5 3
3 5 2
4 5 3
4 6 10
5 6 8
*/