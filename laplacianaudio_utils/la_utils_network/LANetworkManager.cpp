#include "LANetworkManager.h"

la_utils_network::LANetworkManager::LANetworkManager()
:   juce::Thread("LANetworkManager Thread"),
    mUrlString("")
{}

la_utils_network::LANetworkManager::~LANetworkManager() {}

void la_utils_network::LANetworkManager::run()
{
    auto result = getResultText (mUrlString);

    DBG("Response from BE: " + result);
     mRequestCallback(result);
    
    
}

String la_utils_network::LANetworkManager::getResultText(const URL& url)
{
    juce::StringPairArray responseHeaders;
    int statusCode = 0;

    if (auto stream = url.createInputStream (juce::URL::InputStreamOptions (juce::URL::ParameterHandling::inAddress)
                                                                             .withConnectionTimeoutMs(20000)
                                                                             .withExtraHeaders("Content-Type:application/json")
                                                                             .withResponseHeaders (&responseHeaders)
                                                
                                                                             .withStatusCode (&statusCode)))
    {
        if (statusCode != 200)
            return "KO";
        return stream->readEntireStreamAsString();
    }

    if (statusCode != 0)
        return "KOStatusCode: " + juce::String (statusCode);

    return "KONetwork";
}

void la_utils_network::LANetworkManager::makeFetchRequest(RequestCallback cb)
{
    mRequestCallback = cb;
    startThread();
}
