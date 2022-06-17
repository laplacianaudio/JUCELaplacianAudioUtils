# Laplacian Audio JUCE Utils

## Description
Laplacian Audio JUCE Utils is a library of higher-level APIs in order to make life easier with certain JUCE tasks.

## Installation
Clone this repo and import the module (folder) 'laplacianaudio_utils' into your Projucer project.

## How to use
ATM the following namespaces are available:
- la_utils_network

## Examples
By now, you can find a working example for the LANetworkManager class. You can look inside the 'Examples' 
folder.

<br />

Create an instance of a class like the following:
- la_utils_network::LANetworkManager mNetworkManager 

Be sure to call the prepare method of every DSP module in the PluginProcessor.cpp's prepare method!


## License
JUCELaplacianAudioUtils is licensed under the GNU General Public License (GPLv3) agreement.
