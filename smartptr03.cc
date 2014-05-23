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

#include <memory>
#include <iostream>
#include <vector>

#include "smartptrtestclass.h"

int main()
{
  std::shared_ptr<SmartPtrTestClass> p1(new SmartPtrTestClass);

  {
    std::vector<std::shared_ptr<SmartPtrTestClass>> v;

    std::shared_ptr<SmartPtrTestClass> p2(new SmartPtrTestClass);

    std::cout << "p1: " << p1.get() << " " << p1.use_count() << std::endl;
    std::cout << "p1: " << p2.get() << " " << p2.use_count() << std::endl;
    std::cout << std::endl;

    v.push_back(p1);
    std::cout << "p1: " << p1.get() << " " << p1.use_count() << std::endl;
    std::cout << "p1: " << p2.get() << " " << p2.use_count() << std::endl;
    std::cout << std::endl;

    v.push_back(p2);
    std::cout << "p1: " << p1.get() << " " << p1.use_count() << std::endl;
    std::cout << "p1: " << p2.get() << " " << p2.use_count() << std::endl;
    std::cout << std::endl;

    v.push_back(p1);
    std::cout << "p1: " << p1.get() << " " << p1.use_count() << std::endl;
    std::cout << "p1: " << p2.get() << " " << p2.use_count() << std::endl;
    std::cout << std::endl;
  }

  std::cout << "p1: " << p1.get() << " " << p1.use_count() << std::endl;
}
