// Copyright (c) 2025 Mikko Kuha (University of Jyväskylä).
// This program is free software: you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details. You should have received a copy
// of the GNU General Public License along with this program. If not, see
// <http://www.gnu.org/licenses/>.

#ifndef LOG_INTERPOLATOR_H
#define LOG_INTERPOLATOR_H

#include <iostream>
#include <vector>

class log_interpolator
{
public:
    log_interpolator(){ratio = 1;};
    log_interpolator(std::vector<double> xs_, std::vector<double> ys_) noexcept : xs(std::move(xs_)), ys(std::move(ys_))
    {
        if (xs[0] <= 0)
        {
            std::cout << "LOGARITHMIC INTERPOLATOR INITIALIZED OUT OF BOUNDS" << std::endl;
            ratio = 1;
        }
        else ratio = xs[1]/xs[0];
    }
    
    /// @param mode Defines the axis scales (x/y). 0 = linear / linear, 1 = logarithmic / linear, 2 = logarithmic / logarithmic
    auto value_at(const double x, int mode = 2) const noexcept -> double;


    log_interpolator &operator=(const log_interpolator &rhs)
    {
        this->xs = rhs.xs;
        this->ys = rhs.ys;
        this->ratio = rhs.ratio;
        return *this;
    }

protected:
private:
    std::vector<double> xs;
    std::vector<double> ys;
    double ratio;
};

#endif // LOG_INTERPOLATOR_H
