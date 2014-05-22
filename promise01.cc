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
#include <chrono>
#include <thread>
#include <future>
#include <iomanip>

using namespace std::chrono;

std::mutex m;

class suffering
{
  std::promise<int> promise_;
  std::thread thread_;
  int count_;

  void run() { 
    {
      std::lock_guard<std::mutex> lock(m);
      auto tp = system_clock::now();
      auto tp_c = system_clock::to_time_t(tp);
      std::cout << "start for  n=" << count_ << "\t"
                << std::put_time(std::localtime(&tp_c), "%T")
                << std::flush << std::endl;
    }

    auto sum = 0;
    for (int i=0;i<count_;++i) {
      sum +=i;
      std::this_thread::sleep_for(microseconds(100));
    }

    {
      std::lock_guard<std::mutex> lock(m);

      std::cout << "result for n=" << count_ << "\t" << sum << std::endl;

      auto tp = system_clock::now();
      auto tp_c = system_clock::to_time_t(tp);
      std::cout << "end for    n=" << count_ << "\t"
                << std::put_time(std::localtime(&tp_c), "%T")
                << std::flush << std::endl;
    }

    promise_.set_value(sum);
  }
  
public:
  
  suffering(int n) :
    count_(n),
    thread_(&suffering::run, this) {
    thread_.detach();
  }
  
  std::future<int> get_future() {
    return promise_.get_future();
  }
};

int main()
{
  suffering inflictPainA(40000);
  std::future<int> a = inflictPainA.get_future();

  suffering inflictPainB(20000);
  std::future<int> b = inflictPainB.get_future();
  
  a.get();
  b.get();
}
