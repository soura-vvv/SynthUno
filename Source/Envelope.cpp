/*
  ==============================================================================

    Envelope.cpp
    Created: 10 Mar 2021 5:48:58pm
    Author:  Sourav

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Envelope.h"

//==============================================================================
Envelope::Envelope(SynthFrameworkAudioProcessor& p):
    audioProcessor(p)

{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
     //Attack Slider
    setSize(200, 200);
    attackSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    attackSlider.setRange(0.1f, 5000.0f);
    attackSlider.setValue(0.1f);
    attackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 40, 10);
    attackSlider.onValueChange = [this] {std::cout << (attackSlider.getValue()) << std::endl; };
    addAndMakeVisible(attackSlider);
    attackTree = new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.parameters, "attackTime", attackSlider);

    //Sustain Slider
    sustainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    sustainSlider.setRange(0, 1);
    sustainSlider.setValue(0.8);
    sustainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 40, 10);
    sustainSlider.onValueChange = [this] {std::cout << (sustainSlider.getValue()); };
    addAndMakeVisible(sustainSlider);
    sustainTree = new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.parameters, "sustainTime", sustainSlider);

    //Decay Slider
    decaySlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    decaySlider.setRange(0.1, 5000.0);
    decaySlider.setValue(500);
    decaySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 40, 10);
    decaySlider.onValueChange = [this] {std::cout << (decaySlider.getValue()); };
    addAndMakeVisible(decaySlider);
    decayTree = new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.parameters, "decayTime", decaySlider);

    //Release Slider
    releaseSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    releaseSlider.setRange(0.1, 5000.0);
    releaseSlider.setValue(2000);
    releaseSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 40, 10);
    releaseSlider.onValueChange = [this] {std::cout << (releaseSlider.getValue()); };
    addAndMakeVisible(releaseSlider);
    releaseTree = new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.parameters, "releaseTime", releaseSlider);

}

Envelope::~Envelope()
{
}

void Envelope::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
    g.fillAll(juce::Colours::black);
}

void Envelope::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

    juce::Rectangle<int> area = getLocalBounds().reduced(40);
    attackSlider.setBounds(10, 10, 40, 100);
    sustainSlider.setBounds(50, 10, 40, 100);
    decaySlider.setBounds(100, 10, 40, 100);
    releaseSlider.setBounds(150, 10, 40, 100);
}
