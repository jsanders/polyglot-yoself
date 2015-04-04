#include <iostream>
#include <set>
#include <vector>
#include <cmath>

struct Point {
  int x;
  int y;
};

// Some useful operations for Points

std::ostream& operator<< (std::ostream& os, const Point& p) {
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}

bool operator<(const Point a, const Point b) {
  // Use lexicographic order, which I believe to satisfy the strict weak ordering requirement.
  return (a.x != b.x && a.x < b.x) || a.y < b.y;
}

double distance(const Point a, const Point b) {
  auto xdist = std::abs(a.x - b.x);
  auto ydist = std::abs(a.y - b.y);
  return std::sqrt(xdist * xdist + ydist * ydist);  
}

// Printing stuff

template <typename T>
void banner(T v) {
  std::cout << "----- " << v << " -----" << std::endl;
}

template <typename T>
void print(T points) {
  for (const auto &p : points) {
    std::cout << p << std::endl;
  }
}

// Find nearest neighbor in given set
Point nearest_neighbor(Point point, std::set<Point> neighbors) {
  auto it = neighbors.begin();
  Point nearest = *it;
  double dist = distance(point, nearest);
  for (; it != neighbors.end(); ++it) {
    double _dist = distance(point, *it);
    if (_dist < dist) {
      nearest = *it;
      dist = _dist;
    }
  }
  return nearest;
}

// Find a path using the nearest neighbor heuristic
std::vector<Point> nearest_neighbor_heuristic(std::set<Point> points) {
  std::vector<Point> visited;
  Point last;
  Point current = *points.begin();

  while(true) {
    visited.push_back(current);
    points.erase(current);
    last = current;

    if (points.size() == 0) {
      break;
    } else {
      current = nearest_neighbor(current, points);
    }
  }

  return visited;
}

int main() {
  std::set<Point> points = { {1,1},{2,3},{3,1},{5,7} };
  auto solution = nearest_neighbor_heuristic(points);

  print(solution);
}
