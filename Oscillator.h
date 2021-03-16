/*
  ==============================================================================

    Oscillator.h
    Created: 10 Mar 2021 4:03:55pm
    Author:  Sourav

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class Oscillator  : public juce::Component
{
public:
    Oscillator(SynthFrameworkAudioProcessor&);
    ~Oscillator() override;

    void paint (juce::Graphics&) override;
    void resized() override;

 

private:  
    SynthFrameworkAudioProcessor& audioProcessor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Oscillator)
        juce::ComboBox oscMenu;
    //juce::ScopedPointer<juce::AudioProcessorValueTreeState> oscTree;
    juce::ScopedPointer<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscTree;
};
