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

void GUI::on_button_savePlainText()
{
	auto dialog = new Gtk::FileChooserDialog("Please choose a file",
		Gtk::FileChooser::Action::OPEN);
	dialog->set_transient_for(*this);
	dialog->set_modal(true);
	dialog->signal_response().connect(sigc::bind(
		sigc::mem_fun(*this, &GUI::on_savePlainText_dialog_response), dialog));

	//Add response buttons to the dialog:
	dialog->add_button("_Cancel", Gtk::ResponseType::CANCEL);
	dialog->add_button("_Save", Gtk::ResponseType::OK);

	//Add filters, so that only certain file types can be selected:

	auto filter_text = Gtk::FileFilter::create();
	filter_text->set_name(".txt files");
	filter_text->add_mime_type("text/plain");
	filter_text->add_pattern("*.txt");
	dialog->add_filter(filter_text);

	auto filter_text_loose = Gtk::FileFilter::create();
	filter_text_loose->set_name("All Text files");
	filter_text_loose->add_mime_type("text/plain");
	dialog->add_filter(filter_text_loose);

	auto filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog->add_filter(filter_any);

	//Show the dialog and wait for a user response:
	dialog->show();
}

void GUI::on_button_loadPlainText()
{
	auto dialog = new Gtk::FileChooserDialog("Please choose a file",
		Gtk::FileChooser::Action::OPEN);
	dialog->set_transient_for(*this);
	dialog->set_modal(true);
	dialog->signal_response().connect(sigc::bind(
		sigc::mem_fun(*this, &GUI::on_loadPlainText_dialog_response), dialog));

	//Add response buttons to the dialog:
	dialog->add_button("_Cancel", Gtk::ResponseType::CANCEL);
	dialog->add_button("_Open", Gtk::ResponseType::OK);

	//Add filters, so that only certain file types can be selected:

	auto filter_text = Gtk::FileFilter::create();
	filter_text->set_name(".txt files");
	filter_text->add_mime_type("text/plain");
	filter_text->add_pattern("*.txt");
	dialog->add_filter(filter_text);

	auto filter_text_loose = Gtk::FileFilter::create();
	filter_text_loose->set_name("All Text files");
	filter_text_loose->add_mime_type("text/plain");
	dialog->add_filter(filter_text_loose);

	auto filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog->add_filter(filter_any);

	//Show the dialog and wait for a user response:
	dialog->show();
}

void GUI::on_button_obfuscate()
{
	obfuscatedTextBuffer->set_text(Obfuscate::Obfuscator::Obfuscate(1, plainTextBuffer->get_text()));
}

void GUI::on_button_deobfuscate() {
	plainTextBuffer->set_text(Obfuscate::Obfuscator::Deobfuscate(1, obfuscatedTextBuffer->get_text()));
}

void GUI::on_button_loadObfuscatedText()
{
	auto dialog = new Gtk::FileChooserDialog("Please choose a file",
		Gtk::FileChooser::Action::OPEN);
	dialog->set_transient_for(*this);
	dialog->set_modal(true);
	dialog->signal_response().connect(sigc::bind(
		sigc::mem_fun(*this, &GUI::on_loadObfuscatedText_dialog_response), dialog));

	//Add response buttons to the dialog:
	dialog->add_button("_Cancel", Gtk::ResponseType::CANCEL);
	dialog->add_button("_Open", Gtk::ResponseType::OK);

	//Add filters, so that only certain file types can be selected:

	auto filter_text = Gtk::FileFilter::create();
	filter_text->set_name(".txt files");
	filter_text->add_mime_type("text/plain");
	filter_text->add_pattern("*.txt");
	dialog->add_filter(filter_text);

	auto filter_text_loose = Gtk::FileFilter::create();
	filter_text_loose->set_name("All Text files");
	filter_text_loose->add_mime_type("text/plain");
	dialog->add_filter(filter_text_loose);

	auto filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog->add_filter(filter_any);

	//Show the dialog and wait for a user response:
	dialog->show();
}

void GUI::on_button_saveObfuscatedText()
{
	auto dialog = new Gtk::FileChooserDialog("Please choose a file",
		Gtk::FileChooser::Action::OPEN);
	dialog->set_transient_for(*this);
	dialog->set_modal(true);
	dialog->signal_response().connect(sigc::bind(
		sigc::mem_fun(*this, &GUI::on_saveObfuscatedText_dialog_response), dialog));

	//Add response buttons to the dialog:
	dialog->add_button("_Cancel", Gtk::ResponseType::CANCEL);
	dialog->add_button("_Save", Gtk::ResponseType::OK);

	//Add filters, so that only certain file types can be selected:

	auto filter_text = Gtk::FileFilter::create();
	filter_text->set_name(".txt files");
	filter_text->add_mime_type("text/plain");
	filter_text->add_pattern("*.txt");
	dialog->add_filter(filter_text);

	auto filter_text_loose = Gtk::FileFilter::create();
	filter_text_loose->set_name("All Text files");
	filter_text_loose->add_mime_type("text/plain");
	dialog->add_filter(filter_text_loose);

	auto filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog->add_filter(filter_any);

	//Show the dialog and wait for a user response:
	dialog->show();
}

void GUI::on_loadPlainText_dialog_response(int response_id, Gtk::FileChooserDialog* dialog)
{
	//Handle the response:
	switch (response_id)
	{
	case Gtk::ResponseType::OK:
	{
		std::cout << "Open clicked." << std::endl;

		//Notice that this is a std::string, not a Glib::ustring.
		auto filename = dialog->get_file()->get_path();
		std::cout << "File selected: " << filename << std::endl;
		plainTextBuffer->set_text(Files::readFromFile(filename));
		break;
	}
	case Gtk::ResponseType::CANCEL:
	{
		std::cout << "Cancel clicked." << std::endl;
		break;
	}
	default:
	{
		std::cout << "Unexpected button clicked." << std::endl;
		break;
	}
	}
	delete dialog;
}

void GUI::on_savePlainText_dialog_response(int response_id, Gtk::FileChooserDialog* dialog)
{
	//Handle the response:
	switch (response_id)
	{
	case Gtk::ResponseType::OK:
	{
		std::cout << "Open clicked." << std::endl;

		//Notice that this is a std::string, not a Glib::ustring.
		auto filename = dialog->get_file()->get_path();
		std::cout << "File selected: " << filename << std::endl;
		Files::writeToFile(filename, plainTextBuffer->get_text());
		break;
	}
	case Gtk::ResponseType::CANCEL:
	{
		std::cout << "Cancel clicked." << std::endl;
		break;
	}
	default:
	{
		std::cout << "Unexpected button clicked." << std::endl;
		break;
	}
	}
	delete dialog;
}

void GUI::on_loadObfuscatedText_dialog_response(int response_id, Gtk::FileChooserDialog* dialog)
{
	//Handle the response:
	switch (response_id)
	{
	case Gtk::ResponseType::OK:
	{
		std::cout << "Open clicked." << std::endl;

		//Notice that this is a std::string, not a Glib::ustring.
		auto filename = dialog->get_file()->get_path();
		std::cout << "File selected: " << filename << std::endl;
		obfuscatedTextBuffer->set_text(Files::readFromFile(filename));
		break;
	}
	case Gtk::ResponseType::CANCEL:
	{
		std::cout << "Cancel clicked." << std::endl;
		break;
	}
	default:
	{
		std::cout << "Unexpected button clicked." << std::endl;
		break;
	}
	}
	delete dialog;
}

void GUI::on_saveObfuscatedText_dialog_response(int response_id, Gtk::FileChooserDialog* dialog)
{
	//Handle the response:
	switch (response_id)
	{
	case Gtk::ResponseType::OK:
	{
		std::cout << "Open clicked." << std::endl;

		//Notice that this is a std::string, not a Glib::ustring.
		auto filename = dialog->get_file()->get_path();
		std::cout << "File selected: " << filename << std::endl;
		Files::writeToFile(filename, obfuscatedTextBuffer->get_text());
		break;
	}
	case Gtk::ResponseType::CANCEL:
	{
		std::cout << "Cancel clicked." << std::endl;
		break;
	}
	default:
	{
		std::cout << "Unexpected button clicked." << std::endl;
		break;
	}
	}
	delete dialog;
}
