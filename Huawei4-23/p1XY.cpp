#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

struct Pixel
{
    int x;
    int y;
    int distance;
};

int main()
{
    int w, h, m, k;
    cin >> w >> h;
    cin >> m;
    cin >> k;

    vector<Pixel> v;
    int x_center = (w - 1) / 2;
    int y_center = (h - 1) / 2;
    int val;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> val;
            if (val == m)
            {
                int dis = abs(j - x_center) + abs(i - y_center);
                v.push_back({j, i, dis});
            }
        }
    }

    sort(v.begin(), v.end(), [](Pixel p1, Pixel p2)->bool {
        if (p1.distance != p2.distance) return p1.distance < p2.distance;
        if (p1.x != p2.x) return p1.x < p2.x;
        return p1.y < p2.y; 
    });
    int cnt = min((int)v.size(), k);
    for (int i = 0; i < cnt; i++)
    {
        cout << v[i].x << ' ' << v[i].y;
        if (i+1 < cnt) cout << ' ';
    }
    cout << endl;
    return 0;
}