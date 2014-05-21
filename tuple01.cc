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

#include <tuple>
#include <iostream>
#include <string>
#include <stdexcept>

std::tuple<double, char, std::string> getStudent(int id)
{
  if (id == 0) return std::make_tuple(3.8, 'A', "Lisa Simpson");
  if (id == 1) return std::make_tuple(2.9, 'C', "Milhouse Van Houten");
  if (id == 2) return std::make_tuple(1.7, 'D', "Ralph Wiggum");
  throw std::invalid_argument("id");
}

int main()
{
  auto student0 = getStudent(0);
  std::cout << "ID: 0, "
      << "GPA: " << std::get<0>(student0) << ", "
      << "grade: " << std::get<1>(student0) << ", "
      << "name: " << std::get<2>(student0) << '\n';
  
  auto student1 = getStudent(1);
  double gpa1;
  char grade1;
  std::tuple_element<2,decltype(student1)>::type name1;
  std::tie(gpa1, grade1, name1) = getStudent(1);
  std::cout << "ID: 1, "
      << "GPA: " << gpa1 << ", "
      << "grade: " << grade1 << ", "
      << "name: " << name1 << '\n';
}
