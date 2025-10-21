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

	public ref class GameInfo : public System::Windows::Forms::Form
	{
	public:
		GameInfo(void)
		{
			InitializeComponent();

			// Set initial text
			label1->Text =
				"EXTINCTION PROTOCOL\n\n"
				"WELCOME, CAPTAIN\n\n"
				"Lead your crew to safety as Earth faces extinction.Make tough decisions, "
				"gather resources,and answer questions under pressure to survive.\n\n"
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
				"This game consists of three levels,each with 8 challenging questions. You'll face:\n"
				"- Timed True or False questions and multiple-choice questions with complex consequences.\n"
				"Your progress depends on strategic decision-making,fuel and oxygen levels "
				"Fuel and oxygen will decrease with incorrect answers and increase with correct ones.If you run out of fuel or oxygen, "
				"you will fail the mission,and you'll have to restart.\n\n"
				"WILL YOU RISE TO THE CHALLENGE?";

			// Create a graphics object to measure the text
			Graphics^ g = this->CreateGraphics();
			SizeF textSize = g->MeasureString(label1->Text, label1->Font, panel1->Width - 20);

			// Set label size based on calculated text size
			label1->Size = System::Drawing::Size((int)textSize.Width, (int)textSize.Height);


			// *Start label position BELOW the panel*
			label1->Location = System::Drawing::Point(10, panel1->Height);

			// Enable Double Buffering to prevent flickering
			this->SetStyle(ControlStyles::UserPaint, true);
			this->SetStyle(ControlStyles::AllPaintingInWmPaint, true);
			this->SetStyle(ControlStyles::DoubleBuffer, true);

			// Initialize scrolling animation
			scrollTimer = gcnew System::Windows::Forms::Timer();
			scrollTimer->Interval = 20; // Smooth movement
			scrollTimer->Tick += gcnew EventHandler(this, &GameInfo::ScrollText);
		}

	protected:
		~GameInfo()
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GameInfo::typeid));
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
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Elephant", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(10, 200);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(580, 500);
			this->label1->TabIndex = 0;
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label1->Click += gcnew System::EventHandler(this, &GameInfo::label1_Click);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->button1->Location = System::Drawing::Point(567, 662);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(228, 75);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Continue";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GameInfo::button1_Click);
			// 
			// GameInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1370, 749);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->DoubleBuffered = true;
			this->Name = L"GameInfo";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"GameInfo";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &GameInfo::GameInfo_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void GameInfo_Load(System::Object^ sender, System::EventArgs^ e) {
		// Play background music
		System::Media::SoundPlayer^ backgroundSound = gcnew System::Media::SoundPlayer("IntroSound.wav");
		backgroundSound->PlayLooping();

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
};
}