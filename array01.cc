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

#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>

int main()
{
  std::array<int, 3> a1{ {1, 2, 3} };
  std::array<int, 3> a2 = {1, 2, 3};
  
  std::array<std::string, 2> a3{ {std::string("a"), "b"} };
  std::array<std::string, 2> a4 = {std::string("a"), "b"};

  std::sort(a1.begin(), a1.end());
  std::reverse_copy(a2.begin(), a2.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  for(auto& s: a3) {
    std::cout << s << ' ';
  }
  std::cout << std::endl;
}
