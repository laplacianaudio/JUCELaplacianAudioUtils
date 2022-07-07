#pragma once

#include <JuceHeader.h>
#include "LAInterfaceDefines.h"

namespace la_utils_gui
{
    class LAMainLookAndFeel
:   public juce::LookAndFeel_V4
    {
    public:
        LAMainLookAndFeel();
        ~LAMainLookAndFeel();
        
        juce::Slider::SliderLayout getSliderLayout (juce::Slider& slider) override;
        
        juce::Font getLabelFont(juce::Label& label) override;
        
        void setFontSize(float size);
        
        void drawRotarySlider(juce::Graphics &,
                            int x,
                            int y,
                            int width,
                            int height,
                            float sliderPosProportional,
                            float rotaryStartAngle,
                            float rotaryEndAngle,
                            juce::Slider &) override;
        
        
        void drawButtonBackground(juce::Graphics &, juce::Button &, const juce::Colour &backgroundColour, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;
        
        juce::Label* createSliderTextBox(juce::Slider &) override;
        
        
    private:
        float fontSize = 0;
    };
}
