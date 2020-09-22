#include "MapManager.h"

struct Direction {
  int x;
  int y;
};

struct Point {
  unsigned int x;
  unsigned int y;
};

int queryMap(struct Point);
bool is_CanGo(int player, struct Point, struct Direction);//the first point should be {!player}
bool is_CanGo2(int player, struct Point, struct Direction);//the last point should be {player}
struct Point nextPoint(struct Point, struct Direction);

//判断某位置是否能走棋
bool MapManager_CanGo(int player, unsigned int x, unsigned int y) {

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
      break;
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

bool is_CanGo(int player, struct Point point, struct Direction direction) {
  if (queryMap(point) != BLANK) {
    return false;
  }
  struct Point tmpPoint = nextPoint(point, direction);
  if (queryMap(tmpPoint) != !player) {
    return false;
  }
  return is_CanGo2(player, tmpPoint, direction);
}

bool is_CanGo2(int player, struct Point point, struct Direction direction) {
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

struct Point nextPoint(struct Point point, struct Direction direction) {
  struct Point ret = {point.x + direction.x, point.y + direction.y};
  return ret;
}

int queryMap(struct Point point) {
  unsigned int x = point.x, y = point.y;
  if (x <= 9 && y <= 9) {
    return MapManager_Map[x][y];
  } else {
    printf("this code should never be reached: means the query is out of map");
    return -1;
  }
}
