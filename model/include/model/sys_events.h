/**************************************************************************
 *   Copyright (C) 2024 Alec Leamas                                        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
 **************************************************************************/

/**
 * \file
 *  Suspend/resume and new devices events exchange point
 */

#ifndef SYS__EVENTS_H_
#define SYS__EVENTS_H_
#include "observable_evtvar.h"

class SystemEvents {
public:
  static SystemEvents& GetInstance() {
    static SystemEvents instance;
    return instance;
  }

  SystemEvents(SystemEvents&) = delete;
  SystemEvents& operator=(SystemEvents&) = delete;

  /** Notified when resuming from hibernate. */
  EventVar evt_resume;

  /**
   * Notified when a new or removed device is detected, usually an USB
   * hotplug event:
   */
  EventVar evt_dev_change;

private:
  SystemEvents() = default;
};

#endif  // define SYS__EVENTS_H_
