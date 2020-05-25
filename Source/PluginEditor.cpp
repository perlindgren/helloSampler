/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
HelloSamplerAudioProcessorEditor::HelloSamplerAudioProcessorEditor(HelloSamplerAudioProcessor &p)
    : AudioProcessorEditor(&p), mWaveThumbnail(p), mADSR(p), processor(p)
{
    auto tapImage = ImageCache::getFromMemory(BinaryData::TAP_png, BinaryData::TAP_pngSize);

    if (!tapImage.isNull())
        mImageComponent.setImage(tapImage, RectanglePlacement::stretchToFit);
    else
        jassert(!tapImage.isNull());

    addAndMakeVisible(mWaveThumbnail);
    addAndMakeVisible(mADSR);
    addAndMakeVisible(mImageComponent);
    addAndMakeVisible(mLoadButton);
    mLoadButton.setButtonText("Load");
    mLoadButton.onClick = [&] { p.loadFile(); };
    //playButton.setColour(TextButton::buttonColourId, Colours::green);
    //playButton.setEnabled(false);FaceA
    startTimerHz(30);

    setSize(600, 400);
}

HelloSamplerAudioProcessorEditor::~HelloSamplerAudioProcessorEditor()
{
    stopTimer();
}

//==============================================================================
void HelloSamplerAudioProcessorEditor::paint(Graphics &g)
{
    g.fillAll(Colours::black);
}

void HelloSamplerAudioProcessorEditor::resized()
{
    mWaveThumbnail.setBoundsRelative(0.0f, 0.25f, 1.0f, 0.5);
    mADSR.setBoundsRelative(0.0f, 0.75f, 1.0f, 0.25f);
    mLoadButton.setBoundsRelative(0.0f, 0.75, 0.25, 0.25);
    mImageComponent.setBoundsRelative(0.0f, 0.0f, 0.5f, 0.25f);
}

void HelloSamplerAudioProcessorEditor::timerCallback()
{
    repaint();
}
