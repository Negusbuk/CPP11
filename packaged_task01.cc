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

auto suffering(int n) -> int
{
  {
    std::lock_guard<std::mutex> lock(m);
    auto tp = system_clock::now();
    auto tp_c = system_clock::to_time_t(tp);
    std::cout << "start for  n=" << n << "\t"
              << std::put_time(std::localtime(&tp_c), "%T")
              << std::flush << std::endl;
  }

  auto sum = 0;
  for (int i=0;i<n;++i) {
    sum +=i;
    std::this_thread::sleep_for(microseconds(100));
  }
  
  {
    std::lock_guard<std::mutex> lock(m);

    std::cout << "result for n=" << n << "\t" << sum << std::endl;

    auto tp = system_clock::now();
    auto tp_c = system_clock::to_time_t(tp);
    std::cout << "end for    n=" << n << "\t"
              << std::put_time(std::localtime(&tp_c), "%T")
              << std::flush << std::endl;
  }
            
  return sum;
}

int main()
{
  auto inflictPainA = std::bind(suffering, 40000);
  auto inflictPainB = std::bind(suffering, 20000);

  {
    std::cout << "test 1:" << std::endl;
    
    std::packaged_task<int()> pta(inflictPainA);
    std::future<int> a = pta.get_future();
    std::thread ta(std::move(pta));

    std::packaged_task<int()> ptb(inflictPainB);
    std::future<int> b = ptb.get_future();
    std::thread tb(std::move(ptb));
  
    ta.join();
    tb.join();
  
    a.get();
    b.get();
    
    std::cout << std::endl;
  }
  
  {
    std::cout << "test 2:" << std::endl;

    std::packaged_task<int()> pta(inflictPainA);
    std::future<int> a = pta.get_future();

    std::packaged_task<int()> ptb(inflictPainB);
    std::future<int> b = ptb.get_future();
  
    pta();
    ptb();
  
    a.get();
    b.get();

    std::cout << std::endl;
  }

}