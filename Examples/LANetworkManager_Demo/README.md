# LANetworkManager Example

## Description
This is a basic example for the Laplacian Audio JUCE Network Manager (Work-In-Progress)

## How to use
- Start the Backend (BE), located inside the BE folder. The BE is a NodeJS/Express application
- Open the Projucer project, compile and run it

## How to start the backend
- Install Node/npm on your machine
- In BE folder, install the dependencies with the command 'npm i'
- Start the BE with the command 'node ./server.js' (BE will listen on localhost, port 3000)

This Example will show a way to query a BE and know if updates for your application/plugin are available.
You could implement your own BE, parsing JSON instead of String responses, and so on. 
This would be a starting point/exmaple in order to do Network Requests with Juce.
