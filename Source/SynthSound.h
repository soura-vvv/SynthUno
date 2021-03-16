/*
  ==============================================================================

    SynthSound.h
    Created: 4 Feb 2021 6:00:10pm
    Author:  Sourav

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

//One of the sound that the synthesizer can play

class SynthSound : public juce::SynthesiserSound
{
public:
    bool appliesToNote(int midiNoteNumber) 
    {
        return true;
    }
    bool appliesToChannel(int midiChannel)
    {
        return true;
    }
    
};