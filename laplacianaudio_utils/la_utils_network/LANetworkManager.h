#pragma once

#include <JuceHeader.h>

typedef std::function<void (juce::String)> RequestCallback;

namespace la_utils_network
{
    class LANetworkManager
    :   private juce::Thread
    {
    public:
        LANetworkManager();
        ~LANetworkManager();
        
        void run() override;
        
        juce::String getResultText(const juce::URL& url);
        
        void setUrlString(const juce::String inUrlString) { mUrlString = inUrlString; }
        
        void makeFetchRequest(RequestCallback cb);
        
    private:
        juce::String mUrlString;
        RequestCallback mRequestCallback;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LANetworkManager)

    };

}

        
