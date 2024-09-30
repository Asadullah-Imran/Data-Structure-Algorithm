#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int kx, ky;
        cin >> kx >> ky;
        int qx, qy;
        cin >> qx >> qy;

        set<pair<int, int>> kSet;
        set<pair<int, int>> qSet;
        set<pair<int, int>> intersectionSet;

        kSet.insert({kx + b, ky + a});
        kSet.insert({kx + a, ky + b});
        kSet.insert({kx + b, ky - a});
        kSet.insert({kx + a, ky - b});
        kSet.insert({kx - a, ky - b});
        kSet.insert({kx - b, ky - a});
        kSet.insert({kx - a, ky + b});
        kSet.insert({kx - b, ky + a});

        qSet.insert({qx - b, qy + a});
        qSet.insert({qx - a, qy + b});
        qSet.insert({qx + b, qy + a});
        qSet.insert({qx + a, qy + b});
        qSet.insert({qx + b, qy - a});
        qSet.insert({qx + a, qy - b});
        qSet.insert({qx - b, qy - a});
        qSet.insert({qx - a, qy - b});

        set_intersection(kSet.begin(), kSet.end(), qSet.begin(), qSet.end(), inserter(intersectionSet, intersectionSet.begin()));

        // for (const auto &pos : kSet)
        // {
        //     if (qSet.find(pos) != qSet.end())
        //     {
        //         intersectionSet.insert(pos);
        //     }
        // }

        cout << intersectionSet.size() << endl;
    }
}
