#include <gui/main_screen/MAINView.hpp>
#include <gui/main_screen/MAINPresenter.hpp>

MAINPresenter::MAINPresenter(MAINView& v)
    : view(v)
{

}

void MAINPresenter::activate()
{

}

void MAINPresenter::deactivate()
{

}

void MAINPresenter::newjunctiontemp(float value)
{
	view.settemp(value);
}

void MAINPresenter::newjunctionHumi(float value)
{
	view.sethumi(value);
}

void MAINPresenter::newjunctionCO2(float value)
{
	view.setCO2(value);
}

void MAINPresenter::newjunctionLight(int value)
{
	view.setlight(value);
}

void MAINPresenter::newjunctionTOF(int value)
{
	view.setTOF(value);
}

void MAINPresenter::newjunctionFatigue(float value)
{
	view.setFatigue(value);
}
