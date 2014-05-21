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
  std::unordered_map<int,std::string> um1({
    { 1, "a"},
    { 2, "b"},
    { 3, "c"},
    { 4, "d"},
    { 5, "e"},
    { 6, "f"},
    { 4, "d"},
    { 5, "e"},
    { 6, "f"},
    { 3, "c"},
    { 4, "d"},
    { 5, "e"},
  });
  for (auto i : um1) std::cout << i.first << ' ';
  std::cout << std::endl;
  for (auto i : um1) std::cout << i.second << ' ';
  std::cout << std::endl;
  std::cout << "count: " << um1.count(4) << std::endl;
  auto iter1 = um1.equal_range(4);
  for (auto i = iter1.first;i!=iter1.second;++i) std::cout << i->first << ' ';
  std::cout << std::endl;
  for (auto i = iter1.first;i!=iter1.second;++i) std::cout << i->second << ' ';
  std::cout << std::endl;

  std::cout << std::endl;

  std::unordered_multimap<int,std::string> um2({
    { 1, "a"},
    { 2, "b"},
    { 3, "c"},
    { 4, "d"},
    { 5, "e"},
    { 6, "f"},
    { 4, "d"},
    { 5, "e"},
    { 6, "f"},
    { 3, "c"},
    { 4, "d"},
    { 5, "e"},
  });
  for (auto i : um2) std::cout << i.first << ' ';
  std::cout << std::endl;
  std::cout << "count: " << um2.count(4) << std::endl;
  auto iter2 = um2.equal_range(4);
  for (auto i = iter2.first;i!=iter2.second;++i) std::cout << i->first << ' ';
  std::cout << std::endl;
  for (auto i = iter2.first;i!=iter2.second;++i) std::cout << i->second << ' ';
  std::cout << std::endl;

}
