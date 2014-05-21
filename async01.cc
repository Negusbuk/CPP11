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
#include <future>

auto A() -> int {
  int sum = 0;
  for (int i=0;i<1000000;++i) {
    sum +=i;
  }
  std::cout << "(A " << sum << ")" << std::endl;
  return sum;
}

auto B() -> int {
  int sum = 0;
  for (int j=0;j<10000;++j) {
    sum +=j;
  }
  std::cout << "(B " << sum << ")" << std::endl;
  return sum;
}

int main()
{
  auto a1 = A();
  auto b1 = B();
  std::cout << "1: " << a1 << " " << b1 << std::endl;

  std::cout << std::endl;

  auto a2 = std::async(std::launch::async, A);
  auto b2 = std::async(std::launch::async, B);
  a2.wait();
  b2.wait();
  std::cout << "2: " << a2.get() << " " << b2.get() << std::endl;

  std::cout << std::endl;

  auto a3 = std::async(std::launch::async, A);
  auto b3 = std::async(std::launch::async, B);
  std::cout << "3: " << a3.get() << " " << b3.get() << std::endl;

  std::cout << std::endl;

  auto a4 = std::async(std::launch::async, A);
  auto b4 = std::async(std::launch::async, B);
  std::cout << "4: " << b4.get() << " " << a4.get() << std::endl;
}
