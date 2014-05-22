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
#include <unordered_map>

int main()
{
  // fill map with values
  std::unordered_map<int,std::string> um({
    { 1, "a" },
    { 2, "b" },
    { 3, "c" },
    { 4, "d" },
    { 5, "e" },
    { 6, "f" },
    { 4, "d" },
    { 5, "e" },
    { 6, "f" },
    { 3, "c" },
    { 4, "d" },
    { 5, "e" },
  });
  
  // dump content of set to screen
  for (auto i : um) std::cout << i.first << ' ';
  std::cout << std::endl;
  for (auto i : um) std::cout << i.second << ' ';
  std::cout << std::endl;
  
  // returns 0 or 1 depending on wether key is found
  std::cout << "count of 1: " << um.count(1) << std::endl;
  std::cout << "count of 2: " << um.count(2) << std::endl;
  std::cout << "count of 3: " << um.count(3) << std::endl;
  std::cout << "count of 4: " << um.count(4) << std::endl;
  std::cout << "count of 5: " << um.count(5) << std::endl;
  std::cout << "count of 6: " << um.count(6) << std::endl;
  std::cout << "count of 7: " << um.count(7) << std::endl;

  // returns the bounds of a range that includes all the elements for a given key
  auto it = um.equal_range(4);
  for (auto i=it.first;i!=it.second;++i) {
    std::cout << i->first << " ";
  }
  std::cout << std::endl;
  for (auto i=it.first;i!=it.second;++i) {
    std::cout << i->second << " ";
  }
  std::cout << std::endl;
}