/*
 * Copyright (c) 2017-2018, Linaro Limited
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef __PKCS11_PROCESSING_H
#define __PKCS11_PROCESSING_H

#include <pkcs11.h>

CK_RV ck_create_object(CK_SESSION_HANDLE session,
			CK_ATTRIBUTE_PTR attribs,
			CK_ULONG count,
			CK_OBJECT_HANDLE_PTR phObject);

CK_RV ck_destroy_object(CK_SESSION_HANDLE session,
			CK_OBJECT_HANDLE obj);

CK_RV ck_encdecrypt_init(CK_SESSION_HANDLE session,
			 CK_MECHANISM_PTR mechanism,
			 CK_OBJECT_HANDLE key,
			 int decrypt);

CK_RV ck_encdecrypt_update(CK_SESSION_HANDLE session,
			   CK_BYTE_PTR in,
			   CK_ULONG in_len,
			   CK_BYTE_PTR out,
			   CK_ULONG_PTR out_len,
			   int decrypt);

CK_RV ck_encdecrypt_oneshot(CK_SESSION_HANDLE session,
			    CK_BYTE_PTR in,
			    CK_ULONG in_len,
			    CK_BYTE_PTR out,
			    CK_ULONG_PTR out_len,
			    int decrypt);

CK_RV ck_encdecrypt_final(CK_SESSION_HANDLE session,
			  CK_BYTE_PTR out,
			  CK_ULONG_PTR out_len,
			  int decrypt);

CK_RV ck_generate_key(CK_SESSION_HANDLE session,
		      CK_MECHANISM_PTR mechanism,
		      CK_ATTRIBUTE_PTR attribs,
		      CK_ULONG count,
		      CK_OBJECT_HANDLE_PTR handle);

CK_RV ck_signverify_init(CK_SESSION_HANDLE session,
			 CK_MECHANISM_PTR mechanism,
			 CK_OBJECT_HANDLE key,
			 int sign);

CK_RV ck_signverify_update(CK_SESSION_HANDLE session,
			   CK_BYTE_PTR in,
			   CK_ULONG in_len,
			   int sign);

CK_RV ck_signverify_oneshot(CK_SESSION_HANDLE session,
			    CK_BYTE_PTR in,
			    CK_ULONG in_len,
			    CK_BYTE_PTR out,
			    CK_ULONG_PTR out_len,
			    int sign);

CK_RV ck_signverify_final(CK_SESSION_HANDLE session,
			  CK_BYTE_PTR out,
			  CK_ULONG_PTR out_len,
			  int sign);

CK_RV ck_find_objects_init(CK_SESSION_HANDLE session,
			   CK_ATTRIBUTE_PTR attribs,
			   CK_ULONG count);

CK_RV ck_find_objects(CK_SESSION_HANDLE session,
			CK_OBJECT_HANDLE_PTR obj,
			CK_ULONG max_count,
			CK_ULONG_PTR count);

CK_RV ck_find_objects_final(CK_SESSION_HANDLE session);

CK_RV ck_generate_key_pair(CK_SESSION_HANDLE session,
			   CK_MECHANISM_PTR mechanism,
			   CK_ATTRIBUTE_PTR pub_attribs,
			   CK_ULONG pub_count,
			   CK_ATTRIBUTE_PTR priv_attribs,
			   CK_ULONG priv_count,
			   CK_OBJECT_HANDLE_PTR pub_key,
			   CK_OBJECT_HANDLE_PTR priv_key);

CK_RV ck_derive_key(CK_SESSION_HANDLE session,
		    CK_MECHANISM_PTR mechanism,
		    CK_OBJECT_HANDLE parent_handle,
		    CK_ATTRIBUTE_PTR attribs,
		    CK_ULONG count,
		    CK_OBJECT_HANDLE_PTR key_handle);

CK_RV ck_get_object_size(CK_SESSION_HANDLE session,
			 CK_OBJECT_HANDLE obj,
			 CK_ULONG_PTR out_size);

CK_RV ck_get_attribute_value(CK_SESSION_HANDLE session,
			     CK_OBJECT_HANDLE obj,
			     CK_ATTRIBUTE_PTR attribs,
			     CK_ULONG count);

#endif /*__PKCS11_PROCESSING_H*/
