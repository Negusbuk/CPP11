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

void f(std::weak_ptr<SmartPtrTestClass>& wp)
{
  auto sp = wp.lock(); // sp is a std::shared_ptr<SmartPtrTestClass>

  if (sp) {
    sp->func();
  } else {
    std::cout << "object expired" << std::endl;
  }
}

int main()
{
  std::weak_ptr<SmartPtrTestClass> wp;

  {
    std::shared_ptr<SmartPtrTestClass> sp(new SmartPtrTestClass);
    wp = sp;

    f(wp);
  }

  f(wp);
}
