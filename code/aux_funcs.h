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

void sha1_one_block_sse(void *data, void *digest);
void sha224_one_block_sse(void *data, void *digest);
void sha256_one_block_sse(void *data, void *digest);
void sha384_one_block_sse(void *data, void *digest);
void sha512_one_block_sse(void *data, void *digest);
void md5_one_block_sse(void *data, void *digest);

void aes_keyexp_128_sse(void *key,
                        void *enc_exp_keys,
                        void *dec_exp_keys);

void aes_keyexp_192_sse(void *key,
                        void *enc_exp_keys,
                        void *dec_exp_keys);

void aes_keyexp_256_sse(void *key,
                        void *enc_exp_keys,
                        void *dec_exp_keys);


void aes_xcbc_expand_key_sse(void *key, 
                             void *k1_exp, 
                             void *k2, 
                             void *k3);

void aes_keyexp_128_enc_sse(void *key, void *enc_exp_keys);

////////////////////////////////////////////////////////////////////////


void sha1_one_block_avx(void *data, void *digest);
void sha224_one_block_avx(void *data, void *digest);
void sha256_one_block_avx(void *data, void *digest);
void sha384_one_block_avx(void *data, void *digest);
void sha512_one_block_avx(void *data, void *digest);
#define md5_one_block_avx       md5_one_block_sse



void aes_keyexp_128_avx(void *key,
                        void *enc_exp_keys,
                        void *dec_exp_keys);

void aes_keyexp_192_avx(void *key,
                        void *enc_exp_keys,
                        void *dec_exp_keys);

void aes_keyexp_256_avx(void *key,
                        void *enc_exp_keys,
                        void *dec_exp_keys);


void aes_xcbc_expand_key_avx(void *key, 
                             void *k1_exp, 
                             void *k2, 
                             void *k3);

void aes_keyexp_128_enc_avx(void *key, void *enc_exp_keys);

////////////////////////////////////////////////////////////////////////


#define sha1_one_block_avx2      sha1_one_block_avx
#define sha224_one_block_avx2    sha224_one_block_avx
#define sha256_one_block_avx2    sha256_one_block_avx
#define sha384_one_block_avx2    sha384_one_block_avx
#define sha512_one_block_avx2    sha512_one_block_avx
#define md5_one_block_avx2       md5_one_block_avx
#define aes_keyexp_128_avx2      aes_keyexp_128_avx
#define aes_keyexp_192_avx2      aes_keyexp_192_avx
#define aes_keyexp_256_avx2      aes_keyexp_256_avx
#define aes_xcbc_expand_key_avx2 aes_xcbc_expand_key_avx
#define aes_keyexp_128_enc_avx2  aes_keyexp_128_enc_avx
