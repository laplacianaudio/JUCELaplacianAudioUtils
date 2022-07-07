#include "LAKnob.h"

la_utils_gui::LAKnob::LAKnob(juce::String inParameterIdString,
                       juce::String inParameterString,
                       float defaultValue,
                       AudioProcessorValueTreeState& inState,
                       Colour inFillColour)
{
    parameterIdString = inParameterIdString;
    parameterString = inParameterString;
    setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    
    setRotaryParameters (juce::MathConstants<float>::pi * 1.25f,
                         juce::MathConstants<float>::pi * 2.75f,
                         true);
    setVelocityBasedMode (true);
    setVelocityModeParameters (1.0, 1, 0.1, false);
    setRange (0.0, 1.0, 0.01);
    setDoubleClickReturnValue (true, defaultValue);
    // setTextValueSuffix (" %");
    setColour (juce::Slider::textBoxTextColourId, CustomColours::black);
    setColour (juce::Slider::rotarySliderFillColourId, juce::Colours::orange);
    setLookAndFeel (&mLookAndFeel);
    setTitle(parameterString);
    setColour(juce::Slider::rotarySliderFillColourId, inFillColour);
    
    mAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(inState,
                                                                                   parameterIdString,
                                                                                   *this);
}

la_utils_gui::LAKnob::~LAKnob()
{
    setLookAndFeel(nullptr);
}

void la_utils_gui::LAKnob::paint(juce::Graphics& g)
{
    juce::Slider::paint(g);
    g.setColour(CustomColours::grey);
    auto bounds = getLocalBounds();
    bounds.setY(getLocalBounds().getHeight() * 0.02);
    g.setFont(bounds.getHeight() * 0.15);
    g.drawFittedText(parameterString,
                     bounds,
                     juce::Justification::Justification::centredBottom,
                     1);
}

juce::String la_utils_gui::LAKnob::getTextFromValue(double value)
{
    std::stringstream stream;
      stream << std::fixed << std::setprecision(getNumDecimalPlacesToDisplay()) << value * 100 << getTextValueSuffix().toStdString();
      std::string s = stream.str();
      return s;
}