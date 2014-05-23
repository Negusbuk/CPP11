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
  std::vector<std::unique_ptr<SmartPtrTestClass>> v;

  v.push_back(std::unique_ptr<SmartPtrTestClass>(new SmartPtrTestClass));
  v.push_back(std::unique_ptr<SmartPtrTestClass>(new SmartPtrTestClass));

  std::cout << "v[0]: " << v[0].get() << std::endl;
  v[0]->func();
  std::cout << "v[1]: " << v[1].get() << std::endl;
  v[1]->func();
  std::cout << std::endl;

  v[0].swap(v[1]);
  std::cout << "v[0]: " << v[0].get() << std::endl;
  v[0]->func();
  std::cout << "v[1]: " << v[1].get() << std::endl;
  v[1]->func();
  std::cout << std::endl;
  std::swap(v[0], v[1]);

  v[0] = std::move(v[1]);
  std::cout << "v[0]: " << v[0].get() << std::endl;
  std::cout << "v[1]: " << v[1].get() << std::endl;
  v[0]->func();
  std::cout << std::endl;

  std::unique_ptr<SmartPtrTestClass> p = std::move(v[0]);
  std::cout << "v[0]: " << v[0].get() << std::endl;
  std::cout << "v[1]: " << v[1].get() << std::endl;
  std::cout << "p:    " << p.get() << std::endl;
  p->func();
}
