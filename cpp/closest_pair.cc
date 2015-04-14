// Closest pair heuristic for the traveling salesman problem

#include <iostream>
#include <cmath>
#include <unordered_set>
#include <vector>

struct Point {
  float x;
  float y;
};

struct PointHash {
    size_t operator()(const Point& p) const {
        return std::hash<int>()(p.x) ^ std::hash<int>()(p.y);
    }
};

struct PointEqual {
    bool operator()(const Point& p1, const Point& p2) const {
        return p1.x == p2.x && p1.y == p2.y;
    }
};

double distance(const Point a, const Point b) {
  int xdist = std::abs(a.x - b.x);
  int ydist = std::abs(a.y - b.y);
  return std::sqrt(xdist * xdist + ydist * ydist);  
}

typedef std::vector<Point> Chain;

Chain closest_pair_heuristic(std::unordered_set<Point, PointHash, PointEqual> points) {
    return Chain();
}

int main() {
    std::unordered_set<Point, PointHash, PointEqual> points = { {1,1},{2,3},{3,1},{5,7} };
    auto solution = closest_pair_heuristic(points);

    for (const auto &p : solution) {
        std::cout << p.x << ", " << p.y << std::endl;
    }

    return 0;
}
