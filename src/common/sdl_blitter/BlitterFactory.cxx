//============================================================================
//
//   SSSS    tt          lll  lll
//  SS  SS   tt           ll   ll
//  SS     tttttt  eeee   ll   ll   aaaa
//   SSSS    tt   ee  ee  ll   ll      aa
//      SS   tt   eeeeee  ll   ll   aaaaa  --  "An Atari 2600 VCS Emulator"
//  SS  SS   tt   ee      ll   ll  aa  aa
//   SSSS     ttt  eeeee llll llll  aaaaa
//
// Copyright (c) 1995-2019 by Bradford W. Mott, Stephen Anthony
// and the Stella Team
//
// See the file "License.txt" for information on usage and redistribution of
// this file, and for a DISCLAIMER OF ALL WARRANTIES.
//============================================================================

#include "BlitterFactory.hxx"

#include "SDL_lib.hxx"
#include "BilinearBlitter.hxx"
#include "HqBlitter.hxx"

unique_ptr<Blitter> BlitterFactory::createBlitter(FrameBufferSDL2& fb)
{
  if (!fb.isInitialized()) {
    throw runtime_error("BlitterFactory requires an initialized framebuffer!");
  }

  SDL_RendererInfo info;

  SDL_GetRendererInfo(fb.renderer(), &info);

  return (info.flags & SDL_RENDERER_TARGETTEXTURE) ?
    unique_ptr<Blitter>(new HqBlitter(fb)) : unique_ptr<Blitter>(new BilinearBlitter(fb));
}