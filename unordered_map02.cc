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
#include <map>

typedef std::pair<float,float> fpair;

template <>
class std::hash<std::pair<float,float>> {
public:
        size_t operator()(std::pair<float,float> x) const throw() {
             size_t h1 = std::hash<float>()(x.first);
             size_t h2 = std::hash<float>()(x.second);
             return h1 ^ (h2<<1);
        }
};
 
int main()
{
	
  std::unordered_map<fpair,fpair> m({  
    { fpair(1.1, 1.2), fpair( 1.3, 1.4) },
    { fpair(2.1, 2.2), fpair( 2.3, 2.4) },
  });
  
  for (auto i : m) std::cout << i.first.first << ' ';
  std::cout << std::endl;
}
