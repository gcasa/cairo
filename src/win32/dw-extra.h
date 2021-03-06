/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*- */

/* Mingw-w64 dwrite_3.h is broken
 *
 * We only need the definitions of the following functions and their dependencies.
 *   IDWriteFactory4::TranslateColorGlyphRun()
 *   IDWriteFontResource::GetDefaultFontAxisValues()
 *   IDWriteFontResource::GetFontAxisCount()
 *   IDWriteFontResource::HasVariations()
 *   IDWriteFontFace5::GetFontAxisValueCount()
 *   IDWriteFontFace5::GetFontAxisValues()
 *   IDWriteFontFace5::HasVariations()
 *   IDWriteFontFace5::GetFontResource()
 *
 * But we need to include all the prior functions in the same struct,
 * and parent structs, so that the functions are in the correct position
 * in the vtable. The parameters of the unused functions are not
 * required as we only need a function in the struct to create a
 * function pointer in the vtable.
 */

#ifndef DWRITE_EXTRA_H
#define DWRITE_EXTRA_H

#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"

#include <dwrite_2.h>

interface IDWriteFactory3;
interface IDWriteFactory4;
interface IDWriteColorGlyphRunEnumerator1;

DEFINE_ENUM_FLAG_OPERATORS(DWRITE_GLYPH_IMAGE_FORMATS);

struct DWRITE_COLOR_GLYPH_RUN1 : DWRITE_COLOR_GLYPH_RUN
{
    DWRITE_GLYPH_IMAGE_FORMATS glyphImageFormat;
    DWRITE_MEASURING_MODE measuringMode;
};


DEFINE_GUID(IID_IDWriteColorGlyphRunEnumerator1, 0x7c5f86da, 0xc7a1, 0x4f05, 0xb8,0xe1, 0x55,0xa1,0x79,0xfe,0x5a,0x35);
MIDL_INTERFACE("7c5f86da-c7a1-4f05-b8e1-55a179fe5a35")
IDWriteColorGlyphRunEnumerator1 : public IDWriteColorGlyphRunEnumerator
{
    virtual HRESULT STDMETHODCALLTYPE GetCurrentRun(
        const DWRITE_COLOR_GLYPH_RUN1 **run) = 0;

};
__CRT_UUID_DECL(IDWriteColorGlyphRunEnumerator1, 0x7c5f86da, 0xc7a1, 0x4f05, 0xb8,0xe1, 0x55,0xa1,0x79,0xfe,0x5a,0x35)

DEFINE_GUID(IID_IDWriteFactory3, 0x9a1b41c3, 0xd3bb, 0x466a, 0x87,0xfc, 0xfe,0x67,0x55,0x6a,0x3b,0x65);
MIDL_INTERFACE("9a1b41c3-d3bb-466a-87fc-fe67556a3b65")
IDWriteFactory3 : public IDWriteFactory2
{
  virtual void STDMETHODCALLTYPE CreateGlyphRunAnalysis() = 0;
  virtual void STDMETHODCALLTYPE CreateCustomRenderingParams() = 0;
  virtual void STDMETHODCALLTYPE CreateFontFaceReference() = 0;
  virtual void STDMETHODCALLTYPE CreateFontFaceReference2() = 0;
  virtual void STDMETHODCALLTYPE GetSystemFontSet() = 0;
  virtual void STDMETHODCALLTYPE CreateFontSetBuilder() = 0;
  virtual void STDMETHODCALLTYPE CreateFontCollectionFromFontSet() = 0;
  virtual void STDMETHODCALLTYPE GetSystemFontCollection() = 0;
  virtual void STDMETHODCALLTYPE GetFontDownloadQueue() = 0;
};
__CRT_UUID_DECL(IDWriteFactory3, 0x9a1b41c3, 0xd3bb, 0x466a, 0x87,0xfc, 0xfe,0x67,0x55,0x6a,0x3b,0x65)

DEFINE_GUID(IID_IDWriteFactory4, 0x4b0b5bd3, 0x0797, 0x4549, 0x8a,0xc5, 0xfe,0x91,0x5c,0xc5,0x38,0x56);
MIDL_INTERFACE("4b0b5bd3-0797-4549-8ac5-fe915cc53856")
IDWriteFactory4 : public IDWriteFactory3
{
  virtual HRESULT STDMETHODCALLTYPE TranslateColorGlyphRun(
    D2D1_POINT_2F                      baselineOrigin,
    DWRITE_GLYPH_RUN const             *glyphRun,
    DWRITE_GLYPH_RUN_DESCRIPTION const *glyphRunDescription,
    DWRITE_GLYPH_IMAGE_FORMATS         desiredGlyphImageFormats,
    DWRITE_MEASURING_MODE              measuringMode,
    DWRITE_MATRIX const                *worldAndDpiTransform,
    UINT32                             colorPaletteIndex,
    IDWriteColorGlyphRunEnumerator1    **colorLayers) = 0;
};
__CRT_UUID_DECL(IDWriteFactory4, 0x4b0b5bd3, 0x0797, 0x4549, 0x8a,0xc5, 0xfe,0x91,0x5c,0xc5,0x38,0x56)

typedef enum DWRITE_FONT_AXIS_TAG {
    DWRITE_FONT_AXIS_TAG_WEIGHT = 0x74686777,
    DWRITE_FONT_AXIS_TAG_WIDTH = 0x68746477,
    DWRITE_FONT_AXIS_TAG_SLANT = 0x746e6c73,
    DWRITE_FONT_AXIS_TAG_OPTICAL_SIZE = 0x7a73706f,
    DWRITE_FONT_AXIS_TAG_ITALIC = 0x6c617469
} DWRITE_FONT_AXIS_TAG;

typedef struct DWRITE_FONT_AXIS_VALUE {
    DWRITE_FONT_AXIS_TAG axisTag;
    FLOAT value;
} DWRITE_FONT_AXIS_VALUE;

DEFINE_GUID(IID_IDWriteFontResource, 0x1f803a76, 0x6871, 0x48e8, 0x98,0x7f, 0xb9,0x75,0x55,0x1c,0x50,0xf2);
MIDL_INTERFACE("1f803a76-6871-48e8-987f-b975551c50f2")
IDWriteFontResource : public IUnknown
{
  virtual void STDMETHODCALLTYPE GetFontFile() = 0;
  virtual void STDMETHODCALLTYPE GetFontFaceIndex() = 0;
  virtual UINT32 STDMETHODCALLTYPE GetFontAxisCount() = 0;
  virtual HRESULT STDMETHODCALLTYPE GetDefaultFontAxisValues(
    const DWRITE_FONT_AXIS_VALUE *values,
    UINT32 num_values) = 0;
  virtual void STDMETHODCALLTYPE GetFontAxisRanges() = 0;
  virtual void STDMETHODCALLTYPE GetFontAxisAttributes() = 0;
  virtual void STDMETHODCALLTYPE GetAxisNames() = 0;
  virtual void STDMETHODCALLTYPE GetAxisValueNameCount() = 0;
  virtual void STDMETHODCALLTYPE GetAxisValueNames() = 0;
  virtual WINBOOL STDMETHODCALLTYPE HasVariations() = 0;
  virtual void STDMETHODCALLTYPE CreateFontFace() = 0;
  virtual void STDMETHODCALLTYPE CreateFontFaceReference() = 0;
};
__CRT_UUID_DECL(IDWriteFontResource, 0x1f803a76, 0x6871, 0x48e8, 0x98,0x7f, 0xb9,0x75,0x55,0x1c,0x50,0xf2)

DEFINE_GUID(IID_IDWriteFontFace3, 0xd37d7598, 0x09be, 0x4222, 0xa2,0x36, 0x20,0x81,0x34,0x1c,0xc1,0xf2);
MIDL_INTERFACE("d37d7598-09be-4222-a236-2081341cc1f2")
IDWriteFontFace3 : public IDWriteFontFace2
{
  virtual void STDMETHODCALLTYPE GetFontFaceReference() = 0;
  virtual void STDMETHODCALLTYPE GetPanose() = 0;
  virtual void STDMETHODCALLTYPE GetWeight() = 0;
  virtual void STDMETHODCALLTYPE GetStretch() = 0;
  virtual void STDMETHODCALLTYPE GetStyle() = 0;
  virtual void STDMETHODCALLTYPE GetFamilyNames() = 0;
  virtual void STDMETHODCALLTYPE GetFaceNames() = 0;
  virtual void STDMETHODCALLTYPE GetInformationalStrings() = 0;
  virtual void STDMETHODCALLTYPE HasCharacter() = 0;
  virtual void STDMETHODCALLTYPE GetRecommendedRenderingMode() = 0;
  virtual void STDMETHODCALLTYPE IsCharacterLocal() = 0;
  virtual void STDMETHODCALLTYPE IsGlyphLocal() = 0;
  virtual void STDMETHODCALLTYPE AreCharactersLocal() = 0;
  virtual void STDMETHODCALLTYPE AreGlyphsLocal() = 0;
};
__CRT_UUID_DECL(IDWriteFontFace3, 0xd37d7598, 0x09be, 0x4222, 0xa2,0x36, 0x20,0x81,0x34,0x1c,0xc1,0xf2)

DEFINE_GUID(IID_IDWriteFontFace4, 0x27f2a904, 0x4eb8, 0x441d, 0x96,0x78, 0x05,0x63,0xf5,0x3e,0x3e,0x2f);
MIDL_INTERFACE("27f2a904-4eb8-441d-9678-0563f53e3e2f")
IDWriteFontFace4 : public IDWriteFontFace3
{
  virtual void STDMETHODCALLTYPE GetGlyphImageFormats_() = 0;
  virtual void STDMETHODCALLTYPE GetGlyphImageFormats() = 0;
  virtual void STDMETHODCALLTYPE GetGlyphImageData() = 0;
  virtual void STDMETHODCALLTYPE ReleaseGlyphImageData() = 0;
};
__CRT_UUID_DECL(IDWriteFontFace4, 0x27f2a904, 0x4eb8, 0x441d, 0x96,0x78, 0x05,0x63,0xf5,0x3e,0x3e,0x2f)

DEFINE_GUID(IID_IDWriteFontFace5, 0x98eff3a5, 0xb667, 0x479a, 0xb1,0x45, 0xe2,0xfa,0x5b,0x9f,0xdc,0x29);
MIDL_INTERFACE("98eff3a5-b667-479a-b145-e2fa5b9fdc29")
IDWriteFontFace5 : public IDWriteFontFace4
{
  virtual UINT32 STDMETHODCALLTYPE GetFontAxisValueCount() = 0;
  virtual HRESULT STDMETHODCALLTYPE GetFontAxisValues(
    DWRITE_FONT_AXIS_VALUE *values,
    UINT32 value_count) = 0;
  virtual WINBOOL STDMETHODCALLTYPE HasVariations() = 0;
  virtual HRESULT STDMETHODCALLTYPE GetFontResource(
    IDWriteFontResource **resource) = 0;
  virtual void STDMETHODCALLTYPE Equals() = 0;
};
__CRT_UUID_DECL(IDWriteFontFace5, 0x98eff3a5, 0xb667, 0x479a, 0xb1,0x45, 0xe2,0xfa,0x5b,0x9f,0xdc,0x29)

#endif /* DWRITE_EXTRA_H */
