//contributed by srikar padaliya<srikarpadaliya@gmail.com>

#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int, int>> vpair;

bool respect_to_y(const pair<int, int> a, const pair<int, int> b)
{
    return (a.second < b.second);
}

float distance(pair<int, int> v1, pair<int, int> v2)
{
    return sqrt(pow(v1.first - v2.first, 2) + pow(v1.second - v2.second, 2));
}

vpair BruteForce(vpair &v, int n)
{
    vpair v1 = v;
    float min = FLT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (distance(v[i], v[j]) < min)
            {
                v1.clear();
                v1.push_back(v[i]);
                v1.push_back(v[j]);
                min = distance(v[i], v[j]);
            }
        }
    }
    return v1;
}

vpair stripClosest(vpair &strip, int size, float d, vpair &closest)
{
    float min = d;
    vpair close = closest;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size && (strip[j].second - strip[i].second) < min; j++)
        {
            if (distance(strip[i], strip[j]) < min)
            {
                close.clear();
                close.push_back(strip[i]);
                close.push_back(strip[j]);
                min = distance(strip[i], strip[j]);
            }
        }
    }

    return close;
}

vpair closestUntil(vpair &Vx, vpair &Vy, int n)
{
    if (n <= 3)
        return BruteForce(Vx, n);

    int mid = n / 2;
    vpair midPoint;
    midPoint.push_back(Vx[mid]);

    vpair Py_left;
    vpair Py_right;
    int li = 0, ri = 0;

    for (int i = 0; i < n; i++)
    {
        if ((Vy[i].first < midPoint[0].first || (Vy[i].first == midPoint[0].first && Vy[i].second < midPoint[0].second)) && li < mid)
        {
            Py_left.push_back(Vy[i]);
            li++;
        }
        else
            Py_right.push_back(Vy[i]);
    }

    vpair halfv;
    for (int i = mid; i < n; i++)
        halfv.push_back(Vx[i]);

    vpair vl = closestUntil(Vx, Py_left, mid);
    vpair vr = closestUntil(halfv, Py_right, n - mid);

    int d1, d2;
    d1 = distance(vl[0], vl[1]);
    d2 = distance(vr[0], vr[1]);

    int d = min(d1, d2);

    vpair closestPair;
    if (d == d1)
        closestPair = vl;
    else
        closestPair = vr;

    vpair strip;
    for (int i = 0; i < n; i++)
        if (abs(Vy[i].first - midPoint[0].first) < d)
            strip.push_back(Vy[i]);

    return stripClosest(strip, strip.size(), d, closestPair);
}

vpair closest(vpair &v, int n)
{
    vpair Vx;
    vpair Vy;

    for (int i = 0; i < n; i++)
    {
        Vx.push_back(v[i]);
        Vy.push_back(v[i]);
    }

    sort(Vx.begin(), Vx.end());
    sort(Vy.begin(), Vy.end(), respect_to_y);

    return closestUntil(Vx, Vy, n);
}

int main()
{
    int n;
    cout << "Total number of points : ";
    cin >> n;
    vpair v, closest_pair;
    cout << " enter coordinates of each points \n";
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    closest_pair = closest(v, n);
    float dist = distance(closest_pair[0], closest_pair[1]);
    printf("2 closest pairs: (%d, %d) and (%d, %d).\n", closest_pair[0].first, closest_pair[0].second, closest_pair[1].first, closest_pair[1].second);
    printf("Distance: %f.", dist);
    return 0;
}
