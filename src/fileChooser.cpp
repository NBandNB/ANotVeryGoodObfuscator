#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include "../include/Graphical.h"

void GUI::on_button_savePlainText()
{
	QString fileName = QFileDialog::getSaveFileName(this, "Please choose a file", QDir::homePath(), "Text Files (*.txt);;All Files (*.*)");
	if(fileName.isEmpty())
        return;
    else{
        Files::writeToFile(fileName.toStdString(), plainText->toPlainText().toStdString());
    }
}

void GUI::on_button_loadPlainText()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Please choose a file", QDir::homePath(), "Text Files (*.txt);;All Files (*.*)");
    if(fileName.isEmpty())
        return;
    else{
        plainText->setText(QString::fromStdString(Files::readFromFile(fileName.toStdString())));;
    }
}

void GUI::on_button_loadObfuscatedText()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Please choose a file", QDir::homePath(), "Text Files (*.txt);;All Files (*.*)");
    if(fileName.isEmpty())
        return;
    else{
        obfustactedText->setText(QString::fromStdString(Files::readFromFile(fileName.toStdString())));
    }
}

void GUI::on_button_saveObfuscatedText()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Please choose a file", QDir::homePath(), "Text Files (*.txt);;All Files (*.*)");
    if(fileName.isEmpty())
        return;
    else{
        Files::writeToFile(fileName.toStdString(), obfustactedText->toPlainText().toStdString());
    }
}

/*void GUI::on_loadPlainText_dialog_response(int response_id, Gtk::FileChooserDialog* dialog)
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
}*/
