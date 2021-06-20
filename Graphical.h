#pragma once

#include <iostream>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/textview.h>
#include <gtkmm/box.h>
#include <gtkmm/scrolledwindow.h>
#include "Obfuscate.h"

class GUI : public Gtk::Window {

public:
	//Main Window
	GUI();
	~GUI() override; 
	 
protected:
	//Signal handlers:
	void on_button_savePlainText();
	void on_button_loadPlainText();
	void on_button_obfuscate();
	void on_button_deobfuscate();
	void on_button_loadObfuscatedText();
	void on_button_saveObfuscatedText();



	//Member widgets:
	Gtk::Box ButtonBox;
	Gtk::Box TextBox;
	Gtk::Box MainBox;

	Gtk::ScrolledWindow scrollObfuscated;
	Gtk::ScrolledWindow scrollPlain;

	Gtk::TextView plainText;
	Gtk::TextView obfustactedText;

	Glib::RefPtr<Gtk::TextBuffer> obfuscatedTextBuffer=Gtk::TextBuffer::create();
	Glib::RefPtr<Gtk::TextBuffer> plainTextBuffer=Gtk::TextBuffer::create();

	Gtk::Button savePlainText;
	Gtk::Button loadPlainText;
	Gtk::Button obfuscate;
	Gtk::Button deobfuscate; 
	Gtk::Button loadObfuscatedText;
	Gtk::Button saveObfuscatedText;

};