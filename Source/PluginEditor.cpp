/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthFrameworkAudioProcessorEditor::SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p),OscGui(p),EnvGui(p),FilterGui(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    setSize (600, 200);
    addAndMakeVisible(OscGui);
    addAndMakeVisible(EnvGui);
    addAndMakeVisible(FilterGui);
    /*
    //Attack Slider
    attackSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    attackSlider.setRange(0.1f, 5000.0f);
    attackSlider.setValue(0.1f);
    attackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 40, 10);
    attackSlider.onValueChange = [this] {std::cout<<(attackSlider.getValue())<<std::endl;};
    addAndMakeVisible(attackSlider);
    attackTree = new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.parameters, "attackTime", attackSlider);

    //Sustain Slider
    sustainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    sustainSlider.setRange(0,1);
    sustainSlider.setValue(0.8);
    sustainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 40, 10);
    sustainSlider.onValueChange = [this] {std::cout << (sustainSlider.getValue()); };
    addAndMakeVisible(sustainSlider);
    sustainTree = new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.parameters, "sustainTime", sustainSlider);

    //Decay Slider
    decaySlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    decaySlider.setRange(0.1,5000.0);
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
    */

    
}

SynthFrameworkAudioProcessorEditor::~SynthFrameworkAudioProcessorEditor()
{
}

//==============================================================================
void SynthFrameworkAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("SynthUno", getLocalBounds(), juce::Justification::centred, 1);
}

void SynthFrameworkAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    juce::Rectangle<int> area = getLocalBounds();
    const int componentWidth = 200;
    const int componentHeight = 200;
    OscGui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    EnvGui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    FilterGui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    /*

*/
}
/*
void SynthFrameworkAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &attackSlider)
        attackTime = attackSlider.getValue();
    
    

}*/