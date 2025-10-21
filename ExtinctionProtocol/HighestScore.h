#pragma once
#include "global.h"
#include <fstream>
#include <string>

namespace ExtinctionProtocol {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for HighestScore
	/// </summary>
	public ref class HighestScore : public System::Windows::Forms::Form
	{
	public:
		HighestScore(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			UpdateScoreDisplay();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HighestScore()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ lvelOneScore;
	private: System::Windows::Forms::Label^ levelTwo;
	private: System::Windows::Forms::Label^ levelThree;


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(HighestScore::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->lvelOneScore = (gcnew System::Windows::Forms::Label());
			this->levelTwo = (gcnew System::Windows::Forms::Label());
			this->levelThree = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(841, 575);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &HighestScore::pictureBox1_Click);
			// 
			// lvelOneScore
			// 
			this->lvelOneScore->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lvelOneScore->AutoSize = true;
			this->lvelOneScore->BackColor = System::Drawing::Color::Transparent;
			this->lvelOneScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lvelOneScore->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->lvelOneScore->Location = System::Drawing::Point(529, 220);
			this->lvelOneScore->Name = L"lvelOneScore";
			this->lvelOneScore->Size = System::Drawing::Size(30, 31);
			this->lvelOneScore->TabIndex = 1;
			this->lvelOneScore->Text = L"0";
			// 
			// levelTwo
			// 
			this->levelTwo->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->levelTwo->AutoSize = true;
			this->levelTwo->BackColor = System::Drawing::Color::Transparent;
			this->levelTwo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->levelTwo->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->levelTwo->Location = System::Drawing::Point(529, 348);
			this->levelTwo->Name = L"levelTwo";
			this->levelTwo->Size = System::Drawing::Size(30, 31);
			this->levelTwo->TabIndex = 2;
			this->levelTwo->Text = L"0";
			// 
			// levelThree
			// 
			this->levelThree->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->levelThree->AutoSize = true;
			this->levelThree->BackColor = System::Drawing::Color::Transparent;
			this->levelThree->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->levelThree->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->levelThree->Location = System::Drawing::Point(529, 491);
			this->levelThree->Name = L"levelThree";
			this->levelThree->Size = System::Drawing::Size(30, 31);
			this->levelThree->TabIndex = 3;
			this->levelThree->Text = L"0";
			// 
			// HighestScore
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(841, 575);
			this->Controls->Add(this->levelThree);
			this->Controls->Add(this->levelTwo);
			this->Controls->Add(this->lvelOneScore);
			this->Controls->Add(this->pictureBox1);
			this->DoubleBuffered = true;
			this->Name = L"HighestScore";
			this->Text = L"HighestScore";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

    void UpdateScoreDisplay() {
			   lvelOneScore->Text = LevelOneScore.ToString() + "/" + chapters[0].getNumOfQuestions().ToString();
			   levelTwo->Text = LevelTwoScore.ToString() + "/" + chapters[1].getNumOfQuestions().ToString();
			   levelThree->Text = LevelThreeScore.ToString() + "/" + chapters[2].getNumOfQuestions().ToString();
		   }
};
}