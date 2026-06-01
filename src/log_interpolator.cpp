// Copyright (c) 2025 Mikko Kuha (University of Jyväskylä).
// This program is free software: you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details. You should have received a copy
// of the GNU General Public License along with this program. If not, see
// <http://www.gnu.org/licenses/>.

#include <cmath>
#include "log_interpolator.hpp"

auto log_interpolator::value_at(const double x, int mode) const noexcept -> double
{
    if (x >= this->xs.back())
    {
        return this->ys.back();
    }

    double power = log(x/xs[0]) / log(ratio);
    int nearest_smaller_exponent = std::max(static_cast<int>(power), 0);

    switch(mode)
    {
        case 0: return (this->ys[nearest_smaller_exponent] * (this->xs[nearest_smaller_exponent+1] - x) + this->ys[nearest_smaller_exponent+1] * (x - this->xs[nearest_smaller_exponent])) / (this->xs[nearest_smaller_exponent+1] - this->xs[nearest_smaller_exponent]);
        case 1: return this->ys[nearest_smaller_exponent+1]*(power-nearest_smaller_exponent) + this->ys[nearest_smaller_exponent]*(nearest_smaller_exponent+1-power);
        case 2: return pow(this->ys[nearest_smaller_exponent+1],(power-nearest_smaller_exponent)) * pow(this->ys[nearest_smaller_exponent],(nearest_smaller_exponent+1-power));
        default: return 0;
    }
}

