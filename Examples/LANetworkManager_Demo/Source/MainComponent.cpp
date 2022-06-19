#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
    
    mNetworkManager = std::make_unique<la_utils_network::LANetworkManager>();
    
    mTextEditor = std::make_unique<TextEditor>();
    mTextEditor->setReadOnly(true);
    mTextEditor->setMultiLine(true);
    mTextEditor->setHasFocusOutline(false);
    
    mTextButton = std::make_unique<TextButton>();
    mTextButton->setButtonText("Check for Updates on BE");
    mTextButton->onClick = [this] {
        mNetworkManager->setUrlString("http://localhost:3000/check-update");
        mNetworkManager->makeFetchRequest([this] (String result) {
            DBG(result);
            setResult(result);
        });
    };

    mUpdateLabel = std::make_unique<Label>();
    mUpdateLabel->setText("Updates Available!", dontSendNotification);
    mUpdateLabel->setColour(Label::ColourIds::textColourId, Colours::red);
    mUpdateLabel->setJustificationType(Justification::Justification::centredRight);
    
    addAndMakeVisible(mTextEditor.get());
    addAndMakeVisible(mTextButton.get());
    addChildComponent(mUpdateLabel.get());

    startTimer(1000); 
}

MainComponent::~MainComponent()
{
}

void MainComponent::timerCallback()
{
    mTextEditor->setText(getResult());
    /* Result == 0 -> No Updates; Result == 1 -> Updates Available **/
    if (getResult() == "1")
    {
        mUpdateLabel->setVisible(true);

        /* Here you could write your custom BL if Updates are/aren't available **/
    }
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    
    mTextEditor->setBounds(getWidth() * 0.05, getHeight() * 0.1, getWidth() * 0.9, getHeight() * 0.7);
    mTextEditor->setFont(getLocalBounds().getWidth() * 0.03);
    mTextEditor->applyFontToAllText(getLocalBounds().getWidth() * 0.03);
    
    mTextButton->setBounds(getWidth() * 0.05, getHeight() * 0.85, getWidth() * 0.9, getHeight() * 0.10);

    mUpdateLabel->setBounds(0, 0, getWidth(), getHeight() * 0.05);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
