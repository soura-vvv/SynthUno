/*
  ==============================================================================

    Filter.cpp
    Created: 13 Mar 2021 2:36:36pm
    Author:  Sourav

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Filter.h"

//==============================================================================
Filter::Filter(SynthFrameworkAudioProcessor& p):
    audioProcessor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    setSize(200, 200);

    filterCutOffTree = new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.parameters,"filterCutOff",filterCutOff);
    filterResTree = new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.parameters, "filterRes", filterRes);
    filterTypeTree = new::juce::AudioProcessorValueTreeState::ComboBoxAttachment(audioProcessor.parameters, "filterType", filterType);

    filterType.addItem("LowRes",1);
    filterType.addItem("HighRes",2);
    filterType.addItem("bandpass", 3);
    filterType.setJustificationType(juce::Justification::centred);

    filterCutOff.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    filterCutOff.setRange(20, 20000);
    filterCutOff.setValue(400.0);
    filterCutOff.setTextBoxStyle(juce::Slider::NoTextBox, false, 0,0);
    filterCutOff.setSkewFactorFromMidPoint(2000.0);//Makes it Logarithmic
    filterRes.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    filterRes.setRange(0.0, 1.0);
    filterRes.setValue(0.0);
    filterRes.setTextBoxStyle(juce::Slider::NoTextBox, false, 0,0);



    addAndMakeVisible(filterType);
    addAndMakeVisible(filterCutOff);
    addAndMakeVisible(filterRes);




}

Filter::~Filter()
{
}

void Filter::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll(juce::Colours::black);
}

void Filter::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    juce::Rectangle<int> area = getLocalBounds().reduced(40);
    filterType.setBounds(area.removeFromTop(20));
    filterCutOff.setBounds(30, 100, 70, 70);
    filterRes.setBounds(100, 100, 70, 70);

}
