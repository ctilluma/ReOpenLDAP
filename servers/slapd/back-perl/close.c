/* $ReOpenLDAP$ */
/* Copyright 1999-2017 ReOpenLDAP AUTHORS: please see AUTHORS file.
 * All rights reserved.
 *
 * This file is part of ReOpenLDAP.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted only as authorized by the OpenLDAP
 * Public License.
 *
 * A copy of this license is available in the file LICENSE in the
 * top-level directory of the distribution or, alternatively, at
 * <http://www.OpenLDAP.org/license.html>.
 */

#include "perl_back.h"
#include "slapconfig.h"
/**********************************************************
 *
 * Close
 *
 **********************************************************/

int
perl_back_close(
	BackendInfo *bd
)
{
	perl_destruct(PERL_INTERPRETER);
	perl_free(PERL_INTERPRETER);
	PERL_INTERPRETER = NULL;
#ifdef PERL_SYS_TERM
	PERL_SYS_TERM();
#endif

	ldap_pvt_thread_mutex_destroy( &perl_interpreter_mutex );

	return 0;
}

int
perl_back_db_destroy(
	BackendDB *be,
	ConfigReply *cr
)
{
	PerlBackend *pb = be->be_private;

	ch_free( pb->pb_module_name );
	ber_bvarray_free( pb->pb_module_path );
	ber_bvarray_free( pb->pb_module_config );

	free( be->be_private );
	be->be_private = NULL;

	return 0;
}
