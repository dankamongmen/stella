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
// Copyright (c) 1995-2020 by Bradford W. Mott, Stephen Anthony
// and the Stella Team
//
// See the file "License.txt" for information on usage and redistribution of
// this file, and for a DISCLAIMER OF ALL WARRANTIES.
//============================================================================

#ifndef STRING_LIST_WIDGET_HXX
#define STRING_LIST_WIDGET_HXX

#include "ListWidget.hxx"

/** StringListWidget */
class StringListWidget : public ListWidget
{
  public:
    StringListWidget(GuiObject* boss, const GUI::Font& font,
                     int x, int y, int w, int h, bool hilite = true);
    virtual ~StringListWidget() = default;

    void setList(const StringList& list);
    bool wantsFocus() const override { return true; }

  protected:
    void handleMouseEntered() override;
    void handleMouseLeft() override;
    void drawWidget(bool hilite) override;
    Common::Rect getEditRect() const override;

  protected:
    bool _hilite{false};
    int  _textOfs{0};

  private:
    // Following constructors and assignment operators not supported
    StringListWidget() = delete;
    StringListWidget(const StringListWidget&) = delete;
    StringListWidget(StringListWidget&&) = delete;
    StringListWidget& operator=(const StringListWidget&) = delete;
    StringListWidget& operator=(StringListWidget&&) = delete;
};

#endif
