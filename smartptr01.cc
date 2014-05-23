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

#include "smartptrtestclass.h"

int main()
{
  {
    std::unique_ptr<SmartPtrTestClass> p(new SmartPtrTestClass());
    std::cout << "p: " << p.get() << std::endl;
    p->func();
  }
  std::cout << std::endl;

  {
    std::unique_ptr<SmartPtrTestClass> p1(new SmartPtrTestClass());
    std::cout << "p1: "<< p1.get() << std::endl;
    p1->func();

    std::unique_ptr<SmartPtrTestClass> p2 = std::move(p1);
    std::cout << "p1: "<< p1.get() << std::endl;
    std::cout << "p2: "<< p2.get() << std::endl;
    p2->func();
  }
  std::cout << std::endl;

  {
    SmartPtrTestClass sptc;
    std::unique_ptr<SmartPtrTestClass> p(&sptc); // crash due to double delete
    std::cout << "p: "<< p.get() << std::endl;
  }
}
