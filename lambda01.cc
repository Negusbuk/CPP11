/*******************************************************************************
 *  
 *  Copyright (C) 2013 Andreas Mussgiller
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *  
 *******************************************************************************/

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <functional>

std::function<double (double)> func_;

int main()
{
  auto printVector = [] (const std::vector<int>& v) {
    for (auto i : v) { std::cout << i << " "; }
    std::cout << std::endl;
  };

  std::vector<int> v { 0,1,2,3,4,5,6,7,8,9 };
  printVector(v);

  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(v.begin(), v.end(), g);
  printVector(v);

  int max = 0;
  std::for_each(v.begin(), v.end(), [&max](int& n) { if (n>max) max = n; });
  std::cout << max << std::endl;

  std::sort(v.begin(), v.end(), [](int& n1, int& n2) { return (n1<n2); });
  printVector(v);
}
