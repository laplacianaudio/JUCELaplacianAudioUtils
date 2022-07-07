#pragma once

#include <JuceHeader.h>
#include "LAInterfaceDefines.h"
#include "LAMainLookAndFeel.h"

namespace la_utils_gui
{
    class LAKnob
    :   public juce::Slider
    {
    public:
        LAKnob(juce::String inParameterIdString,
                juce::String inParameterString,
                float defaultValue,
                juce::AudioProcessorValueTreeState& inState,
                juce::Colour inFillColour);
        ~LAKnob();
        
        void paint(juce::Graphics &) override;
        
        juce::String getTextFromValue(double value) override;
        
    private:
        la_utils_gui::LAMainLookAndFeel mLookAndFeel;
        juce::String parameterIdString;
        juce::String parameterString;
        std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mAttachment;
    };
}

        
