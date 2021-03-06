/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "assign.h"

bool_t
xdr_ques (XDR *xdrs, ques *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->q_id))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->ques, 200,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_ans (XDR *xdrs, ans *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->q_id))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->c_id))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->ans, 30,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_board (XDR *xdrs, board *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, (1 +  10  + 10 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->id, 10,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->score, 10,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->size))
				 return FALSE;
		} else {
			{
				register int *genp;

				for (i = 0, genp = objp->id;
					i < 10; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
			{
				register int *genp;

				for (i = 0, genp = objp->score;
					i < 10; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
			IXDR_PUT_LONG(buf, objp->size);
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, (1 +  10  + 10 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->id, 10,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->score, 10,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->size))
				 return FALSE;
		} else {
			{
				register int *genp;

				for (i = 0, genp = objp->id;
					i < 10; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
			{
				register int *genp;

				for (i = 0, genp = objp->score;
					i < 10; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
			objp->size = IXDR_GET_LONG(buf);
		}
	 return TRUE;
	}

	 if (!xdr_vector (xdrs, (char *)objp->id, 10,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->score, 10,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->size))
		 return FALSE;
	return TRUE;
}
