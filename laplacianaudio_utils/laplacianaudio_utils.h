/** BEGIN_JUCE_MODULE_DECLARATION

    ID:             laplacianaudio_utils
    vendor:         Laplacian Audio
    version:        0.1.1
    name:           Laplacian Audio Utils
    description:    JUCE Utils by Laplacian Audio
    website:        https://laplacianaudio.com
    license:        GPLv3

    dependencies:

    END_JUCE_MODULE_DECLARATION
*/

#pragma once
#define LAPLACIANAUDIO_UTILS_H_INCLUDED

#include <juce_core/juce_core.h>
#include <juce_events/juce_events.h>

/** Laplacian Audio Utils Network */
#include "la_utils_network/LANetworkManager.h"

/** Laplacian GUI Utils */
#include "la_utils_gui/LAKnob.h"
#include "la_utils_gui/LAMainLookAndFeel.h"