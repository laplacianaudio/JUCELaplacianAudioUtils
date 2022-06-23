/*
  ==============================================================================

    LAGenManager.h
    Created: 23 Jun 2022 6:24:17pm
    Author:  Mike Gazzaruso

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "genlib.h"
#include "genlib_exportfunctions.h"
#include "genlib_ops.h"
#include "gen_exported.h"

namespace la_utils_maxmsp
{
    class LAGenManager
    {
    public:
        LAGenManager();
        ~LAGenManager();
        
        void prepareToPlay(double in_sampleRate, int in_samplesPerBlock);
            
        void process(juce::AudioBuffer<float> &in_buffer);
        
        void setParameter(long in_paramIndex, float in_paramValue);
        
    private:
        CommonState *m_cself;
        
        t_sample* genBuffer[2];
        t_sample* genBufferLeft;
        t_sample* genBufferRight;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LAGenManager)
    };
}
        
