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
    mTextButton->setButtonText("Make Remote Fetch API Request");
    mTextButton->onClick = [this] {
        mNetworkManager->setUrlString("https://jsonplaceholder.typicode.com/todos/" + String(getCounter()));
        mNetworkManager->makeFetchRequest([this] (String result) {
            DBG(result);
            setResult(result);
            this->incrementCounter();
        });
    };
    
    addAndMakeVisible(mTextEditor.get());
    addAndMakeVisible(mTextButton.get());
    
    startTimer(1000);
    
}

MainComponent::~MainComponent()
{
}

void MainComponent::timerCallback()
{
    mTextEditor->setText(getResult());
    repaint();
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
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
