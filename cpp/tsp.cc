#include <iostream>
#include <string>
#include <set>

using ::std::cout;
using ::std::string;
using ::std::set;

struct Point {
  int x;
  int y;

  // A bit unfortunate, but I want to put `Point`s in `set`s, and they are ordered.
  bool operator<(const Point other) const {
    // Use lexicographic order, which I believe to satisfy the strict weak ordering requirement.
    return (x != other.x && x < other.x) || y < other.y;
  }
};

void printPoint(Point point) {
  cout << "(" << point.x << ", " << point.y << ")\n";
}

void print(set<Point> points, string title) {
  cout << "--- " << title << " ---\n";
  for (const auto &p : points) {
    printPoint(p);
  }
}

int main() {
  set<Point> unvisited = { {1,1},{2,3},{3,1},{5,7} };
  set<Point> visited;
  for (auto p = unvisited.begin(); p != unvisited.end(); ) {
    cout << "--- current ---\n";
    auto cur = *p;
    printPoint(cur);
    visited.insert(cur);
    p = unvisited.erase(p);
    print(visited, "visited");
    print(unvisited, "unvisited");
  }
  print(visited, "final");
}
