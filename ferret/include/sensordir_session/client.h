/*
 * \brief  Client-side interface of the Hello service
 * \author Björn Döbel
 * \date   2008-03-20
 */

/*
 * Copyright (C) 2008-2013 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

#ifndef _INCLUDE__HELLO_SESSION_H__CLIENT_H_
#define _INCLUDE__HELLO_SESSION_H__CLIENT_H_

#include <sensordir_session/sensordir_session.h>
#include <base/rpc_client.h>
#include <base/printf.h>
#include <stdint.h>

namespace Ferret {

	struct Session_client : Genode::Rpc_client<Session>
	{
		Session_client(Genode::Capability<Session> cap)
		: Genode::Rpc_client<Session>(cap) { }
		Genode::Dataspace_capability create(uint16_t typ)
		{
			return call<Rpc_create>(typ);
		}
		Genode::Dataspace_capability lookup(uint16_t maj,  uint16_t min,  uint16_t inst)
		{
			return call<Rpc_lookup>(maj, min, inst);
		}
	};
}

#endif /* _INCLUDE__HELLO_SESSION_H__CLIENT_H_ */
