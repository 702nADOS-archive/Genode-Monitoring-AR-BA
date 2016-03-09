/**
 * \file   ferret/lib/monitor/monitor.cc
 * \brief  Functions to access sensors from monitors.
 *
 * \date   10/03/2009
 * \author Martin Pohlack <mp26@os.inf.tu-dresden.de>
 * \author Bjoern Doebel <doebel@tudos.org>
 */
/*
 * (c) 2009 Technische Universität Dresden
 * This file is part of TUD:OS and distributed under the terms of the
 * GNU General Public License 2.
 * Please see the COPYING-GPL-2 file for details.
 */
//#include <types.h>

#include <monitor.h>
#include <monitor_list.h>
#include <sensordir.h>

#include <sensors/common.h>

#include <dataspace/client.h>
#include <sensors/scalar.h>
#include <sensordir_session/client.h>
#include <sensordir_session/connection.h>

Ferret::Connection f;

int ferret_attach(uint16_t major, uint16_t minor,
                  uint16_t instance, void ** addr)
{
	Genode::Dataspace_capability dir_cap = f.lookup(major, minor, instance);

	*addr = Genode::env()->rm_session()->attach(dir_cap);

	return 0;
}

/*int ferret_detach(uint16_t major, uint16_t minor,
                  uint16_t instance, void ** addr)
{
	Ferret::Connection f;
	
	return 0;
}*/
