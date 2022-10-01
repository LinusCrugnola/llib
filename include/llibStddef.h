#pragma once
#define _NODISC [[nodiscard]]
#define _QUAS_0 0.00000001
#define _PRECISION 100000000

namespace llib{
constexpr inline double preciseE8(const double x){
    return int(x * _PRECISION) / _PRECISION;
}
}