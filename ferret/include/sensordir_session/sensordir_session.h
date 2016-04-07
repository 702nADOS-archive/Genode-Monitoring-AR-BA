/*
 * \brief  Interface definition of the Hello service
 * \author Björn Döbel
 * \date   2008-03-20
 */

/*
 * Copyright (C) 2008-2013 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

#ifndef _INCLUDE__HELLO_SESSION__HELLO_SESSION_H_
#define _INCLUDE__HELLO_SESSION__HELLO_SESSION_H_

#include <session/session.h>
#include <base/rpc.h>
#include <stdint.h>


namespace Ferret {

	struct Session : Genode::Session
	{
		static const char *service_name() { return "Sensordir"; }

		virtual Genode::Dataspace_capability create(uint16_t typ) = 0;
		virtual Genode::Dataspace_capability lookup(uint16_t maj,  uint16_t min,  uint16_t inst) = 0;


		/*******************
		 ** RPC interface **
		 *******************/

		GENODE_RPC(Rpc_create, Genode::Dataspace_capability, create, uint16_t);
		GENODE_RPC(Rpc_lookup, Genode::Dataspace_capability, lookup, uint16_t, uint16_t, uint16_t);
		GENODE_RPC_INTERFACE(Rpc_create, Rpc_lookup);
	};
}

#endif /* _INCLUDE__HELLO_SESSION__HELLO_SESSION_H_ */
