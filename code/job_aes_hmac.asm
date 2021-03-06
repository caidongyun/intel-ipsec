;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Copyright (c) 2015, Intel Corporation 
; 
; All rights reserved. 
; 
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions are
; met: 
; 
; * Redistributions of source code must retain the above copyright
;   notice, this list of conditions and the following disclaimer.  
; 
; * Redistributions in binary form must reproduce the above copyright
;   notice, this list of conditions and the following disclaimer in the
;   documentation and/or other materials provided with the
;   distribution. 
; 
; * Neither the name of the Intel Corporation nor the names of its
;   contributors may be used to endorse or promote products derived from
;   this software without specific prior written permission. 
; 
; 
; THIS SOFTWARE IS PROVIDED BY INTEL CORPORATION ""AS IS"" AND ANY
; EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
; IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
; PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL INTEL CORPORATION OR
; CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
; EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
; PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
; PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
; LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
; NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
; SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

%include "datastruct.asm"

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;; Define constants
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

%define STS_BEING_PROCESSED	0
%define STS_COMPLETED_AES	1
%define STS_COMPLETED_HMAC	2
%define STS_COMPLETED		3
%define STS_INVALID_ARGS	4

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;; Define JOB_AES_HMAC structure
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

START_FIELDS	; HMAC Specific Fields
;;;	name				size	align
FIELD	__auth_key_xor_ipad,		8,	8	; pointer to ipad
FIELD	__auth_key_xor_opad,		8,	8	; pointer to opad
END_FIELDS

%assign _HMAC_spec_fields_size	_FIELD_OFFSET
%assign _HMAC_spec_fields_align	_STRUCT_ALIGN

START_FIELDS	; AES XCBC Specific Fields
;;;	name				size	align
FIELD	__k1_expanded,			8,	8	; ptr to exp k1 keys
FIELD	__k2,				8,	8	; ptr to k2
FIELD	__k3,				8,	8	; ptr to k3
END_FIELDS

%assign _AES_XCBC_spec_fields_size	_FIELD_OFFSET
%assign _AES_XCBC_spec_fields_align	_STRUCT_ALIGN

START_FIELDS	; JOB_AES_HMAC

;;;	name				size	align
FIELD	_aes_enc_key_expanded,		8,	8	; pointer to exp enc keys
FIELD	_aes_dec_key_expanded,		8,	8	; pointer to exp dec keys
FIELD	_aes_key_len_in_bytes,		8,	8
FIELD	_src,				8,	8	; pointer to src buffer
FIELD	_dst,				8,	8	; pointer to dst buffer
FIELD	_cipher_start_src_offset_in_bytes, \
					8,	8
FIELD	_msg_len_to_cipher_in_bytes,	8,	8
FIELD	_hash_start_src_offset_in_bytes,8,	8
FIELD	_msg_len_to_hash_in_bytes,	8,	8
FIELD	_iv,				8,	8	; pointer to IV
FIELD	_iv_len_in_bytes,		8,	8
FIELD	_auth_tag_output,		8,	8	; pointer to hash output
FIELD	_auth_tag_output_len_in_bytes,	8,	8

;FIELD	_aad,				8,	8	; pointer to AAD
;FIELD	_aad_len_in_bytes,		8,	8

UNION	_u,	_HMAC_spec_fields_size,     _HMAC_spec_fields_align, \
		_AES_XCBC_spec_fields_size, _AES_XCBC_spec_fields_align

FIELD	_status,			4,	4	; JOB_STS
FIELD	_cipher_mode,			4,	4	; JOB_CIPHER_MODE
FIELD	_cipher_direction,		4,	4	; JOB_CIPHER_DIRECTION
FIELD	_hash_alg,			4,	4	; JOB_HASH_ALG
FIELD	_chain_order,			4,	4	; JOB_CHAIN_ORDER
FIELD	_user_data,			8,	8
FIELD	_user_data2,			8,	8
END_FIELDS

%assign _JOB_AES_HMAC_size	_FIELD_OFFSET
%assign _JOB_AES_HMAC_align	_STRUCT_ALIGN

%assign _auth_key_xor_ipad	_u + __auth_key_xor_ipad
%assign _auth_key_xor_opad	_u + __auth_key_xor_opad
%assign _k1_expanded		_u + __k1_expanded
%assign _k2			_u + __k2
%assign _k3			_u + __k3

