/*
 * Copyright (C) 2018-2021 Alyssa Rosenzweig <alyssa@rosenzweig.io>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __AGX_PUBLIC_H_
#define __AGX_PUBLIC_H_

#include "compiler/nir/nir.h"
#include "util/u_dynarray.h"

void
agx_compile_shader_nir(nir_shader *nir, struct util_dynarray *binary);

static const nir_shader_compiler_options agx_nir_options = {
   .lower_scmp = true,
   .lower_flrp16 = true,
   .lower_flrp32 = true,
   .lower_ffract = true,
   .lower_fmod = true,
   .lower_fdiv = true,
   .lower_isign = true,
   .lower_fpow = true,
   .lower_find_lsb = true,
   .lower_ifind_msb = true,
   .lower_fdph = true,
   .lower_wpos_pntc = true,
   .lower_fsign = true,
   .lower_rotate = true,
   .lower_pack_split = true,
   .lower_uniforms_to_ubo = true,
   .lower_cs_local_index_from_id = true,

   .lower_doubles_options = nir_lower_dmod,
   .lower_int64_options = ~(nir_lower_iadd64 | nir_lower_imul_2x32_64),

   .has_fsub = true,
   .has_isub = true,
   .has_cs_global_id = true,

   .vectorize_io = true,
   .fuse_ffma16 = true,
   .fuse_ffma32 = true,
   .use_interpolated_input_intrinsics = true,
};

#endif
