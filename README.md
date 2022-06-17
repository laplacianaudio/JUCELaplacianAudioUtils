# Laplacian Audio JUCE Utils

## Description
Laplacian Audio JUCE Utils is a library of higher-level APIs in order to make life easier with certain JUCE tasks.

## Installation
Clone this repo and import the moudule (folder) 'laplacianaudio_utils' from your Projucer project.

## How to use
ATM the following namespaces are available:
- la_utils_network

<br />

Create an instance of a class like the following:
- la_utils_network::LANetworkManager mNetworkManager 

Be sure to call the prepare method of every DSP module in the PluginProcessor.cpp's prepare method!


## License
JUCELaplacianAudioUtils is licensed under the GNU General Public License (GPLv3) agreement.
