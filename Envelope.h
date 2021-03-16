/*
  ==============================================================================

    Envelope.h
    Created: 10 Mar 2021 5:48:58pm
    Author:  Sourav

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class Envelope  : public juce::Component
{
public:
    Envelope(SynthFrameworkAudioProcessor&);
    ~Envelope() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    juce::Slider attackSlider;
    juce::Slider sustainSlider;
    juce::Slider decaySlider;
    juce::Slider releaseSlider;
    juce::ScopedPointer <juce::AudioProcessorValueTreeState::SliderAttachment> attackTree;
    juce::ScopedPointer <juce::AudioProcessorValueTreeState::SliderAttachment> sustainTree;
    juce::ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> decayTree;
    juce::ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> releaseTree;
private:
    SynthFrameworkAudioProcessor& audioProcessor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope)
};
