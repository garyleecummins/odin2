#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../GlobalIncludes.h"
#define INLAY_DEFAULT_SPECDRAW 2

#define DRAW_INLAY_LEFT_SPEC 7
#define DRAW_INLAY_RIGHT_SPEC 6
#define DRAW_INLAY_UP_SPEC 7
#define DRAW_INLAY_DOWN_SPEC 6
#define SPECDRAW_THICCNESS 4
#define DISPLAY_WIDTH_SPEC 205

class SpecdrawDisplay : public Component, public SettableTooltipClient {
public:
	SpecdrawDisplay();
	~SpecdrawDisplay();

	void paint(Graphics &) override;
	void setInlay(int p_inlay) {
		m_inlay = p_inlay;
	}
	void setColor(juce::Colour p_color) {
		m_color = p_color;
	}
	void setDrawColor(juce::Colour p_draw_color) {
		m_draw_color = p_draw_color;
	}

	void mouseDrag(const MouseEvent &event) override;
	void mouseDown(const MouseEvent &event) override;
	void mouseUp(const MouseEvent &event) override;
	void mouseInteraction();

	float *getDrawnTable();

	void setDrawnTable(float p_table[SPECDRAW_STEPS_X]) {
		for (int i = 0; i < SPECDRAW_STEPS_X; ++i) {
			//DBG(p_table[i]);
			m_draw_values[i] = p_table[i];
		}
		repaint();
	}

	std::function<void()> onDraw = []() {};
	void setGUIBig();
	void setGUISmall();

private:
	bool m_GUI_big = false;
	int m_inlay    = INLAY_DEFAULT_SPECDRAW;
	juce::Image m_glaspanel;
	juce::Colour m_color      = juce::Colours::black;
	juce::Colour m_draw_color = juce::Colours::white;

	bool m_mouse_was_down = false;
	int m_last_x_value;
	float m_last_y_value;
	float m_draw_values[SPECDRAW_STEPS_X] = {1.f, 0.f, 0.f};

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SpecdrawDisplay)
};