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
#include <vector>
#include <thread>

class Counter {
  int count_;
public:
  Counter() : count_(0) {}

  void increment() {
    ++count_;
  }

  int value() const {
    return count_;
  }
};

int main()
{
  Counter counter;

  std::vector<std::thread> threads;

  for (int i=0;i<10;++i) {
    threads.push_back(std::thread([&counter](){
      for (int i=0;i<10000;++i) {
        counter.increment();
      }
    }));
  }

  for (auto& thread : threads) {
    thread.join();
  }

  std::cout << counter.value() << std::endl;

  return 0;
}
