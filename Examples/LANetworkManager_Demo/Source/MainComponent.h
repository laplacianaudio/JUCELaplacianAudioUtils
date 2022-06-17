#pragma once

#include <JuceHeader.h>
#include <laplacianaudio_utils/la_utils_network/LANetworkManager.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent
:   public juce::Component,
    private Timer
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    String getResult() { return mResult; }
    void setResult(String inResult) { mResult = inResult; }
    
    int getCounter() { return mCounter; }
    void incrementCounter() { mCounter++; }

private:
    //==============================================================================
    // Your private member variables go here...
    std::unique_ptr<TextEditor> mTextEditor;
    std::unique_ptr<TextButton> mTextButton;
    
    void timerCallback() override;
    
    String mResult = "";
    int mCounter = 1;
    
    std::unique_ptr<la_utils_network::LANetworkManager> mNetworkManager;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
