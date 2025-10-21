#pragma once
#include "QuestionForm.h"
namespace ExtinctionProtocol {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class AccessCode : public System::Windows::Forms::Form
	{
	public:
		AccessCode(void)
		{
			InitializeComponent();
			correctPassword = gcnew String("");
			attempts = 0;
			questionForm->pnlRestart->Visible = true;
			lblFeedback->Text = "YOU HAVE 3 ATTEMPTS!";
		}
		AccessCode(QuestionForm^& qForm, String^ expectedPassword) {
			InitializeComponent();
			this->questionForm = qForm;
			this->correctPassword = expectedPassword;
			attempts = 0;
			questionForm->pnlRestart->Visible = true;
			lblFeedback->Text = "YOU HAVE 3 ATTEMPTS!";
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AccessCode()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::Label^ lblFeedback;
	private: Panel^ pnlRestart;
	private: int attempts;
	private: QuestionForm^ questionForm;

	private:String^ correctPassword;
	private: System::Windows::Forms::Panel^ panel1;
	protected:

	protected:


	protected:

	private:  System::ComponentModel::Container ^components;
		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AccessCode::typeid));
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->lblFeedback = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// txtPassword
			// 
			this->txtPassword->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txtPassword->BackColor = System::Drawing::SystemColors::ControlText;
			this->txtPassword->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->txtPassword->Location = System::Drawing::Point(688, 342);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(332, 13);
			this->txtPassword->TabIndex = 1;
			this->txtPassword->UseSystemPasswordChar = true;
			// 
			// lblFeedback
			// 
			this->lblFeedback->AutoSize = true;
			this->lblFeedback->BackColor = System::Drawing::Color::Transparent;
			this->lblFeedback->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFeedback->ForeColor = System::Drawing::Color::MediumTurquoise;
			this->lblFeedback->Location = System::Drawing::Point(576, 76);
			this->lblFeedback->Name = L"lblFeedback";
			this->lblFeedback->Size = System::Drawing::Size(356, 31);
			this->lblFeedback->TabIndex = 2;
			this->lblFeedback->Text = L"YOU HAVE 3 ATTEMPTS!";
			this->lblFeedback->Click += gcnew System::EventHandler(this, &AccessCode::lblFeedback_Click);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Location = System::Drawing::Point(766, 385);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(158, 56);
			this->panel1->TabIndex = 3;
			this->panel1->Click += gcnew System::EventHandler(this, &AccessCode::btnLogin_Click);
			// 
			// AccessCode
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1370, 648);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->lblFeedback);
			this->Controls->Add(this->txtPassword);
			this->DoubleBuffered = true;
			this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->Name = L"AccessCode";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"AccessCode";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &AccessCode::AccessCode_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void AccessCode_Load(System::Object^ sender, System::EventArgs^ e) {
		txtPassword->Focus();
	}
	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		// Convert both strings to lowercase.
		String^ entered = txtPassword->Text->ToLower();
		String^ correct = correctPassword->ToLower();

		if (entered == correct) {
			
			// Hide this form; then show the QuestionForm (for Chapter 3)
			this->Hide();
			if (questionForm != nullptr) {
				questionForm->pnlRestart->Visible = false;			
				questionForm->Show();
				questionForm->tmrDecreTime->Enabled = true;
			}
		}
		else {
			attempts++;
			if (attempts < 3) {
				int remaining = 3 - attempts;
				lblFeedback->ForeColor = Color::Cyan;
				lblFeedback->Text = "INVALID PASSWORD!\nAttempts remaining: " + remaining.ToString();
				txtPassword->Clear();
			}
			else {
				if (questionForm != nullptr) {
					questionForm->pnlRestart->Visible = true;
					questionForm->lblGameState->Text = "GAME OVER!\nACCESS CODE INCORRECT!";
					questionForm->lblLastScore->Text = "Final Score: " + PlayerScore.ToString() + "/" + ((currLevel + 1) * 8).ToString();
					questionForm->gameOverSound->Play();
					questionForm->Show();
				}

				this->Hide();
			}
		}
	}
private: System::Void lblFeedback_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
//The generic case-insensitive comparer .

generic<typename T>
ref class CaseInsensitiveComparer {
public:
	bool Equals(T a, T b) {
		String^ strA = safe_cast<String^>(a);
		String^ strB = safe_cast<String^>(b);
		if (strA == nullptr || strB == nullptr)
			return false;
		return String::Compare(strA, strB, StringComparison::OrdinalIgnoreCase) == 0;
	}
};
}
