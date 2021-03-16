/*
  ==============================================================================

    Filter.h
    Created: 13 Mar 2021 2:36:36pm
    Author:  Sourav

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class Filter  : public juce::Component
{
public:
    Filter(SynthFrameworkAudioProcessor&);
    ~Filter() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    SynthFrameworkAudioProcessor& audioProcessor;
    juce::Slider filterCutOff;
    juce::Slider filterRes;
    juce::ComboBox filterType;
    juce::ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> filterCutOffTree;
    juce::ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> filterResTree;
    juce::ScopedPointer<juce::AudioProcessorValueTreeState::ComboBoxAttachment> filterTypeTree;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Filter)
};
