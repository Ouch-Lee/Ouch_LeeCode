#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;
struct Pixel
{
    int x, y ,dist;
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int w, h, m, k; // 奇数
    cin >> w >> h;
    cin >> m;
    cin >> k;
    
    // 确定中间点
    int a = (w-1) / 2; // 宽 => j
    int b = (h-1) / 2; // 高 => i
    vector<Pixel> v;
    v.reserve(w*h / 10);
    int val;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> val;
            if (val == m) // 
            {
                int distance = abs(j - a) + abs(i - b);
                v.push_back({j, i, distance});
            }
        }
    }

    sort(v.begin(), v.end(), [](const Pixel &a, const Pixel &b){
        if (a.dist != b.dist) return a.dist < b.dist;
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
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