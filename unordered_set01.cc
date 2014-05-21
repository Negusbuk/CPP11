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
#include <string>
#include <unordered_set>

int main()
{
  std::unordered_set<int> us1({ 1,2,3,4,5,6,4,5,6,3,4,5 });
  for (auto i : us1) std::cout << i << ' ';
  std::cout << std::endl;
  std::cout << "count: " << us1.count(4) << std::endl;
  auto iter1 = us1.equal_range(4);
  for (auto i = iter1.first;i!=iter1.second;++i) std::cout << *i << ' ';
  std::cout << std::endl;

  std::cout << std::endl;

  std::unordered_multiset<int> us2({ 1,2,3,4,5,6,4,5,6,3,4,5 });
  for (auto i : us2) std::cout << i << ' ';
  std::cout << std::endl;
  std::cout << "count: " << us2.count(4) << std::endl;
  auto iter2 = us2.equal_range(4);
  for (auto i = iter2.first;i!=iter2.second;++i) std::cout << *i << ' ';
  std::cout << std::endl;
}
