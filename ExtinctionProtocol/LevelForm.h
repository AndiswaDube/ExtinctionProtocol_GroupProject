#pragma once
#include "Question.h"
#include "global.h"
#include "QuestionForm.h"
#include "AccessCode.h"

namespace ExtinctionProtocol {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class LevelForm : public System::Windows::Forms::Form
	{
	public:
		LevelForm(void)
		{
			InitializeComponent();
			//
			// Get story text from getStoryLine() method
			fullStoryline = gcnew System::String(chapters[currLevel].getStoryLine().c_str());

			// Initialize variables
			currentCharIndex = 0;
			lblStoryline->Text = ""; // Clear label initially

			// Configure Timer
			tmrStory->Interval = 50; // Speed of typing effect (adjust as needed)
			tmrStory->Tick += gcnew System::EventHandler(this, &LevelForm::tmrStory_Tick);

			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LevelForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^ lblLevel;


	private: System::Windows::Forms::Button^ button1;

	public: System::Windows::Forms::Label^ lblStoryline;
	public: System::Windows::Forms::PictureBox^ pbxLevel;
	private: System::Windows::Forms::Timer^ tmrStory;
	private: System::Windows::Forms::Panel^ pnlLevelsback;
		   System::String^ fullStoryline; // Holds the complete story text
		   int currentCharIndex; // Tracks the current position of typing

	private: System::Windows::Forms::Panel^ panel1;
	public:

	public:

	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LevelForm::typeid));
			this->lblLevel = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->lblStoryline = (gcnew System::Windows::Forms::Label());
			this->pbxLevel = (gcnew System::Windows::Forms::PictureBox());
			this->tmrStory = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pnlLevelsback = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxLevel))->BeginInit();
			this->panel1->SuspendLayout();
			this->pnlLevelsback->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblLevel
			// 
			this->lblLevel->BackColor = System::Drawing::Color::Transparent;
			this->lblLevel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lblLevel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblLevel->ForeColor = System::Drawing::Color::White;
			this->lblLevel->Location = System::Drawing::Point(0, 0);
			this->lblLevel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblLevel->Name = L"lblLevel";
			this->lblLevel->Size = System::Drawing::Size(224, 94);
			this->lblLevel->TabIndex = 0;
			this->lblLevel->Text = L"Lvl 1";
			this->lblLevel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblLevel->Click += gcnew System::EventHandler(this, &LevelForm::lblLevel_Click);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 17, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(520, 746);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(282, 86);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Begin";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &LevelForm::button1_Click);
			// 
			// lblStoryline
			// 
			this->lblStoryline->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblStoryline->BackColor = System::Drawing::Color::Transparent;
			this->lblStoryline->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStoryline->ForeColor = System::Drawing::Color::White;
			this->lblStoryline->Location = System::Drawing::Point(15, 18);
			this->lblStoryline->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblStoryline->Name = L"lblStoryline";
			this->lblStoryline->Padding = System::Windows::Forms::Padding(75, 0, 75, 0);
			this->lblStoryline->Size = System::Drawing::Size(1318, 835);
			this->lblStoryline->TabIndex = 4;
			this->lblStoryline->Text = L"(Story line)";
			this->lblStoryline->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblStoryline->Visible = false;
			this->lblStoryline->Click += gcnew System::EventHandler(this, &LevelForm::button1_Click);
			// 
			// pbxLevel
			// 
			this->pbxLevel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pbxLevel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbxLevel.Image")));
			this->pbxLevel->Location = System::Drawing::Point(0, 0);
			this->pbxLevel->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pbxLevel->Name = L"pbxLevel";
			this->pbxLevel->Size = System::Drawing::Size(1330, 918);
			this->pbxLevel->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbxLevel->TabIndex = 5;
			this->pbxLevel->TabStop = false;
			this->pbxLevel->Click += gcnew System::EventHandler(this, &LevelForm::button1_Click);
			this->pbxLevel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &LevelForm::pbxLevel_Paint);
			// 
			// tmrStory
			// 
			this->tmrStory->Enabled = true;
			this->tmrStory->Interval = 1000;
			this->tmrStory->Tick += gcnew System::EventHandler(this, &LevelForm::tmrStory_Tick);
			// 
			// panel1
			// 
			this->panel1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->lblStoryline);
			this->panel1->Location = System::Drawing::Point(-9, 262);
			this->panel1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1350, 857);
			this->panel1->TabIndex = 7;
			// 
			// pnlLevelsback
			// 
			this->pnlLevelsback->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pnlLevelsback->BackColor = System::Drawing::Color::Transparent;
			this->pnlLevelsback->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlLevelsback.BackgroundImage")));
			this->pnlLevelsback->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pnlLevelsback->Controls->Add(this->lblLevel);
			this->pnlLevelsback->Location = System::Drawing::Point(554, 100);
			this->pnlLevelsback->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pnlLevelsback->Name = L"pnlLevelsback";
			this->pnlLevelsback->Size = System::Drawing::Size(224, 94);
			this->pnlLevelsback->TabIndex = 6;
			// 
			// LevelForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1330, 918);
			this->Controls->Add(this->pnlLevelsback);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pbxLevel);
			this->DoubleBuffered = true;
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"LevelForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Level";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &LevelForm::LevelForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &LevelForm::LevelForm_Paint);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxLevel))->EndInit();
			this->panel1->ResumeLayout(false);
			this->pnlLevelsback->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (chapters[currLevel].hasNextQuestion()) {
			Question currQues = chapters[currLevel].getNextQuestion();

			QuestionForm^ secondForm = gcnew QuestionForm();
			secondForm->BackgroundImage = Image::FromFile(gcnew String(currQues.getImagePath().c_str()));
			secondForm->pbxQuestion->Image = Image::FromFile(gcnew String(currQues.getImagePath().c_str()));
			secondForm->lblQuestion->Text = gcnew String(currQues.getText().c_str());

			int index = 3;
			for (Option queOpts : currQues.getOptions()) {
				secondForm->gbxOptions->Controls[index]->Visible = true;
				secondForm->gbxOptions->Controls[index]->Text = gcnew String(queOpts.getText().c_str());
				secondForm->gbxOptions->Controls[index]->Visible = true;
				index--;
			}

			// Check if the current level is Chapter 3
			if (currLevel == 2) {
				secondForm->pnlOxygen->Width = oxyLevel.getOxygenLevel();
				secondForm->queTime = 15;
				secondForm->tmrDecreTime->Enabled = false;

				// Pass the QuestionForm to the AccessCode form
				AccessCode^ loginForm = gcnew AccessCode(secondForm, "timereck");

				// Hide the current form and show the AccessCode form
				this->Hide();
				loginForm->Show();

				return; // prevent continuing to the question form
			}
			else {
				this->Hide();
				secondForm->pnlOxygen->Width = oxyLevel.getOxygenLevel();
				secondForm->queTime = 15;
				secondForm->tmrDecreTime->Enabled = true;
				secondForm->Show();
			}
		}
		else {
			this->Close();
			loadNextLevel();
		}
	}

	private: System::Void LevelForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

	}
	private: System::Void pbxLevel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

	}
	private: System::Void tmrStory_Tick(System::Object^ sender, System::EventArgs^ e) {

		lblStoryline->Visible = true;
		if (currentCharIndex < fullStoryline->Length) {
			// Append the next character to the label
			lblStoryline->Text += fullStoryline[currentCharIndex];



			// Move to the next character
			currentCharIndex++;
		}
		else {
			// Stop the timer when the full text is displayed
			tmrStory->Stop();
			// If the current level is 2, play the different sound

		}
	}

	private: System::Void LevelForm_Load(System::Object^ sender, System::EventArgs^ e) {
		if (currLevel == 0) {
			System::Media::SoundPlayer^ backgroundSound = gcnew System::Media::SoundPlayer("Sound/IntroSound.wav");
			backgroundSound->PlayLooping();
		}
		if (currLevel == 1) {
			System::Media::SoundPlayer^ level2Sound = gcnew System::Media::SoundPlayer("Sound/Level 2.wav");
			level2Sound->PlayLooping();
		}
		if (currLevel == 2) {
			System::Media::SoundPlayer^ level3Sound = gcnew System::Media::SoundPlayer("Sound/Level 3.wav");
			level3Sound->PlayLooping();
		}

		if (currLevel == 3) {
			System::Media::SoundPlayer^ conclusionSound = gcnew System::Media::SoundPlayer("Sound/conclusion.wav");
			conclusionSound->PlayLooping();
		}
		currentCharIndex = 0;
		lblStoryline->Text = ""; // Clear previous text
		tmrStory->Start(); // Start typing effect
	}
	private: System::Void lblStoryline_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void lblLevel_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}