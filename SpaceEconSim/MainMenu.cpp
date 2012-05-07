#include "MainMenu.hpp"
#include "GUIManager.hpp"

#include <SFGUI\Button.hpp>

MainMenu::MainMenu(GUIManager& a_GUIMgr)
:	Scene(a_GUIMgr)
{
	/*
	// Create a new window.
	sfg::Window::Ptr window( sfg::Window::Create() );
	window->SetTitle( "new window" );

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
	
	window->Add( box );
	m_Desktop.Add( window );
	m_Desktop.SetProperty( "Button#create_window > Label", "FontSize", 18.f );

	// Signals.
	destroy_button->OnLeftClick.Connect( &DesktopExample::OnDestroyWindowClick, this );
	front_button->OnLeftClick.Connect( &DesktopExample::OnFrontClick, this );
	*/
	//sfg::Button::Ptr quit_button( sfg::Button::Create( "Quit" ) );
	//a_GUIMgr.AddWidget(quit_button);
	//a_GUIMgr.CreateNewWindow(sf::Vector2f(0.1f,0.1f), sf::Vector2f(0.2f,0.2f));
	//a_GUIMgr.CreateNewWindow(sf::Vector2f(0.1f,0.1f), sf::Vector2f(0.2f,0.2f));
	//a_GUIMgr.CreateNewWindow(sf::Vector2f(0.1f,0.1f), sf::Vector2f(0.2f,0.2f));

	//exit button
}

void MainMenu::Quit()
{
	//
}
