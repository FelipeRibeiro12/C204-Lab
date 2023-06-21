#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

double calculateDistance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double calculateTotalDistance(vector<Point>& points) {
    double totalDistance = 0.0;
    int n = points.size();

    for (int i = 0; i < n - 1; i++) {
        totalDistance += calculateDistance(points[i], points[i + 1]);
    }

    return totalDistance;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double totalDistance = calculateTotalDistance(points);

    cout << fixed << setprecision(3) << totalDistance << endl;

    return 0;
}
