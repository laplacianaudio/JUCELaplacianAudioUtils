# Laplacian Audio Max/MSP Manager

## Description
LAGenManager is a JUCE class that allows developers to access high-level APIs in order to use DSP code exported with [gen~](https://docs.cycling74.com/max8/vignettes/gen_topic) object.
For more imnformations about Max/MSP and gen~ visit [Max/MSP Website](https://cycling74.com/products/max). 

## Prerequisites
- Export your gen~ code, in Max/MSP, with 'exportcode' message. 
- By default, gen~ exports the library in the 'gen_dsp' folder and the gen_exported.h/cpp files outside the 'gen_dsp' folder. In order to use the Gen Manager, you are required to copy all the gen~ exported single files inside the Source folder of your project
- Copy the LAGenManager.h/cpp files inside the Source folder of your project

## Usage
In your JUCE project (i.e. in your AudioProcessor), create an instance of LAGenManager
```
std::unique_ptr<la_utils_maxmsp::LAGenManager> m_genManager;
```
and later initialize it i.e. in your AudioProcessor constructor
```
m_genManager = std::make_unique<la_utils_maxmsp::LAGenManager>();
```

In the prepareToPlay() function
```
m_genManager->prepareToPlay(sampleRate, samplesPerBlock);
```

In your rendering function, i.e. processBlock()
```
m_genManager->process(buffer);
```

If you need to set a parameter of your gen~ DSP use
```
void la_utils_maxmsp::LAGenManager::setParameter(long in_paramIndex, float in_paramValue);
```

## Known issues / caveat
- Actually the Gen Manager uses malloc() at every prepareToPlay(). A more clever version will be updated, handling with realloc(). 
- Not all the gen~ exported code APIs are yet implemented/exposed
