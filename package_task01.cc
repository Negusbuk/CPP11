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
  std::packaged_task<int()> ta([](){ return A(); });
  std::future<int> a = ta.get_future();
  std::thread(std::move(ta)).detach();

  std::packaged_task<int()> tb([](){ return B(); });
  std::future<int> b = tb.get_future();
  std::thread(std::move(tb)).detach();

  a.wait();
  b.wait();

  std::cout << a.get() << " " << b.get() << std::endl;
}
