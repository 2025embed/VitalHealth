#include <gui/main_screen/MAINView.hpp>
#include <touchgfx/Color.hpp>

MAINView::MAINView()
{

}

void MAINView::setupScreen()
{
    MAINViewBase::setupScreen();
}

void MAINView::tearDownScreen()
{
    MAINViewBase::tearDownScreen();
}

void MAINView::changelanguagefunc()
{
    int idlanguage = Texts::getLanguage() + 1;
    if (idlanguage == NUMBER_OF_LANGUAGES)
    {
        idlanguage = 0;
    }
    Texts::setLanguage(idlanguage);
    MAINView::invalidate();
    getRootContainer().invalidate();
}

void MAINView::settemp(float value)
{
	if (value < 23)
	{
		tempinfo.setColor(Color::getColorFromRGB(0x00, 0x00, 0xFF));
	}
	else if (value >= 23 && value <= 28)
	{
		tempinfo.setColor(Color::getColorFromRGB(0x00, 0x00, 0x00));
	}
	else
	{
		tempinfo.setColor(Color::getColorFromRGB(0xFF, 0x80, 0x00));
	}
	Unicode::snprintfFloat(tempinfoBuffer, TEMPINFO_SIZE, "%.1f", value);
	tempinfo.invalidate();
}

void MAINView::sethumi(float value)
{
	if (value >= 40 && value <= 60)
	{
		humiinfo.setColor(Color::getColorFromRGB(0x00, 0x00, 0x00));
	}
	else
	{
		humiinfo.setColor(Color::getColorFromRGB(0xFF, 0x80, 0x00));
	}
	Unicode::snprintfFloat(humiinfoBuffer, HUMIINFO_SIZE, "%.1f", value);
	humiinfo.invalidate();
}

void MAINView::setCO2(float value)
{
	if (value <= 800)
	{
		CO2info.setColor(Color::getColorFromRGB(0x00, 0x00, 0x00));
	}
	else if (value > 800 && value <= 1000)
	{
		CO2info.setColor(Color::getColorFromRGB(0xFF, 0x80, 0x00));
	}
	else
	{
		CO2info.setColor(Color::getColorFromRGB(0xFF, 0x00, 0x00));
	}
	Unicode::snprintfFloat(CO2infoBuffer, CO2INFO_SIZE, "%.1f", value);
	CO2info.invalidate();
}

void MAINView::setlight(int value)
{
	if (value <= 750 && value >= 500)
	{
		lightinfo.setColor(Color::getColorFromRGB(0x00, 0x00, 0x00));
	}
	else
	{
		lightinfo.setColor(Color::getColorFromRGB(0xFF, 0x80, 0x00));
	}
	Unicode::snprintf(lightinfoBuffer, LIGHTINFO_SIZE, "%d", value);
	lightinfo.invalidate();
}

void MAINView::setTOF(int value)
{
	const TypedTextId texts[] = { T_BACK,T_FRONT,T_LEFT,T_RIGHT,T_NORMAL };
	Unicode::snprintf(postureinfoBuffer, POSTUREINFO_SIZE, "%s", TypedText(texts[value]).getText());
	postureinfo.invalidate();
}

void MAINView::setFatigue(float value)
{
	static uint8_t currentSuggestionIndex = 0;
	if (value < 70)
	{
		suggest.setColor(Color::getColorFromRGB(0x00, 0x00, 0x00));
		Unicode::snprintf(suggestBuffer, SUGGEST_SIZE, "%s", TypedText(2).getText());
	}
	else
	{
		suggest.setColor(Color::getColorFromRGB(0x00, 0x00, 0x00));
		Unicode::snprintf(suggestBuffer, SUGGEST_SIZE, "%s", TypedText(currentSuggestionIndex).getText());
		currentSuggestionIndex = currentSuggestionIndex + 1;
		if (currentSuggestionIndex == 2)
		{
			currentSuggestionIndex = 0;
		}
	}
	if (value < 70)
	{
		degree.setColor(Color::getColorFromRGB(0x00, 0x00, 0x00));
		Unicode::snprintfFloat(degreeBuffer, DEGREE_SIZE, "%.1f", value);
	}
	else
	{
		degree.setColor(Color::getColorFromRGB(0xFF, 0x00, 0x00));
		Unicode::snprintfFloat(degreeBuffer, DEGREE_SIZE, "%.1f", value);
	}
	scoreprog.setValue(value);
	suggest.invalidate();
	degree.invalidate();
	scoreprog.invalidate();
}
