/*
  ==============================================================================

    TabbedComponentWithMenu.h
    Created: 17 Feb 2016 10:47:20am
    Author:  Spindler

  ==============================================================================
*/

#ifndef TABBEDCOMPONENTWITHMENU_H_INCLUDED
#define TABBEDCOMPONENTWITHMENU_H_INCLUDED

#include "JuceHeader.h"

//==============================================================================
/*
*/
class TabbedComponentWithMenu : public TabbedComponent
{
public:
	TabbedComponentWithMenu() : TabbedComponent(TabbedButtonBar::TabsAtTop)
    {
		m_tabbedButtonBarWithmenuLookAndFeel = new TabbedButtonBarWithMenuLookAndFeel();
		tabs->setLookAndFeel(m_tabbedButtonBarWithmenuLookAndFeel);
		addTab(String(CharPointer_UTF8("\xe2\x89\xa1")), Colours::whitesmoke, nullptr, true);
		setSize(640, 480);
    }

    ~TabbedComponentWithMenu()
    {
		tabs->setLookAndFeel(&LookAndFeel::getDefaultLookAndFeel());
    }

	virtual void paint(Graphics& g) override
    {
		TabbedComponent::paint(g);
    }

    virtual void resized() override
    {
		TabbedComponent::resized();
    }

	// overriden, to revert switching to menu "tab"
	void currentTabChanged(int newCurrentTabIndex, const String &newCurrentTabName) override
	{
		if (newCurrentTabIndex == 0)
		{
			if (m_currentTabIndex < 0 && getNumTabs()>1) m_currentTabIndex = 1;
			setCurrentTabIndex(m_currentTabIndex);
		}
		else
		{
			TabbedComponent::currentTabChanged(newCurrentTabIndex, newCurrentTabName);
			m_currentTabIndex = newCurrentTabIndex;
		}
	}

	// returns the menu button, to register a listener
	Button* getMenuButton() const { return tabs->getTabButton(0); }

private:
	int m_currentTabIndex = -1;

	class TabbedButtonBarWithMenuLookAndFeel : public LookAndFeel_V3
	{
		int getTabButtonBestWidth(TabBarButton& button, int tabDepth) override
		{
			if (button.getIndex() == 0 && button.getButtonText() == CharPointer_UTF8("\xe2\x89\xa1"))
			{
				return jmax<int>(Font(tabDepth * 0.8f).getStringWidth(button.getButtonText().trim()) + getTabButtonOverlap(tabDepth) * 2, tabDepth);
			}
			else
			{
				return LookAndFeel_V3::getTabButtonBestWidth(button, tabDepth);
			}
		}
	};

	ScopedPointer<TabbedButtonBarWithMenuLookAndFeel> m_tabbedButtonBarWithmenuLookAndFeel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabbedComponentWithMenu)
};


#endif  // TABBEDCOMPONENTWITHMENU_H_INCLUDED
