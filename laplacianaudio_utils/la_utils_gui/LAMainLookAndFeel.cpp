#include "LAMainLookAndFeel.h"

la_utils_gui::LAMainLookAndFeel::LAMainLookAndFeel()
{
   /*  auto font = juce::Typeface::createSystemTypefaceFor(BinaryData::YanoneKaffeesatzMedium_ttf, BinaryData::YanoneKaffeesatzMedium_ttfSize);
        setDefaultSansSerifTypeface (font); */
}

la_utils_gui::LAMainLookAndFeel::~LAMainLookAndFeel() {}

juce::Slider::SliderLayout la_utils_gui::LAMainLookAndFeel::getSliderLayout (juce::Slider& slider)
{
    auto localBounds = slider.getLocalBounds();

    juce::Slider::SliderLayout layout;

    layout.textBoxBounds = localBounds.withY (-1);
    layout.sliderBounds = localBounds;
    
    return layout;
}

void la_utils_gui::LAMainLookAndFeel::drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos,
                                          const float rotaryStartAngle, const float rotaryEndAngle, juce::Slider& slider)
{
    y -= height * 0.05;
    auto fill = slider.findColour (juce::Slider::rotarySliderFillColourId);

    auto bounds = juce::Rectangle<float> (x, y, width, height).reduced (2.0f);
    auto radius = juce::jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
    auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    auto lineW = radius * 0.085f;
    auto arcRadius = radius - lineW * 1.6f;

    juce::Path backgroundArc;
    backgroundArc.addCentredArc (bounds.getCentreX(),
                                 bounds.getCentreY(),
                                 arcRadius,
                                 arcRadius,
                                 0.0f,
                                 rotaryStartAngle,
                                 rotaryEndAngle,
                                 true);

    g.setColour (Colour(32, 32, 32));
    g.strokePath (backgroundArc, juce::PathStrokeType (lineW, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));

    juce::Path valueArc;
    valueArc.addCentredArc (bounds.getCentreX(),
                            bounds.getCentreY(),
                            arcRadius,
                            arcRadius,
                            0.0f,
                            rotaryStartAngle,
                            toAngle,
                            true);

    g.setColour (slider.isEnabled() ? fill : juce::Colours::darkgrey);
    g.strokePath (valueArc, juce::PathStrokeType (lineW, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));

    juce::Path stick;
    auto stickWidth = lineW * 2.0f;

    stick.addRectangle (-stickWidth / 2, -stickWidth / 2, stickWidth, radius + lineW);

    g.fillPath (stick, juce::AffineTransform::rotation (toAngle + 3.12f).translated (bounds.getCentre()));

    g.setColour (Colour(40, 40, 40));
    g.fillEllipse (bounds.reduced (radius * 0.25));
    
    setFontSize(radius * 0.4);
}

juce::Label* la_utils_gui::LAMainLookAndFeel::createSliderTextBox (juce::Slider& slider)
{
    auto* l = new juce::Label();

    l->setJustificationType (juce::Justification::centred);
    l->setColour (juce::Label::textColourId, CustomColours::grey);
    l->setColour (juce::Label::textWhenEditingColourId, slider.findColour (juce::Slider::textBoxTextColourId));
    l->setColour (juce::Label::outlineWhenEditingColourId, juce::Colours::transparentWhite);
    l->setInterceptsMouseClicks (false, false);

    return l;
}

juce::Font la_utils_gui::LAMainLookAndFeel::getLabelFont(juce::Label& label)
{
    label.setFont(fontSize);
    return label.getFont();
}

void la_utils_gui::LAMainLookAndFeel::setFontSize(float size)
{
    fontSize = size;
}

void la_utils_gui::LAMainLookAndFeel::drawButtonBackground(juce::Graphics& g,
                                        juce::Button& button,
                                        const juce::Colour &backgroundColour,
                                        bool shouldDrawButtonAsHighlighted,
                                        bool shouldDrawButtonAsDown)
{
    auto cornerSize = 6.0f;
    auto bounds = button.getLocalBounds().toFloat().reduced (0.5f, 0.5f);

    auto baseColour = backgroundColour.withMultipliedSaturation (button.hasKeyboardFocus (true) ? 1.3f : 0.9f)
                                      .withMultipliedAlpha (button.isEnabled() ? 1.0f : 0.5f);

    if (shouldDrawButtonAsDown || shouldDrawButtonAsHighlighted)
        baseColour = baseColour.contrasting (shouldDrawButtonAsDown ? 0.2f : 0.05f);

    g.setColour (baseColour);

    auto flatOnLeft   = button.isConnectedOnLeft();
    auto flatOnRight  = button.isConnectedOnRight();
    auto flatOnTop    = button.isConnectedOnTop();
    auto flatOnBottom = button.isConnectedOnBottom();

    if (flatOnLeft || flatOnRight || flatOnTop || flatOnBottom)
    {
        juce::Path path;
        path.addRoundedRectangle (bounds.getX(), bounds.getY(),
                                  bounds.getWidth(), bounds.getHeight(),
                                  cornerSize, cornerSize,
                                  ! (flatOnLeft  || flatOnTop),
                                  ! (flatOnRight || flatOnTop),
                                  ! (flatOnLeft  || flatOnBottom),
                                  ! (flatOnRight || flatOnBottom));

        g.fillPath (path);

        g.setColour (button.findColour (juce::ComboBox::outlineColourId));
        g.strokePath (path, PathStrokeType (1.0f));
    }
    else
    {
        g.fillRoundedRectangle (bounds, cornerSize);

        g.setColour (button.findColour (juce::ComboBox::outlineColourId));
        g.drawRoundedRectangle (bounds, cornerSize, 1.0f);
    }
}