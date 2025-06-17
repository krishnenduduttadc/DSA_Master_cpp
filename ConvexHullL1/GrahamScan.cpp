#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

// Check if two points are equal
bool isEqual(Point a, Point b) {
    return a.x == b.x && a.y == b.y;
}

// Clockwise check
bool cw(Point a, Point b, Point c) {
    return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) > 0;
}

// Counter-clockwise check
bool ccw(Point a, Point b, Point c) {
    return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) < 0;
}

// Convex hull function
vector<Point> convex_hull(vector<Point>& points) {
    if (points.size() <= 2) return points;

    // Sort points by x, then y
    sort(points.begin(), points.end(), [](Point a, Point b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });

    vector<Point> up, down;
    Point first = points.front(), last = points.back();

    up.push_back(first);
    down.push_back(first);

    for (size_t i = 1; i < points.size(); ++i) {
        // Upper hull
        if (i == points.size() - 1 || cw(first, points[i], last)) {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up.back(), points[i])) {
                up.pop_back();
            }
            up.push_back(points[i]);
        }
        // Lower hull
        if (i == points.size() - 1 || ccw(first, points[i], last)) {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down.back(), points[i])) {
                down.pop_back();
            }
            down.push_back(points[i]);
        }
    }

    vector<Point> hull;
    for (auto p : up) hull.push_back(p);
    for (int i = down.size() - 2; i > 0; --i) hull.push_back(down[i]);

    // Remove duplicates
    vector<Point> final_hull;
    for (auto& p : hull) {
        bool found = false;
        for (auto& q : final_hull) {
            if (isEqual(p, q)) {
                found = true;
                break;
            }
        }
        if (!found) final_hull.push_back(p);
    }

    return final_hull;
}

int main() {
    vector<Point> points = {
        {0, 0},
        {1, 1},
        {2, 2},
        {0, 2},
        {2, 0},
        {1, 2},
        {2, 1}
    };

    vector<Point> hull = convex_hull(points);

    cout << "Convex Hull Points:" << endl;
    for (auto p : hull) {
        cout << p.x << " " << p.y << endl;
    }

    return 0;
}
