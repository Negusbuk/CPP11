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
#include <thread>

auto A() -> int {
  int sum = 0;
  for (int i=0;i<1000000;++i) {
    sum +=i;
  }
  std::cout << "A " << sum << std::endl;
  return sum;
}

auto B() -> int {
  int sum = 0;
  for (int j=0;j<10000;++j) {
    sum +=j;
  }
  std::cout << "B " << sum << std::endl;
  return sum;
}

int main()
{
  std::promise<int> pa;
  std::future<int> a = pa.get_future();
  std::thread ta([](std::promise<int>& p){ p.set_value(A()); },
                 std::ref(pa));

  std::promise<int> pb;
  std::future<int> b = pb.get_future();
  std::thread tb([](std::promise<int>& p){ p.set_value(B()); },
                 std::ref(pb));

  a.wait();
  b.wait();

  std::cout << a.get() << " " << b.get() << std::endl;
  ta.join();
  tb.join();
}
