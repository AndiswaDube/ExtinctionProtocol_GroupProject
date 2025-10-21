#pragma once
#include "LevelForm.h"
#include "global.h"
#include <vector>
#include <string>

namespace ExtinctionProtocol {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class GameInfoForm : public System::Windows::Forms::Form
	{
	public:
		GameInfoForm(void)
		{
			InitializeComponent();
			
			// Enable double buffering on the panel via reflection
			panel1->GetType()->GetProperty("DoubleBuffered", System::Reflection::BindingFlags::Instance | System::Reflection::BindingFlags::NonPublic)
				->SetValue(panel1, true, nullptr);

			// Enable Double Buffering to prevent flickering
			this->SetStyle(ControlStyles::UserPaint, true);
			this->SetStyle(ControlStyles::AllPaintingInWmPaint, true);
			this->SetStyle(ControlStyles::DoubleBuffer, true);
			this->SetStyle(ControlStyles::OptimizedDoubleBuffer, true);
			this->UpdateStyles(); // Apply the style changes
			// Initialize scrolling animation
			scrollTimer = gcnew System::Windows::Forms::Timer();
			scrollTimer->Interval = 10; // Smooth movement
			scrollTimer->Tick += gcnew EventHandler(this, &GameInfoForm::ScrollText);
		}

	private:
		String^ GetLastUsername() {
			if (System::IO::File::Exists("users.txt")) {
				cli::array<String^>^ lines = System::IO::File::ReadAllLines("users.txt");

				if (lines->Length > 0) {
					String^ lastLine = lines[lines->Length - 1];
					cli::array<String^>^ parts = lastLine->Split(',');

					if (parts->Length >= 1) {
						return parts[0]->Trim();
					}
				}
			}
			return "Captain";
		}


	protected:
		~GameInfoForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Timer^ scrollTimer;
		System::Windows::Forms::Panel^ panel1; // Viewport for smooth scrolling
		int scrollSpeed = 1; // Move by 1 pixel per tick

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GameInfoForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(12, 33);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1346, 495);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameInfoForm::panel1_Paint);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(10, 200);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(580, 500);
			this->label1->TabIndex = 0;
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label1->Click += gcnew System::EventHandler(this, &GameInfoForm::label1_Click);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->button1->Location = System::Drawing::Point(567, 662);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(228, 75);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Continue";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &GameInfoForm::button1_Click);
			// 
			// GameInfoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1370, 749);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->DoubleBuffered = true;
			this->Name = L"GameInfoForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"GameInfoForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &GameInfoForm::GameInfoForm_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void GameInfoForm_Load(System::Object^ sender, System::EventArgs^ e) {
		// Play background music
		System::Media::SoundPlayer^ backgroundSound = gcnew System::Media::SoundPlayer("Sound/IntroSound.wav");
		backgroundSound->PlayLooping();

		String^ username = GetLastUsername();
		// Set initial text
		label1->Text =
			"EXTINCTION PROTOCOL\n\n"
			"WELCOME, CAPTAIN " + username + "\n\n"
			"Lead your crew to safety as Earth faces extinction,make tough decisions, "
			"gather resources, and answer questions under pressure to survive.\n\n"
			"GAMEPLAY HIGHLIGHTS\n\n"
			"- MAKE LIFE-OR-DEATH DECISIONS: Gather fuel and supplies while navigating "
			"through oxygen leaks,and alien signals.\n"
			"- ANSWER QUIZ QUESTIONS UNDER PRESSURE: Correct answers increase fuel and "
			"oxygen levels, while wrong answers decrease them.\n"
			"- DECRYPT ENCRYPTED MESSAGES: Unlock the password to the new planet.\n\n"
			"CHALLENGES & FEATURES\n\n"
			"- LIMITED RESOURCES: Manage fuel and oxygen to stay alive.\n"
			"- UNEXPECTED TWISTS: Encounter surprises that will test your skills and strategy.\n\n"
			"GAME STRUCTURE\n\n"
			"This game consists of three levels,each with 8 or more challenging questions. You'll face:\n\n"
			"-Timed True or False questions and multiple-choice questions with complex consequences.\n\n"
			"Click outside the grey panel or press Enter key after choosing your answer.\n"
			"If you run out of fuel, oxygen or timer , \n\n"
			"you will fail the mission, and you'll have to RESTART.\n\n"
			"Your progress depends on strategic decision-making.\n\n"
			"WILL YOU RISE TO THE CHALLENGE?\n\n"
			"GOODLUCK\n\n";
		    
		

		// Create a graphics object to measure the text
		Graphics^ g = this->CreateGraphics();
		SizeF textSize = g->MeasureString(label1->Text, label1->Font, panel1->Width - 20);

		// Set label size based on calculated text size
		label1->Size = System::Drawing::Size((int)textSize.Width, (int)textSize.Height);


		// *Start label position BELOW the panel*
		label1->Location = System::Drawing::Point(10, panel1->Height);

		// Start scrolling animation
		scrollTimer->Start();
	}

	private: System::Void ScrollText(System::Object^ sender, System::EventArgs^ e) {
		// Calculate the lowest Y position where the text is fully visible
		int stopPosition = panel1->Height - label1->Height;

		// Scroll only if the label has not reached its final position
		if (label1->Location.Y > stopPosition) {
			label1->Location = System::Drawing::Point(label1->Location.X, label1->Location.Y - scrollSpeed);
		}
		else {
			// Ensure text is fully visible
			label1->Location = System::Drawing::Point(label1->Location.X, stopPosition);
			scrollTimer->Stop(); // Stop scrolling once the text is fully in view
		}
	}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
		loadNextLevel();
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
};
}