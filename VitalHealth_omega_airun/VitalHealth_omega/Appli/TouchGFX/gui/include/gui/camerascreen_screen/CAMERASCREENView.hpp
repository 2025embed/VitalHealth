#ifndef CAMERASCREENVIEW_HPP
#define CAMERASCREENVIEW_HPP

#include <gui_generated/camerascreen_screen/CAMERASCREENViewBase.hpp>
#include <gui/camerascreen_screen/CAMERASCREENPresenter.hpp>

class CAMERASCREENView : public CAMERASCREENViewBase
{
public:
    CAMERASCREENView();
    virtual ~CAMERASCREENView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CAMERASCREENVIEW_HPP
