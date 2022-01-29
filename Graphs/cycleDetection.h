// Detecting cycle using 'union-find-algorithm'
bool cycleDetector(int v1, int v2, int *parent)
{
    int p1 = v1;
    int p2 = v2;
    while (p1 != parent[v1])
    {
        v1 = parent[v1];
        p1 = parent[v1];
    }
    while (p2 != parent[v2])
    {
        v2 = parent[v2];
        p2 = parent[v2];
    }
    return (p1 == p2);
}