/*
 * Copyright © Yonggang Luo
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
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

/* find | grep .*h$ >../headers.txt */
#include <mesa/main/accum.h>
#include <mesa/main/api_arrayelt.h>
#include <mesa/main/arrayobj.h>
#include <mesa/main/atifragshader.h>
#include <mesa/main/attrib.h>
#include <mesa/main/bbox.h>
#include <mesa/main/blend.h>
#include <mesa/main/blit.h>
#include <mesa/main/bufferobj.h>
#include <mesa/main/buffers.h>
#include <mesa/main/clip.h>
#include <mesa/main/colormac.h>
#include <mesa/main/condrender.h>
#include <mesa/main/config.h>
#include <mesa/main/conservativeraster.h>
#include <mesa/main/consts_exts.h>
#include <mesa/main/context.h>
#include <mesa/main/cpuinfo.h>
#include <mesa/main/dd.h>
#include <mesa/main/debug.h>
#include <mesa/main/debug_output.h>
#include <mesa/main/depth.h>
#include <mesa/main/dlist.h>
#include <mesa/main/draw.h>
#include <mesa/main/draw_validate.h>
#include <mesa/main/enable.h>
#include <mesa/main/enums.h>
#include <mesa/main/errors.h>
#include <mesa/main/eval.h>
#include <mesa/main/extensions.h>
#include <mesa/main/externalobjects.h>
#include <mesa/main/fbobject.h>
#include <mesa/main/feedback.h>
#include <mesa/main/ffvertex_prog.h>
#include <mesa/main/fog.h>
#include <mesa/main/formatquery.h>
#include <mesa/main/formats.h>
#include <mesa/main/format_pack.h>
#include <mesa/main/format_unpack.h>
#include <mesa/main/format_utils.h>
#include <mesa/main/framebuffer.h>
#include <mesa/main/genmipmap.h>
#include <mesa/main/get.h>
#include <mesa/main/glconfig.h>
#include <mesa/main/glformats.h>
#include <mesa/main/glspirv.h>
#include <mesa/main/glthread.h>
#include <mesa/main/glthread_marshal.h>
#include <mesa/main/hash.h>
#include <mesa/main/hint.h>
#include <mesa/main/image.h>
#include <mesa/main/light.h>
#include <mesa/main/lines.h>
#include <mesa/main/macros.h>
#include <mesa/main/matrix.h>
#include <mesa/main/menums.h>
#include <mesa/main/mesa_private.h>
#include <mesa/main/mipmap.h>
#include <mesa/main/mtypes.h>
#include <mesa/main/multisample.h>
#include <mesa/main/pack.h>
#include <mesa/main/pbo.h>
#include <mesa/main/performance_monitor.h>
#include <mesa/main/performance_query.h>
#include <mesa/main/pipelineobj.h>
#include <mesa/main/pixel.h>
#include <mesa/main/pixelstore.h>
#include <mesa/main/pixeltransfer.h>
#include <mesa/main/points.h>
#include <mesa/main/polygon.h>
#include <mesa/main/program_binary.h>
#include <mesa/main/queryobj.h>
#include <mesa/main/rastpos.h>
#include <mesa/main/readpix.h>
#include <mesa/main/remap.h>
#include <mesa/main/renderbuffer.h>
#include <mesa/main/samplerobj.h>
#include <mesa/main/scissor.h>
#include <mesa/main/shaderapi.h>
#include <mesa/main/shaderimage.h>
#include <mesa/main/shaderobj.h>
#include <mesa/main/shader_types.h>
#include <mesa/main/shared.h>
#include <mesa/main/spirv_extensions.h>
#include <mesa/main/sse_minmax.h>
#include <mesa/main/state.h>
#include <mesa/main/stencil.h>
#include <mesa/main/syncobj.h>
#include <mesa/main/texcompress.h>
#include <mesa/main/texcompress_astc.h>
#include <mesa/main/texcompress_bptc.h>
#include <mesa/main/texcompress_bptc_tmp.h>
#include <mesa/main/texcompress_cpal.h>
#include <mesa/main/texcompress_etc.h>
#include <mesa/main/texcompress_fxt1.h>
#include <mesa/main/texcompress_rgtc.h>
#include <mesa/main/texcompress_s3tc.h>
#include <mesa/main/texcompress_s3tc_tmp.h>
#include <mesa/main/texenvprogram.h>
#include <mesa/main/texgetimage.h>
#include <mesa/main/teximage.h>
#include <mesa/main/texobj.h>
#include <mesa/main/texparam.h>
#include <mesa/main/texstate.h>
#include <mesa/main/texstorage.h>
#include <mesa/main/texstore.h>
#include <mesa/main/texturebindless.h>
#include <mesa/main/textureview.h>
#include <mesa/main/transformfeedback.h>
#include <mesa/main/uniforms.h>
#include <mesa/main/varray.h>
#include <mesa/main/version.h>
#include <mesa/main/viewport.h>
#include <mesa/math/m_debug.h>
#include <mesa/math/m_debug_util.h>
#include <mesa/math/m_eval.h>
#include <mesa/math/m_matrix.h>
#include <mesa/math/m_vector.h>
#include <mesa/math/m_vector_asm.h>
#include <mesa/math/m_xform.h>
#include <mesa/program/arbprogparse.h>
#include <mesa/program/link_program.h>
#include <mesa/program/program.h>
#include <mesa/program/programopt.h>
#include <mesa/program/program_parser.h>
#include <mesa/program/prog_cache.h>
#include <mesa/program/prog_instruction.h>
#include <mesa/program/prog_parameter.h>
#include <mesa/program/prog_parameter_layout.h>
#include <mesa/program/prog_print.h>
#include <mesa/program/prog_statevars.h>
#include <mesa/program/prog_to_nir.h>
#include <mesa/program/symbol_table.h>
#include <mesa/state_tracker/st_atifs_to_nir.h>
#include <mesa/state_tracker/st_atom.h>
#include <mesa/state_tracker/st_atom_constbuf.h>
#include <mesa/state_tracker/st_cb_bitmap.h>
#include <mesa/state_tracker/st_cb_clear.h>
#include <mesa/state_tracker/st_cb_copyimage.h>
#include <mesa/state_tracker/st_cb_drawpixels.h>
#include <mesa/state_tracker/st_cb_drawtex.h>
#include <mesa/state_tracker/st_cb_eglimage.h>
#include <mesa/state_tracker/st_cb_feedback.h>
#include <mesa/state_tracker/st_cb_flush.h>
#include <mesa/state_tracker/st_cb_rasterpos.h>
#include <mesa/state_tracker/st_cb_readpixels.h>
#include <mesa/state_tracker/st_cb_texture.h>
#include <mesa/state_tracker/st_context.h>
#include <mesa/state_tracker/st_copytex.h>
#include <mesa/state_tracker/st_debug.h>
#include <mesa/state_tracker/st_draw.h>
#include <mesa/state_tracker/st_extensions.h>
#include <mesa/state_tracker/st_format.h>
#include <mesa/state_tracker/st_gen_mipmap.h>
#include <mesa/state_tracker/st_glsl_to_ir.h>
#include <mesa/state_tracker/st_manager.h>
#include <mesa/state_tracker/st_nir.h>
#include <mesa/state_tracker/st_pbo.h>
#include <mesa/state_tracker/st_program.h>
#include <mesa/state_tracker/st_sampler_view.h>
#include <mesa/state_tracker/st_scissor.h>
#include <mesa/state_tracker/st_shader_cache.h>
#include <mesa/state_tracker/st_texture.h>
#include <mesa/state_tracker/st_util.h>
#include <mesa/state_tracker/st_vdpau.h>
#include <mesa/vbo/vbo.h>
#include <mesa/vbo/vbo_attrib.h>
#include <mesa/vbo/vbo_exec.h>
#include <mesa/vbo/vbo_private.h>
#include <mesa/vbo/vbo_save.h>
#include <mesa/vbo/vbo_util.h>
#include <util/anon_file.h>
#include <util/bigmath.h>
#include <util/bitpack_helpers.h>
#include <util/bitscan.h>
#include <util/bitset.h>
#include <util/blob.h>
#include <util/build_id.h>
#include <util/compiler.h>
#include <util/compress.h>
#include <util/crc32.h>
#include <util/dag.h>
#include <util/detect_os.h>
#include <util/disk_cache.h>
#include <util/disk_cache_os.h>
#include <util/double.h>
#include <util/driconf.h>
#include <util/enum_operators.h>
#include <util/fast_idiv_by_const.h>
#include <util/fast_urem_by_const.h>
#include <util/format/format_utils.h>
#include <util/format/u_format.h>
#include <util/format/u_format_bptc.h>
#include <util/format/u_format_etc.h>
#include <util/format/u_format_fxt1.h>
#include <util/format/u_format_latc.h>
#include <util/format/u_format_other.h>
#include <util/format/u_format_rgtc.h>
#include <util/format/u_format_s3tc.h>
#include <util/format/u_format_tests.h>
#include <util/format/u_format_yuv.h>
#include <util/format/u_format_zs.h>
#include <util/format_r11g11b10f.h>
#include <util/format_rgb9e5.h>
#include <util/format_srgb.h>
#include <util/fossilize_db.h>
#include <util/futex.h>
#include <util/glheader.h>
#include <util/half_float.h>
#include <util/hash_table.h>
#include <util/indices/u_indices.h>
#include <util/indices/u_indices_priv.h>
#include <util/indices/u_primconvert.h>
#include <util/list.h>
#include <util/log.h>
#include <util/macros.h>
#include <util/memstream.h>
#include <util/mesa-sha1.h>
#include <util/mesa_cache_db.h>
#include <util/os_file.h>
#include <util/os_memory.h>
#include <util/os_misc.h>
#include <util/os_socket.h>
#include <util/os_time.h>
#include <util/perf/cpu_trace.h>
#include <util/perf/u_perfetto.h>
#include <util/perf/u_trace.h>
#include <util/ptralloc.h>
#include <util/ralloc.h>
#include <util/rand_xor.h>
#include <util/rb_tree.h>
#include <util/reallocarray.h>
#include <util/register_allocate.h>
#include <util/register_allocate_internal.h>
#include <util/rgtc.h>
#include <util/rounding.h>
#include <util/rwlock.h>
#include <util/set.h>
#include <util/sha1/sha1.h>
#include <util/simple_mtx.h>
#include <util/slab.h>
#include <util/softfloat.h>
#include <util/sparse_array.h>
#include <util/streaming-load-memcpy.h>
#include <util/string_buffer.h>
#include <util/strndup.h>
#include <util/strtod.h>
#include <util/timespec.h>
#include <util/u_atomic.h>
#include <util/u_call_once.h>
#include <util/u_cpu_detect.h>
#include <util/u_debug.h>
#include <util/u_debug_describe.h>
#include <util/u_debug_refcnt.h>
#include <util/u_debug_stack.h>
#include <util/u_debug_symbol.h>
#include <util/u_dl.h>
#include <util/u_drm.h>
#include <util/u_dynarray.h>
#include <util/u_endian.h>
#include <util/u_hash_table.h>
#include <util/u_idalloc.h>
#include <util/u_math.h>
#include <util/u_memory.h>
#include <util/u_memset.h>
#include <util/u_mm.h>
#include <util/u_pointer.h>
#include <util/u_printf.h>
#include <util/u_process.h>
#include <util/u_qsort.h>
#include <util/u_queue.h>
#include <util/u_string.h>
#include <util/u_thread.h>
#include <util/u_vector.h>
#include <util/u_worklist.h>
#include <util/vl_rbsp.h>
#include <util/vl_vlc.h>
#include <util/vma.h>
#include <util/xmlconfig.h>
#include <util/xxhash.h>

#if defined(_WIN32) && defined(_WINDOWS_)
#error "Should not include <windows.h> here"
#endif