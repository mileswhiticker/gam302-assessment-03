#include "GUIManager.hpp"

#include <SFGUI/SFGUI.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFGUI\Desktop.hpp>

GUIManager::GUIManager()
:	m_psfgui(new sfg::SFGUI())
,	m_pDesktop(new sfg::Desktop())
//,	m_RenderWindow(a_RenderWindow)
{
	//m_Desktop.UpdateViewRect(a_RenderWindow.getDefaultView().getViewport());
	//CreateNewWindow(sf::Vector2f(0.1f,0.1f), sf::Vector2f(0.2f,0.2f));
	//sfg::Window::Ptr window( sfg::Window::Create() );
	//m_pDesktop->Add(window);
	CreateNewWindow();
}

void GUIManager::Update(float a_Dt)
{
	//m_Desktop.Update(a_Dt);
	m_pDesktop->Update(a_Dt);
}

void GUIManager::RenderGui(sf::RenderWindow& a_RenderWindow)
{
	m_psfgui->Display(a_RenderWindow);
}

void GUIManager::CreateNewWindow(sf::Vector2f a_Scale1, sf::Vector2f a_Scale2)
{
	//*
	// Create a new window.
	sfg::Window::Ptr window( sfg::Window::Create() );
	/*window->SetTitle( "new window" );

	// Widgets.
	sfg::Button::Ptr destroy_button( sfg::Button::Create( "Destroy" ) );
	sfg::Button::Ptr front_button( sfg::Button::Create( "Main window to front" ) );

	// Layout.
	sfg::Box::Ptr box( sfg::Box::Create( sfg::Box::VERTICAL, 5.f ) );
	box->Pack( sfg::Label::Create( "This is a newly created window, from runtime, interactively." ), false );
	box->Pack( sfg::Label::Create( "You can move me around, try it!" ), false );
	box->Pack( sfg::Label::Create( "Or click the button below to destroy me. :-(" ), false );
	box->Pack( destroy_button, false );
	box->Pack( front_button, false );
	
	window->Add( box );*/
	m_pDesktop->Add( window );
	//m_Desktop.SetProperty( "Button#create_window > Label", "FontSize", 18.f );

	// Signals.
	//destroy_button->OnLeftClick.Connect( &DesktopExample::OnDestroyWindowClick, this );
	//front_button->OnLeftClick.Connect( &DesktopExample::OnFrontClick, this );
	//*/
}

void GUIManager::HandleEvent(sf::Event a_Event)
{
	//m_pDesktop->HandleEvent(a_Event);
}

void GUIManager::AddWidget(sfg::SharedPtr<sfg::Widget> a_Widget)
{
	//m_pDesktop->Add(a_Widget);
}

sfg::WeakPtr<sfg::Desktop> GUIManager::GetDesktop()
{
	//sfg::WeakPtr<sfg::Desktop> out = m_pDesktop;
	//return out;
	//return sfg::SharedPtr<sfg::Desktop>(&m_Desktop);
	return sfg::SharedPtr<sfg::Desktop>(m_pDesktop);
}
