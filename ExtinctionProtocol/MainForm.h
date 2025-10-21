#pragma once
#include "GameInfoForm.h"
#include <fstream>  // File handling




namespace ExtinctionProtocol {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO; // File handling in .NET


	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
			
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;

			}
		}

	private:
		System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::PictureBox^ pbxBoy;
	private: System::Windows::Forms::PictureBox^ pbxGirl;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
		   String^ selectedPbx = nullptr;







	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pbxBoy = (gcnew System::Windows::Forms::PictureBox());
			this->pbxGirl = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxBoy))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxGirl))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 50);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 17, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Red;
			this->button1->Location = System::Drawing::Point(441, 503);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(188, 56);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click_1);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->pbxBoy);
			this->panel1->Controls->Add(this->pbxGirl);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1020, 598);
			this->panel1->TabIndex = 5;
			this->panel1->Visible = false;
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button2->BackColor = System::Drawing::Color::LightSteelBlue;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(459, 548);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(148, 47);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Continue";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(221, 446);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(961, 66);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Once you\'ve made your choice, enter what you\'d like me to call you \r\nduring our j"
				L"ourney";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1490, 74);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Hey Captain, I\'ll be your assistant throughout this mission but before we begin c"
				L"hoose one of the \r\navailable assistants to accompany you";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// textBox1
			// 
			this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->textBox1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::SystemColors::InfoText;
			this->textBox1->Location = System::Drawing::Point(407, 497);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(253, 33);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pbxBoy
			// 
			this->pbxBoy->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pbxBoy->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbxBoy.Image")));
			this->pbxBoy->Location = System::Drawing::Point(543, 65);
			this->pbxBoy->Name = L"pbxBoy";
			this->pbxBoy->Size = System::Drawing::Size(500, 448);
			this->pbxBoy->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbxBoy->TabIndex = 1;
			this->pbxBoy->TabStop = false;
			this->pbxBoy->Click += gcnew System::EventHandler(this, &MainForm::pbxBoy_Click);
			// 
			// pbxGirl
			// 
			this->pbxGirl->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbxGirl.Image")));
			this->pbxGirl->Location = System::Drawing::Point(35, 65);
			this->pbxGirl->Name = L"pbxGirl";
			this->pbxGirl->Size = System::Drawing::Size(500, 448);
			this->pbxGirl->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbxGirl->TabIndex = 0;
			this->pbxGirl->TabStop = false;
			this->pbxGirl->Click += gcnew System::EventHandler(this, &MainForm::pbxGirl_Click);
			// 
			// MainForm
			// 
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1020, 598);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxBoy))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxGirl))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		bool IsUserRegistered(String^ username) {
			if (System::IO::File::Exists("users.txt")) {
				System::IO::StreamReader^ reader = gcnew System::IO::StreamReader("users.txt");
				while (!reader->EndOfStream) {
					String^ line = reader->ReadLine();
					cli::array<String^>^ parts = line->Split(',');

					if (parts->Length > 0 && parts[0]->Trim()->Equals(username, StringComparison::OrdinalIgnoreCase)) {
						reader->Close();
						return true;
					}
				}
				reader->Close();
			}
			return false;
		}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pbxGirl_Click(System::Object^ sender, System::EventArgs^ e) {
		selectedPbx = "Girl";
		// Slightly increase the size of pbxGirl to highlight it
		this->pbxGirl->Width = this->pbxGirl->Width + 20;  // Increase width
		this->pbxGirl->Height = this->pbxGirl->Height + 20;  // Increase height
		this->pbxBoy->Width = this->pbxBoy->Width - 20;  // Reset width
		this->pbxBoy->Height = this->pbxBoy->Height - 20;  // Reset height
	}
	private: System::Void pbxBoy_Click(System::Object^ sender, System::EventArgs^ e) {
		selectedPbx = "Boy";
		this->pbxBoy->Width = this->pbxBoy->Width + 20;  // Increase width
		this->pbxBoy->Height = this->pbxBoy->Height + 20;  // Increase height
		this->pbxGirl->Width = this->pbxGirl->Width - 20;  // Reset width
		this->pbxGirl->Height = this->pbxGirl->Height - 20;  // Reset height
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ username = textBox1->Text->Trim();

		// Check if username is empty
		if (String::IsNullOrEmpty(username)) {
			MessageBox::Show("Please enter your username.");
			return;
		}

		// Check if a picture was selected
		if (selectedPbx == nullptr) {
			MessageBox::Show("Please select your assistant");
			return;
		}

		// Check if the username already exists
		if (IsUserRegistered(username)) {
			MessageBox::Show("Username already exists. Please choose a different one.");
			return;
		}

		// Save to users.txt
		try {
			System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter("users.txt", true); // 'true' to append
			writer->WriteLine(username + "," + selectedPbx);
			writer->Close();

			GameInfoForm^ secondForm = gcnew GameInfoForm();
			this->Hide();
			secondForm->Show();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error saving user info: " + ex->Message);
		}
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		System::Media::SoundPlayer^ buttonSound = gcnew System::Media::SoundPlayer("Sound/buttonClickSound.wav");
		buttonSound->Play();
		// 1) grab the username from your textbox
		String^ username = textBox1->Text->Trim();

		this->button1->Visible = false;
		this->panel1->Visible = true;
		panel1->BringToFront();

		System::Media::SoundPlayer^ userSound = gcnew System::Media::SoundPlayer("Sound/usernameSound.wav");
		userSound->PlayLooping();
	}
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		System::Media::SoundPlayer^ background = gcnew System::Media::SoundPlayer("Sound/mainBackground.wav");
		background->PlayLooping();
	}
	};
}
// Use of Vectors for efficiency and scalability(To make it easier to manage user data in memory).