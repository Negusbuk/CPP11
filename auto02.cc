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
#include <cmath>
#include <typeinfo>

template<class T, class U>
auto add(T t, U u) -> decltype(t + u) // the return type of add is the type of operator+(T,U)
{
  return t + u;
}

auto get_fun(int arg)->double(*)(double) // same as double (*get_fun(int))(double)
{
  switch (arg) {
  case 1: return std::fabs;
  case 2: return std::sin;
  default: return std::cos;
  }
}

int main()
{
  auto a = 1 + 2;
  std::cout << "type of a: " << typeid(a).name() << '\n';
  auto b = add(1, 1.2);
  std::cout << "type of b: " << typeid(b).name() << '\n';
  //auto int c; //compile-time error
  auto d = {1, 2};
  std::cout << "type of d: " << typeid(d).name() << '\n';

  auto my_lambda = [](int x) { return x + 3; };
  std::cout << "my_lambda: " << my_lambda(5) << '\n';

  auto my_fun = get_fun(2);
  std::cout << "type of my_fun: " << typeid(my_fun).name() << '\n';
  std::cout << "my_fun: " << my_fun(3) << '\n';
}
