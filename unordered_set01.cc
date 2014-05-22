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
#include <unordered_set>

int main()
{
  // fill set with values
  std::unordered_set<int> us({ 1,2,3,4,5,6,5,4,3,2,1 });
  
  // dump content of set to screen
  for (auto i : us) std::cout << i << ' ';
  std::cout << std::endl;
  
  // returns 0 or 1 depending on wether key is found
  std::cout << "count of 1: " << us.count(1) << std::endl;
  std::cout << "count of 2: " << us.count(2) << std::endl;
  std::cout << "count of 3: " << us.count(3) << std::endl;
  std::cout << "count of 4: " << us.count(4) << std::endl;
  std::cout << "count of 5: " << us.count(5) << std::endl;
  std::cout << "count of 6: " << us.count(6) << std::endl;
  std::cout << "count of 7: " << us.count(7) << std::endl;
  
  // returns the bounds of a range that includes all the elements for a given key
  auto it = us.equal_range(4);
  while (it.first!=it.second) std::cout << *it.first++ << ' ';
  std::cout << std::endl;
}
