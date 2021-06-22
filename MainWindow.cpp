#include "Graphical.h"

GUI::GUI()
:
	//Add all widgets to Window 
	MainBox(Gtk::Orientation::HORIZONTAL),
	TextBox(Gtk::Orientation::VERTICAL),
	ButtonBox(Gtk::Orientation::VERTICAL),
	savePlainText("Save Plain Text"),
	loadPlainText("Load Plain Text"),
	obfuscate("Obfuscate"),
	deobfuscate("Deobfuscate"),
	loadObfuscatedText("Load Obfuscated Text"),
	saveObfuscatedText("Save Obfuscated Text")
{
	set_title("Obfuscator");
	set_default_size(500, 250);

	//Create and set up Main Box
	MainBox.set_margin(5);
	set_child(MainBox);
	//Create and set up Text Boxes
	TextBox.set_size_request(200, 100);
	MainBox.append(TextBox);
	
	//Set up the Plain Text Box
	scrollPlain.set_child(plainText);

	scrollPlain.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
	scrollPlain.set_expand();

	plainText.set_buffer(plainTextBuffer);

	scrollPlain.set_margin_bottom(2.5);

	TextBox.append(scrollPlain);


	//Set up the Obfuscated Text Box
	scrollObfuscated.set_child(obfustactedText);

	scrollObfuscated.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
	scrollObfuscated.set_expand();

	obfustactedText.set_buffer(obfuscatedTextBuffer);

	scrollObfuscated.set_margin_top(2.5);

	TextBox.append(scrollObfuscated);

	//Create and set up Buttons
	ButtonBox.set_margin_start(5);
	ButtonBox.set_size_request(50, 100);
	ButtonBox.set_spacing(5);

	//Add the button box to the main box
	MainBox.append(ButtonBox);

	//Add all the buttons to the window
	ButtonBox.append(savePlainText);
	ButtonBox.append(loadPlainText);
	ButtonBox.append(obfuscate);
	ButtonBox.append(deobfuscate);
	ButtonBox.append(loadObfuscatedText);
	ButtonBox.append(saveObfuscatedText);

	//Button Handlers
	savePlainText.signal_clicked().connect(sigc::mem_fun(*this, &GUI::on_button_savePlainText));
	loadPlainText.signal_clicked().connect(sigc::mem_fun(*this, &GUI::on_button_loadPlainText));
	obfuscate.signal_clicked().connect(sigc::mem_fun(*this, &GUI::on_button_obfuscate));
	deobfuscate.signal_clicked().connect(sigc::mem_fun(*this, &GUI::on_button_deobfuscate));
	saveObfuscatedText.signal_clicked().connect(sigc::mem_fun(*this, &GUI::on_button_saveObfuscatedText));
	loadObfuscatedText.signal_clicked().connect(sigc::mem_fun(*this, &GUI::on_button_loadObfuscatedText));
}

GUI::~GUI()
{
}

void GUI::on_button_obfuscate()
{
	obfuscatedTextBuffer->set_text(Obfuscate::Obfuscator::Obfuscate(1, plainTextBuffer->get_text()));
}

void GUI::on_button_deobfuscate() {
	plainTextBuffer->set_text(Obfuscate::Obfuscator::Deobfuscate(1, obfuscatedTextBuffer->get_text()));
}

