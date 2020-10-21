#include "Baseline.h"

//保证在调用时它有子可下
void Baseline_Go(const int player, const int map[12][12], const int cangolist[64][2], const int listlength, int ret[2])
{
    ret[0] = cangolist[0][0];
    ret[1] = cangolist[0][1];
}
