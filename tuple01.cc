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
#include <tuple>
#include <stdexcept>

// utility function that returns tuples
std::tuple<std::string,int,int,int> makeColor(const std::string& name)
{
  if (name=="royal blue") return std::make_tuple("royal blue", 0x41, 0x69, 0xE1);
  if (name=="turquoise") return std::make_tuple("turquoise", 0x40, 0xE0, 0xD0);
  if (name=="lime") return std::make_tuple("lime", 0x00, 0xFF, 0x00);
  if (name=="sandy brown") return std::make_tuple("sandy brown", 0xF4, 0xA4, 0x60);
  throw std::invalid_argument("name");
}

int main()
{
  // get a tuple
  auto rb = makeColor("royal blue");

  // dump content of tuple to screen
  std::cout << "name:  " << std::get<0>(rb) << "\n"
            << "red:   " << std::get<1>(rb) << "\n"
            << "green: " << std::get<2>(rb) << "\n"
            << "blue:  " << std::get<3>(rb) << "\n" << std::endl;
  
  // get another tuple
  auto turquoise = makeColor("turquoise");

  // create local variables based on declaration types of tuple
  std::tuple_element<0,decltype(turquoise)>::type name;
  std::tuple_element<1,decltype(turquoise)>::type red;
  std::tuple_element<2,decltype(turquoise)>::type green;

  // create standard local variable
  int blue;

  // tie contents of tuple to local variables
  std::tie(name, red, green, blue) = turquoise;

  // dump content of tuple to screen
  std::cout << "name:  " << name << "\n"
            << "red:   " << red << "\n"
            << "green: " << green << "\n"
            << "blue:  " << blue << std::endl;
}
