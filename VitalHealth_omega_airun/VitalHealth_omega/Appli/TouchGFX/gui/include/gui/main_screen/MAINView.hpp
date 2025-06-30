#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/MAINViewBase.hpp>
#include <gui/main_screen/MAINPresenter.hpp>
#include <texts/TextKeysAndLanguages.hpp>

class MAINView : public MAINViewBase
{
public:
    MAINView();
    virtual ~MAINView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void changelanguagefunc();
    void settemp(float value);
    void sethumi(float value);
    void setCO2(float value);
    void setlight(int value);
    void setTOF(int value);
    void setFatigue(float value);
protected:
};

#endif // MAINVIEW_HPP
