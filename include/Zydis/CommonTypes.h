/***************************************************************************************************

  Zyan Disassembler Library (Zydis)

  Original Author : Florian Bernd, Joel Höner

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.

***************************************************************************************************/

/**
 * @file
 * @brief Includes and defines some default datatypes.
 */

#ifndef ZYDIS_COMMONTYPES_H
#define ZYDIS_COMMONTYPES_H

#include <Zydis/Defines.h>

/* ============================================================================================== */
/* Integer types                                                                                  */
/* ============================================================================================== */

#if !defined(ZYDIS_NO_LIBC)
    // LibC present, use stdint types.
#   include <stdint.h>
    typedef uint8_t  ZydisU8;
    typedef uint16_t ZydisU16;
    typedef uint32_t ZydisU32;
    typedef uint64_t ZydisU64;
    typedef int8_t   ZydisI8;
    typedef int16_t  ZydisI16;
    typedef int32_t  ZydisI32;
    typedef int64_t  ZydisI64;
#else 
    // No LibC, roll our own int sizes ...
#   if defined(ZYDIS_MSVC)
        typedef unsigned __int8  ZydisU8;
        typedef unsigned __int16 ZydisU16;
        typedef unsigned __int32 ZydisU32;
        typedef unsigned __int64 ZydisU64;
        typedef __int8           ZydisI8;
        typedef __int16          ZydisI16;
        typedef __int32          ZydisI32;
        typedef __int64          ZydisI64;
#   else
#       error "Unsupported compiler for NO_LIBC mode."
#   endif
#endif

#if ZYDIS_WORD_SIZE == 32
    typedef ZydisU32 ZydisUSize;
    typedef ZydisI32 ZydisISize;
#elif ZYDIS_WORD_SIZE == 64
    typedef ZydisU64 ZydisUSize;
    typedef ZydisI64 ZydisISize;
#else
#   error "Unsupported word size."
#endif

/* ============================================================================================== */
/* Boolean                                                                                        */
/* ============================================================================================== */

#define ZYDIS_FALSE 0
#define ZYDIS_TRUE  1

/**
 * @briefs  Defines the @c ZydisBool datatype.
 */
typedef uint8_t ZydisBool;

/* ============================================================================================== */

#endif /* ZYDIS_COMMONTYPES_H */
