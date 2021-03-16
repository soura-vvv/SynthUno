/*
  ==============================================================================

    SynthVOice.h
    Created: 4 Feb 2021 6:00:32pm
    Author:  Sourav

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"
#include "maximilian.h"
class SynthVoice : public juce::SynthesiserVoice
{
public:
    bool canPlaySound(juce::SynthesiserSound *sound) override
    {
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }
    void getParam(std::atomic<float>* attack,std::atomic<float>* sustain, std::atomic<float>* decay, std::atomic<float>* release)
    {
        env1.setAttack(*attack);
        env1.setSustain(*sustain);
        env1.setDecay(*decay);
        env1.setRelease(*release);
    }
    double setADSR()
    {
        return env1.adsr(setOscType(), env1.trigger) * level;
    }
    void getOscType(std::atomic<float>* waveType)
    {
        theWave = (int)*waveType;
    }
    double setOscType()
    {
        switch (theWave)
        {
        case 0:return osc1.sinewave(frequency) * level;
        case 1:return osc1.saw(frequency) * level;
        case 2:return osc1.square(frequency) * level;
        default: return osc1.sinewave(frequency) * level;

        }
    }
    double setFilter()
    {
        switch (filterChoice)
        {
        case 0:return filter1.lores(setADSR(), cutOff,resonance);
        case 1:return filter1.hires(setADSR(), cutOff, resonance);
        case 2:return filter1.bandpass(setADSR(), cutOff,resonance);
        default: return filter1.lores(setADSR(), cutOff,resonance);

        }
    }
    void getFilterParam(std::atomic<float>* filterType,std::atomic<float>* filterCutOff,std::atomic<float>* filterRes)

    {
        filterChoice = (int)*filterType;
        cutOff = *filterCutOff;
        resonance = *filterRes;

    }
    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override
    {
        env1.trigger = 1;
        level = velocity;
        frequency = juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        DBG(midiNoteNumber);
    }

    void stopNote(float velocity, bool allowTailOff) override
    {
        env1.trigger = 0;
        allowTailOff = true;
        if(velocity==0)
            clearCurrentNote();
       
    }

    void pitchWheelMoved(int newPitchWheelValue) override
    {

    }

    void controllerMoved(int controllerNumber, int newControllerValue) override
    {

    }

    void renderNextBlock(juce::AudioBuffer<float> &outputBuffer,int startSample,int numSamples) override//Like Process Block, Majority of DSP Code
    {
       
       // env1.setDecay(500);
        //env1.setSustain(0.8);//0----1
        //env1.setRelease(2000);


        
       
        for (int sample = 0; sample < numSamples; ++sample)
        {
            //double theWave = osc1.saw(frequency)*level;
            //double theSound = 
            level = 0.5;
            //double filteredSound = filter1.lores(theSound,500,0.1);
            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
            {

                outputBuffer.addSample(channel, startSample, setFilter()*level);
            }
            ++startSample;
        }
    }
private:
    double level=0.5;
    double frequency;
    maxiOsc osc1;
    maxiEnv env1;
    maxiFilter filter1;
    int theWave;
    int filterChoice;
    float cutOff;
    float resonance;

};