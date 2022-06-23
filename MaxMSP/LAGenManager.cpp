/*
  ==============================================================================

    LAGenManager.cpp
    Created: 23 Jun 2022 6:24:17pm
    Author:  Mike Gazzaruso

  ==============================================================================
*/

#include "LAGenManager.h"

la_utils_maxmsp::LAGenManager::LAGenManager()
{
    m_cself = (CommonState* )gen_exported::create(44100, 64);
}

la_utils_maxmsp::LAGenManager::~LAGenManager()
{
    if (genBufferLeft != nullptr)
        free(genBufferLeft);
    
    if (genBufferRight != nullptr)
        free(genBufferRight);
}

void la_utils_maxmsp::LAGenManager::prepareToPlay(double in_sampleRate, int in_samplesPerBlock)
{
    m_cself->sr = in_sampleRate;
    m_cself->vs = in_samplesPerBlock;
    
    genBufferLeft = (t_sample*) malloc(in_samplesPerBlock * sizeof(t_sample));
    genBufferRight = (t_sample*) malloc(in_samplesPerBlock * sizeof(t_sample));
    
    genBuffer[0] = genBufferLeft;
    genBuffer[1] = genBufferRight;
    
    for (auto i = 0; i < in_samplesPerBlock; i++)
    {
        genBuffer[0][i] = 0;
        genBuffer[1][i] = 0;
    }
}

void la_utils_maxmsp::LAGenManager::setParameter(long in_paramIndex, float in_paramValue)
{
    gen_exported::setparameter(m_cself, in_paramIndex, (t_sample)in_paramValue, NULL);
}

void la_utils_maxmsp::LAGenManager::process(juce::AudioBuffer<float> &in_buffer)
{
    auto* left = in_buffer.getWritePointer(0);
    auto* right = in_buffer.getWritePointer(1);
    
    for (auto j = 0; j < in_buffer.getNumSamples(); j++)
    {
        genBuffer[0][j] = left[j];
        genBuffer[1][j] = right[j];
    }
        
    auto* genBuf = (t_sample**)genBuffer;
    
    gen_exported::perform(m_cself, genBuf, 2, genBuf, 2, in_buffer.getNumSamples());
    
    for (auto j = 0; j < in_buffer.getNumSamples(); j++)
    {
        left[j] = genBuffer[0][j];
        right[j] = genBuffer[1][j];
    }
}

