#include <gui/loading_screen/LOADINGView.hpp>

LOADINGView::LOADINGView()
{

}

void LOADINGView::setupScreen()
{
    LOADINGViewBase::setupScreen();

    per.setAlpha(0);
    per.setFadeAnimationDelay(ANIMATION_DURATION);
    per.startFadeAnimation(255, ANIMATION_DURATION * 2);
}

void LOADINGView::tearDownScreen()
{
    LOADINGViewBase::tearDownScreen();
}

void LOADINGView::handleTickEvent()
{
    const uint8_t ANIMATION_PRESCALER = 5;

    if (currentPct <= 100 && tickCount > 120 * 2)
    {
        if (!(tickCount % ANIMATION_PRESCALER))
        {
            Unicode::snprintf(perBuffer, PER_SIZE, "%d", currentPct);
            per.invalidate();
            currentPct++;
        }

        circleprog.setValue(currentPct * 10 + static_cast<int>((tickCount % ANIMATION_PRESCALER) * (10 / (ANIMATION_PRESCALER))));
    }

    if (tickCount == 100 * ANIMATION_PRESCALER + 120 * 2 + 60)
    {
        application().gotoMAINScreenWipeTransitionWest();
    }

    tickCount++;
}
