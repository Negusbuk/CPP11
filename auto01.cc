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
#include <typeinfo>

class A {
public:
  A() {}
};

int main()
{
  auto a = 1 + 2;
  std::cout << "type of a: " << typeid(a).name() << '\n';
  auto b = 1.0 + 2;
  std::cout << "type of b: " << typeid(b).name() << '\n';

  auto c = new A();
  std::cout << "type of c: " << typeid(c).name() << '\n';
  auto d = *c;
  std::cout << "type of d: " << typeid(d).name() << '\n';
  auto e = &d;
  std::cout << "type of e: " << typeid(e).name() << '\n';
}
