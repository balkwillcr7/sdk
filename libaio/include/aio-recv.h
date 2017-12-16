#ifndef _aio_recv_h_
#define _aio_recv_h_

#include "aio-socket.h"
#include "aio-timeout.h"

#if defined(__cplusplus)
extern "C" {
#endif

struct aio_recv_t
{
	struct aio_timeout_t timeout;
	union
	{
		aio_onrecv onrecv;
		aio_onrecvfrom onrecvfrom;
	} u;
	void* param;
};

/// @param[in] timeout send timeout in ms, <0-infinite
int aio_recv(struct aio_recv_t* recv, int timeout, aio_socket_t aio, void* buffer, size_t bytes, aio_onrecv onrecv, void* param);
int aio_recv_v(struct aio_recv_t* recv, int timeout, aio_socket_t aio, socket_bufvec_t* vec, int n, aio_onrecv onrecv, void* param);
int aio_recvfrom(struct aio_recv_t* recv, int timeout, aio_socket_t aio, void* buffer, size_t bytes, aio_onrecvfrom onrecv, void* param);
int aio_recvfrom_v(struct aio_recv_t* recv, int timeout, aio_socket_t aio, socket_bufvec_t* vec, int n, aio_onrecvfrom onrecv, void* param);

#if defined(__cplusplus)
}
#endif
#endif /* !_aio_recv_h_ */
