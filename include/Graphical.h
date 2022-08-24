#pragma once

#include <iostream>
#include "Obfuscate.h"
#include <QMainWindow>
#include <QTextEdit>
#include "FileHandler.h"
#include <QPushButton>
#include <QBoxLayout>

class GUI : public QMainWindow {

Q_OBJECT
public:
	//Main Window
	GUI(QWidget *parent = nullptr);
	~GUI() override; 
	 
protected slots:
	//Signal handlers:
	void on_button_savePlainText();
	void on_button_loadPlainText();
	void on_button_obfuscate();
	void on_button_deobfuscate();
	void on_button_loadObfuscatedText();
	void on_button_saveObfuscatedText();

	//File Loaders and savers
	//void on_loadPlainText_dialog_response(int response_id, Gtk::FileChooserDialog* dialog);
	//void on_savePlainText_dialog_response(int response_id, Gtk::FileChooserDialog* dialog);
	//void on_loadObfuscatedText_dialog_response(int response_id, Gtk::FileChooserDialog* dialog);
	//void on_saveObfuscatedText_dialog_response(int response_id, Gtk::FileChooserDialog* dialog);

private:
	//Member widgets:
	QBoxLayout *ButtonBox;
	QBoxLayout *TextBox;
	QBoxLayout *MainBox;

	QTextEdit *plainText;
	QTextEdit *obfustactedText;

	QPushButton *savePlainText;
	QPushButton *loadPlainText;
	QPushButton *obfuscate;
	QPushButton *deobfuscate;
	QPushButton *loadObfuscatedText;
	QPushButton *saveObfuscatedText;
};