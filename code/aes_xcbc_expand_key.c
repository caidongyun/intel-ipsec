/**********************************************************************
Copyright (c) 2015, Intel Corporation 

All rights reserved. 

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met: 

* Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.  

* Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the
  distribution. 

* Neither the name of the Intel Corporation nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission. 


THIS SOFTWARE IS PROVIDED BY INTEL CORPORATION ""AS IS"" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL INTEL CORPORATION OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**********************************************************************/

#include <stdio.h>
#include "types.h"
#include "aux_funcs.h"
#include "os.h"

void aes_keyexp_128_enc_sse(void *key, void *enc_exp_keys);
void aes_keyexp_128_enc_avx(void *key, void *enc_exp_keys);

void aes128_ecbenc_x3_sse(void *in, void *keys, void *out1, void *out2, void *out3);
void aes128_ecbenc_x3_avx(void *in, void *keys, void *out1, void *out2, void *out3);

static UINT32 in[4*3] = {
    0x01010101, 0x01010101, 0x01010101, 0x01010101, 
    0x02020202, 0x02020202, 0x02020202, 0x02020202, 
    0x03030303, 0x03030303, 0x03030303, 0x03030303
};

void 
aes_xcbc_expand_key_sse(void *key, void *k1_exp, void *k2, void *k3)
{
    DECLARE_ALIGNED(UINT32 keys_exp_enc[11*4], 16);

    aes_keyexp_128_enc_sse(key, keys_exp_enc);

    aes128_ecbenc_x3_sse(in, keys_exp_enc, k1_exp, k2, k3);

    aes_keyexp_128_enc_sse(k1_exp, k1_exp);
}

void 
aes_xcbc_expand_key_avx(void *key, void *k1_exp, void *k2, void *k3)
{
    DECLARE_ALIGNED(UINT32 keys_exp_enc[11*4], 16);

    aes_keyexp_128_enc_avx(key, keys_exp_enc);

    aes128_ecbenc_x3_avx(in, keys_exp_enc, k1_exp, k2, k3);

    aes_keyexp_128_enc_avx(k1_exp, k1_exp);
}
