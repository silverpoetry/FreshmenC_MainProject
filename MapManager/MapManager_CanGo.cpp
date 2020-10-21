#include "MapManager.h"
#include <cstdio>
#include <cstdlib>

bool is_CanGo(int player, int x, int y, int i, int y);

struct Point {
  unsigned int x;
  unsigned int y;
};


int queryMap(const struct Point);
bool is_CanGo(const int player, const struct Point,
              const struct Direction); // the first point should be {!player}
bool is_CanGo2(const int player, const struct Point,
               const struct Direction); // the last point should be {player}
struct Point nextPoint(const struct Point, const struct Direction);



bool MapManager_CanGo(const int player, const unsigned int x,
                      const unsigned int y) {
  if (x >= ColNumber || y >= RowNumber || x == 0 || y == 0) {
    return false;
  }
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      if (MapManager_Map[x][y] == BLANK &&
          MapManager_Map[x + i][y + j] == !player) {
        return is_CanGo(player, x + i, y + j, i, j);
      }
      return false;
    }
  }
}

bool is_CanGo(int player, int x, int y, int i, int j) {
  int tmp = MapManager_Map[x + i][y + j];
  if (tmp == !player) {
    return is_CanGo(player, x + i, y + j, i, j);
  }
  if (tmp == player) {
    return true;
  }
  return false;
}