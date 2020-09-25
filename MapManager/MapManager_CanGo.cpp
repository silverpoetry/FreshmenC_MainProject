#include "MapManager.h"
#include <cstdlib>

struct Direction {
  int x;
  int y;
};

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

//判断某位置是否能走棋
bool MapManager_CanGo(const int player, const unsigned int x,
                      const unsigned int y) {

  if (x >= 9 || y >= 9 || x == 0 || y == 0) {
    return false;
  }

  struct Direction direction = {-1, -1};
  struct Point point = {x, y};

  while (true) {
    if (is_CanGo(player, point, direction)) {
      return true;
    }
    if (direction.x == 1 && direction.y == 1) {
      return false;
    }

    // next direction
    if (direction.x != 1) {
      direction.x++;
      if (direction.x == 0 && direction.y == 0) {
        direction.x++;
      }
    } else {
      direction.x = -1;
      direction.y++;
    }
  }

  return false;
}

bool is_CanGo(const int player, const struct Point point,
              const struct Direction direction) {
  if (queryMap(point) != BLANK) {
    return false;
  }
  struct Point tmpPoint = nextPoint(point, direction);
  if (queryMap(tmpPoint) != !player) {
    return false;
  }
  return is_CanGo2(player, tmpPoint, direction);
}

bool is_CanGo2(const int player, const struct Point point,
               const struct Direction direction) {
  struct Point tmpPoint = nextPoint(point, direction);
  int tmp = queryMap(tmpPoint);
  if (tmp == BLANK) {
    return false;
  } else if (tmp == player) {
    return true;
  } else {
    return is_CanGo2(player, tmpPoint, direction);
  }
}

struct Point nextPoint(const struct Point point,
                       const struct Direction direction) {
  int x = point.x + direction.x;
  int y = point.y + direction.y;
  if (x >= 0 && y >= 0) {
    struct Point ret = {(unsigned int)x, (unsigned int)y};
    return ret;
  } else {
    printf("error: point extendind out of map");
    exit(1);
  }
}

int queryMap(const struct Point point) {
  unsigned int x = point.x, y = point.y;
  if (x <= 9 && y <= 9) {
    return MapManager_Map[x][y];
  } else {
    printf("this code should never be reached: the query is out of map");
    exit(1);
  }
}
