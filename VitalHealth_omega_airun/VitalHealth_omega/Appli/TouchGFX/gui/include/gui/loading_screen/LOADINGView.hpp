#ifndef LOADINGVIEW_HPP
#define LOADINGVIEW_HPP

#include <gui_generated/loading_screen/LOADINGViewBase.hpp>
#include <gui/loading_screen/LOADINGPresenter.hpp>

class LOADINGView : public LOADINGViewBase
{
public:
    LOADINGView();
    virtual ~LOADINGView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
protected:
    int tickCount;
    uint8_t currentPct;
    const uint8_t ANIMATION_DURATION = 20;
};

#endif // LOADINGVIEW_HPP
