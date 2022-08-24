#include "../include/Graphical.h"

GUI::GUI(QWidget *parent)
    : QMainWindow(parent),
	//Add all widgets to Window 
	MainBox(new QHBoxLayout()),
	TextBox(new QVBoxLayout()),
	ButtonBox(new QVBoxLayout()),
	savePlainText(new QPushButton("Save Plain Text")),
	loadPlainText(new QPushButton("Load Plain Text")),
	obfuscate(new QPushButton("Obfuscate")),
	deobfuscate(new QPushButton("Deobfuscate")),
	loadObfuscatedText(new QPushButton("Load Obfuscated Text")),
	saveObfuscatedText(new QPushButton("Save Obfuscated Text")),
    plainText(new QTextEdit()),
    obfustactedText(new QTextEdit())
{
	setWindowTitle("Obfuscator");
	setMinimumSize(500, 250);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
	//Create and set up Main Box
	MainBox->setMargin(5);
	centralWidget->setLayout(MainBox);
	//Create and set up Text Boxes
	//TextBox->setMinim;
	MainBox->addLayout(TextBox);
	
	TextBox->setSpacing(5);

	TextBox->addWidget(plainText);

	TextBox->addWidget(obfustactedText);

	//Create and set up Buttons
	ButtonBox->setMargin(5);
	//ButtonBox->setMinimumSize(50, 100);
	ButtonBox->setSpacing(5);

	//Add the button box to the main box
	MainBox->addLayout(ButtonBox);

	//Add all the buttons to the window
	ButtonBox->addWidget(savePlainText);
	ButtonBox->addWidget(loadPlainText);
	ButtonBox->addWidget(obfuscate);
	ButtonBox->addWidget(deobfuscate);
	ButtonBox->addWidget(loadObfuscatedText);
	ButtonBox->addWidget(saveObfuscatedText);

	//Button Handlers
    QObject::connect(savePlainText, SIGNAL(clicked()), this, SLOT(on_button_savePlainText()));
    QObject::connect(loadPlainText, SIGNAL(clicked()), this, SLOT(on_button_loadPlainText()));
    QObject::connect(obfuscate, SIGNAL(clicked()), this, SLOT(on_button_obfuscate()));
    QObject::connect(deobfuscate, SIGNAL(clicked()), this, SLOT(on_button_deobfuscate()));
    QObject::connect(loadObfuscatedText, SIGNAL(clicked()), this, SLOT(on_button_loadObfuscatedText()));
    QObject::connect(saveObfuscatedText, SIGNAL(clicked()), this, SLOT(on_button_saveObfuscatedText()));

	//loadPlainText.signal_clicked().connect(sigc::mem_fun(*this, &GUI::on_button_loadPlainText));
	//obfuscate.signal_clicked().connect(sigc::mem_fun(*this, &GUI::on_button_obfuscate));
	//deobfuscate.signal_clicked().connect(sigc::mem_fun(*this, &GUI::on_button_deobfuscate));
	//saveObfuscatedText.signal_clicked().connect(sigc::mem_fun(*this, &GUI::on_button_saveObfuscatedText));
	//loadObfuscatedText.signal_clicked().connect(sigc::mem_fun(*this, &GUI::on_button_loadObfuscatedText));
}

GUI::~GUI()
{
}

void GUI::on_button_obfuscate()
{
	obfustactedText->setText(QString::fromStdString(Obfuscate::Obfuscator::Obfuscate(1, plainText->toPlainText().toStdString())));
}

void GUI::on_button_deobfuscate() {
	plainText->setText(QString::fromStdString(Obfuscate::Obfuscator::Deobfuscate(1, obfustactedText->toPlainText().toStdString())));
}

