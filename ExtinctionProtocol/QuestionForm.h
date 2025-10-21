#pragma once
#include "Question.h"
#include "global.h"
#include "FuelBar.h"
#include <string>
#include "HighestScore.h"


namespace ExtinctionProtocol {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for QuestionForm
    /// </summary>
    public ref class QuestionForm : public System::Windows::Forms::Form
    {
    public:
        QuestionForm(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //

            this->panel2->Visible = true;

            fuelBar = gcnew FuelBar();
            fuelBar->MaxFuel = 8;  // Full bar = 8 units

            if (currLevel == 0) {
                fuelBar->CurrentFuel = 0;  // Start empty for Level 1
            }
            else {
                fuelBar->CurrentFuel = previousFuel;  // Keep fuel for next levels
            }
            fuelBar->Location = Point(661, 49);  // Adjust position
            fuelBar->UpdateAppearance();
            fuelBar->Dock = DockStyle::Left;

            this->panel2->Controls->Clear();  // Remove anything inside panel2
            this->panel2->Controls->Add(fuelBar);

            // Create restart button (hidden initially)
            restartButton = gcnew Button();
            restartButton->Text = "Restart";
            restartButton->Size = Drawing::Size(100, 50);
            restartButton->Location = Point(350, 350);
            restartButton->Visible = false;
            restartButton->Click += gcnew EventHandler(this, &QuestionForm::OnRestartButtonClick);
            this->Controls->Add(restartButton);


            // Create fuel percentage label
            lblFuelPercentage = gcnew Label();
            lblFuelPercentage->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);
            lblFuelPercentage->ForeColor = Color::White;
            lblFuelPercentage->BackColor = Color::Transparent;
            lblFuelPercentage->Size = Drawing::Size(50, 20);
            UpdateFuelPercentage();

        }
        int getTime() {
            if (currLevel == 0) {
                return 18; // Level 1 = 18 seconds
            }
            else if (currLevel == 1) {
                if (questionCount == 8 || questionCount == 19) {
                    return 50; // Level 2, Q9 or Q10 = 50 seconds
                }
                else {
                    return 15; // Level 2 normal = 15 seconds
                }
            }
            else if (currLevel == 2) {
                return 12; // Level 3 = 12 seconds
            }
            return 18; // Default fallback
        }

        void loadQuestion() {
            String^ username = GetLastUsername();
            QuestionForm^ secondForm = this; // Points to the current form

            secondForm->lblQuestion->Visible = false;
            secondForm->gbxOptions->Visible = false;
            secondForm->tmrQuestion->Enabled = true;
            secondForm->tmrOptions->Enabled = true;

            Question currQues = chapters[currLevel].getNextQuestion(); // Gets next question from the level class

            secondForm->BackgroundImage = Image::FromFile(gcnew String(currQues.getImagePath().c_str())); // Changes background image to correspond with the question's image
            secondForm->pbxQuestion->Image = Image::FromFile(gcnew String(currQues.getImagePath().c_str())); // Changes background image to correspond with the question's image
            secondForm->lblQuestion->Text = gcnew String(currQues.getText().c_str()); // Changes question displayed on the label

            RadioButton^ rb;
            for each (Control ^ ctrl in gbxOptions->Controls) { // Changes visibility of the radio buttons in gbxOptions to false
                rb = dynamic_cast<RadioButton^>(ctrl);
                rb->Visible = false;
            }

            int index = 3;
            for (Option queOpts : currQues.getOptions()) { // Loops through the options of the current question
                secondForm->gbxOptions->Controls[index]->Visible = true; // Changes visibility of the radio button if option at index exists
                secondForm->gbxOptions->Controls[index]->Text = gcnew String(queOpts.getText().c_str()); // Changes the radio button's text at the specified index to the option's text
                secondForm->gbxOptions->Controls[index]->Visible = true;
                index--;
            }

            //NARRATIONS FOR SOME QUESTIONS

            if (currLevel == 0 && questionCount == 0) { //before second question in level 1
                pauseBackground();

                fullText = "Captain " + username + "\n" + "you don't have enough\n medical kits\n" + "You'll need them if\n the crew gets sick or\n" + "injured in space!";
                lblDescription->Text = ""; // Clear text
                charIndex = 0;             // Reset index
                tmrLabel->Start();   // Start timer
                tmrDescription->Start();

            }

            if (currLevel == 0 && questionCount == 1) { // before third and fourth question
                pauseBackground();
                fullText = "Captain " + username + "\n" + "the main engine needs a \n backup system and the ship\n is missing components\n needed for launch \nGather everything \n before the planet's \n condition worsens";
                lblDescription->Text = "";
                charIndex = 0;
                tmrLabel->Start();
                tmrDescription->Start();


            }

            if (currLevel == 0 && questionCount == 3) { // before fifth and sixth question
                pauseBackground();
                fullText = "The crew will need sufficient" + "\n" + "food supplies and a stable" + "\n" + "renewable oxygen supply" + "\n" + "you don't have space" + "\n" + "for everything so you" + "\n" + "need to make tough decisions";
                lblDescription->Text = "";
                charIndex = 0;
                tmrLabel->Start();
                tmrDescription->Start();

            }

            if (currLevel == 0 && questionCount == 5) { // before seventh
                pauseBackground();
                fullText = "Captain " + username + "\n" + "the planet's condition is \ngetting" + "\n" + " worser! You can't take" + "\n" + "everyone! You only have\n space" + "\n" + " for a limited number of" + "\n" + " people. Make a decision\n quickly!!!";
                lblDescription->Text = "";
                charIndex = 0;
                tmrLabel->Start();
                tmrDescription->Start();

            }
            if (currLevel == 0 && questionCount == 6) { // before eigth question
                pauseBackground();
                fullText = "The end is here" + "\n" + "It's time Captain\n " + username + "\n" + "You have to takeoff NOW " + "\n" + "...but wait, it looks like" + "\n" + "you have room for 1 more" + "\n" + " person...";
                lblDescription->Text = "";
                charIndex = 0;
                tmrLabel->Start();
                tmrDescription->Start();

            }
            if (currLevel == 1 && questionCount == 0) { // level 2 before questions 2 and 3

                pauseBackground();
                fullText = "Captain " + username + "\n" + " it looks like you have\n a breach" + "\n" + "Oxygen levels are dropping" + "\n" + " fast! Act quickly!" + "\n" + "Oh wait, sensors are also" + "\n" + " picking up a massive \ngravitational" + "\n" + " disturbance ahead,\nso be on a" + "\n" + "look out";
                lblDescription->Text = "";
                charIndex = 0;
                tmrLabel->Start();
                tmrDescription->Start();

            }

            if (currLevel == 1 && questionCount == 2) { // before 4th question

                pauseBackground();
                if (wasPreviousAnswerCorrect) {
                    fullText = "Great job, Captain\n" + username + "!\n" + "But it looks like\n you have\n" + "a new problem\n" + "Food supply is running\n low, \n" + "you have to ration\n what's left.";
                }
                else {
                    fullText = "Captain " + username + "...\n" + "That wasn't the best \ndecision.\n" + "it looks like you have\n" + "a new problem\n" + "Food supply is \nrunning low, \n" + "you have to ration \nwhat's left.";
                }
                lblDescription->Text = ""; // Clear text
                charIndex = 0;             // Reset index
                tmrLabel->Start();
                tmrDescription->Start();

            }

            if (currLevel == 1 && questionCount == 4) { // before 6th question

                pauseBackground();
                fullText = "A crew member has fallen ill" + "\n" + "with an unknown sickness" + "\n" + "and the sensors are\n" + "detecting power shortage\n" + "You have a lot of decision\n" + "making to do Captain\n" + username;
                lblDescription->Text = ""; // Clear text
                charIndex = 0;             // Reset index
                tmrLabel->Start();
                tmrDescription->Start();

            }

            if (currLevel == 1 && questionCount == 6) { //before 8th question

                pauseBackground();
                fullText = "Good news Captain\n" + username + "\n" + "You are almost there" + "\n" + "But it looks like the ship" + "\n" + "might not hold. If something" + "\n" + "happens and only one person\n can survive....";
                lblDescription->Text = ""; // Clear text
                charIndex = 0;             // Reset index
                tmrLabel->Start();
                tmrDescription->Start();

            }

            if (currLevel == 1 && questionCount == 7) { //before 9th question

                pauseBackground();
                fullText = "Captain " + username + "\n" + "You have a problem" + "\n" + "It looks like the new\n planet is locked" + "\n" + "You need to crack the code to" + "\n" + "gain access. The encypted \nplanetary" + "\n" + "security systems are armed" + "\n" + "And time is running out";
                lblDescription->Text = ""; // Clear text
                charIndex = 0;             // Reset index
                tmrLabel->Start();
                tmrDecrypt->Start();

            }
            if (currLevel == 2 && questionCount == -2) {
                pauseBackground();
                fullText = "Captain " + username + "\n" + "A security protocol\n is triggered." + "\n" + "To bypass it ,\nyou must identify \n a logical inconsistency";
                lblDescription->Text = ""; // Clear text
                charIndex = 0;             // Reset index
                tmrLabel->Start();
                tmrDescription->Start();
            }
            if (currLevel == 2 && questionCount == 0) //question 2
            {
                pauseBackground();
                fullText = "Captain " + username + "\n" + "The platform begins \nshifting at your feet.\n You must quickly \n calculate the safest \n path across rotating\n tiles";
                lblDescription->Text = ""; // Clear text
                charIndex = 0;             // Reset index
                tmrLabel->Start();
                tmrDescription->Start();
            }
            if (currLevel == 2 && questionCount == 1) {//3
                pauseBackground();
                fullText = "Captain " + username + "\n" + "An Alien AI demands\n you reroute power through \nthe correct system. \nEach system requires \ndifferent resources ";
                lblDescription->Text = ""; // Clear text
                charIndex = 0;             // Reset index
                tmrLabel->Start();
                tmrDescription->Start();
            }
            if (currLevel == 2 && questionCount == 2) {//4
                pauseBackground();
                fullText = "Captain " + username + "\n" + "You reach a locked \nconsole that requires a \npattern to be\n recognised to proceed ";
                lblDescription->Text = ""; // Clear text
                charIndex = 0;             // Reset index
                tmrLabel->Start();
                tmrDescription->Start();
            }
            if (currLevel == 2 && questionCount == 3) {//5
                pauseBackground();
                fullText = "Captain " + username + "\n" + "To power the beacon ," + "\n" + "you must complete a\n logical circuit using\n only one missing piece";
                lblDescription->Text = ""; // Clear text
                charIndex = 0;             // Reset index
                tmrLabel->Start();
                tmrDescription->Start();
            }
            if (currLevel == 2 && questionCount == 4) {//6
                pauseBackground();
                fullText = "Captain " + username + "\n" + "A defense drone \nscans  your logs and \ntries to detect anomalies";
                lblDescription->Text = ""; // Clear text
                charIndex = 0;             // Reset index
                tmrLabel->Start();
                tmrDescription->Start();
            }
            if (currLevel == 2 && questionCount == 5) {//7
                pauseBackground();
                fullText = "Captain " + username + "\n" + "There is a puzzle \nvault requiring you to \npick a correct pattern\n from four";
                lblDescription->Text = ""; // Clear text
                charIndex = 0;             // Reset index
                tmrLabel->Start();
                tmrDescription->Start();
            }
            if (currLevel == 2 && questionCount == 6) {//8
                pauseBackground();
                fullText = "Captain " + username + "\n" + "To unlock the final\n chamber, you must pass\n a time-based \n logic riddle";
                lblDescription->Text = ""; // Clear text
                charIndex = 0;             // Reset index
                tmrLabel->Start();
                tmrDescription->Start();
            }
            if (currLevel == 2 && questionCount == 7) {//9
                pauseBackground();
                fullText = "Captain " + username + "\n" + "A locked gate\n presents the final\n puzzle: entering\n the right 4-symbol\n sequence derived from patterns \n gathered throughout the\n challenge";
                lblDescription->Text = ""; // Clear text
                charIndex = 0;             // Reset index
                tmrLabel->Start();
                tmrDescription->Start();
            }

            tmrDecreTime->Enabled = false;
            queTime = getTime();
            lbltime->Text = gcnew String("00:" + (queTime < 10 ? "0" : "") + queTime); // Display the updated time immediately
            lbltime->ForeColor = Color::White;
            tmrDecreTime->Enabled = true;
            //**increment questionCount before updating progress
            questionCount++;

            //update progress label
            int progress = static_cast<int>((static_cast<double>(questionCount) / totalQuestions) * 100);
            lblProgress->Text = "Progress: " + progress.ToString() + "%";
        }

        //method to pause the background whilst the narration goes on
        void pauseBackground() {
            String^ gender = GetLastUserGender();

            panel1->BringToFront();
            panel1->Visible = true;

            if (gender == "girl") {
                pbxUser->Image = Image::FromFile("Images/girlAvatar.png");
            }
            else {

                pbxUser->Image = Image::FromFile("Images/boyAvatar.png");
            }


            for each (Control ^ ctrl in this->Controls) {
                if (ctrl != panel1) {
                    ctrl->Enabled = false;
                }
            }
            tmrDecreTime->Enabled = false;
            queTime = getTime();
            tmrDecreTime->Enabled = false;

        }
        //method to get the user's name
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
        //method to get the user's assistant
    private:
        String^ GetLastUserGender() {
            if (System::IO::File::Exists("users.txt")) {
                cli::array<String^>^ lines = System::IO::File::ReadAllLines("users.txt");

                if (lines->Length > 0) {
                    String^ lastLine = lines[lines->Length - 1];
                    cli::array<String^>^ parts = lastLine->Split(',');

                    if (parts->Length >= 2) {
                        return parts[1]->Trim()->ToLower(); // return gender in lowercase for easy comparison
                    }
                }
            }
            return "unknown"; // fallback if gender isn't found
        }


    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~QuestionForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private:int correctCount;
    public: FuelBar^ fuelBar;
    private:Button^ restartButton;
    private:Label^ lblFuelPercentage;
    private:static int previousFuel;
    private: System::Windows::Forms::PictureBox^ pictureBox1;
    public: System::Windows::Forms::PictureBox^ pbxQuestion;
    private:

    private:

    public: System::Windows::Forms::Panel^ pnlOxygen;
    private: System::Windows::Forms::Panel^ pnlOxyback;
    public:
    private: System::Windows::Forms::Panel^ panel2;
    public: System::Windows::Forms::Label^ lblQuestion;
    private:
    public: System::Windows::Forms::PictureBox^ pbxQuestions;
    public: System::Windows::Forms::Panel^ gbxOptions;

    public: System::Windows::Forms::RadioButton^ rdbOpt4;
    private:
    public: System::Windows::Forms::RadioButton^ rdbOpt3;
    public: System::Windows::Forms::RadioButton^ rdbOpt2;
    public: System::Windows::Forms::RadioButton^ rdbOpt1;
    private: System::Windows::Forms::Timer^ tmrQuestion;
    private: System::Windows::Forms::Timer^ tmrOptions;
    private: System::ComponentModel::IContainer^ components;
    private: System::Windows::Forms::PictureBox^ pbxTimer;



    private: System::Windows::Forms::Label^ lbltime;
    private: System::Windows::Forms::Label^ lblProgress;
    public: System::Windows::Forms::Timer^ tmrDecreTime;
    private:int questionCount = 0;
    private:int totalQuestions = chapters[currLevel].getNumOfQuestions();
    public: int queTime;

          System::Media::SoundPlayer^ gameOverSound = gcnew System::Media::SoundPlayer("Sound/GameOver.wav");
    public: System::Windows::Forms::Panel^ pnlRestart;
    public: System::Windows::Forms::Label^ lblGameState;
    public: System::Windows::Forms::Panel^ btnRestart;
          String^ fullText;
          int charIndex = 0;
          bool wasPreviousAnswerCorrect = true;
          System::Media::SoundPlayer^ explosionSound = gcnew System::Media::SoundPlayer("Sound/explosionSound.wav");
          System::Media::SoundPlayer^ decryptionSound = gcnew System::Media::SoundPlayer("Sound/decryptionSound.wav");


    public:


    private: System::Windows::Forms::Label^ lblRestart;
    public: System::Windows::Forms::Label^ lblLastScore;
    private:


    private: System::Windows::Forms::Panel^ pnlScore;
    private: System::Windows::Forms::Label^ lblFinalScore;
    private: System::Windows::Forms::Label^ lblScoreText;
    public: System::Windows::Forms::Panel^ panel1;
    private:
    private: System::Windows::Forms::PictureBox^ pictureBox3;
    public:
    private: System::Windows::Forms::PictureBox^ pbxUser;
    private: System::Windows::Forms::Label^ lblDescription;
    private: System::Windows::Forms::Timer^ tmrDescription;
    private: System::Windows::Forms::Timer^ tmrLabel;
    public: System::Windows::Forms::Panel^ pnlDecryption;
    private:

    private: System::Windows::Forms::Timer^ tmrDecrypt;
    private: System::Windows::Forms::Button^ btnProceed;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Timer^ tmrGif;
    private: System::Windows::Forms::Label^ lblLevel2Feedback;
     private: System::Windows::Forms::Timer^ tmrViewScores;
private: System::Windows::Forms::Panel^ panel3;
private: System::Windows::Forms::Panel^ panel4;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Timer^ tmrUnlock;
    private: System::Windows::Forms::PictureBox^ pbxLevel3Unlock;
           private: System::Windows::Forms::Panel^ panel5;

    public:
    private:




    public:
    private: RadioButton^ selectedOpt;

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
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(QuestionForm::typeid));
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->pbxQuestion = (gcnew System::Windows::Forms::PictureBox());
            this->pnlOxygen = (gcnew System::Windows::Forms::Panel());
            this->pnlOxyback = (gcnew System::Windows::Forms::Panel());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->lblQuestion = (gcnew System::Windows::Forms::Label());
            this->pbxQuestions = (gcnew System::Windows::Forms::PictureBox());
            this->gbxOptions = (gcnew System::Windows::Forms::Panel());
            this->rdbOpt4 = (gcnew System::Windows::Forms::RadioButton());
            this->rdbOpt3 = (gcnew System::Windows::Forms::RadioButton());
            this->rdbOpt2 = (gcnew System::Windows::Forms::RadioButton());
            this->rdbOpt1 = (gcnew System::Windows::Forms::RadioButton());
            this->tmrQuestion = (gcnew System::Windows::Forms::Timer(this->components));
            this->tmrOptions = (gcnew System::Windows::Forms::Timer(this->components));
            this->pbxTimer = (gcnew System::Windows::Forms::PictureBox());
            this->lbltime = (gcnew System::Windows::Forms::Label());
            this->tmrDecreTime = (gcnew System::Windows::Forms::Timer(this->components));
            this->lblProgress = (gcnew System::Windows::Forms::Label());
            this->pnlRestart = (gcnew System::Windows::Forms::Panel());
            this->lblLevel2Feedback = (gcnew System::Windows::Forms::Label());
            this->btnRestart = (gcnew System::Windows::Forms::Panel());
            this->lblRestart = (gcnew System::Windows::Forms::Label());
            this->lblLastScore = (gcnew System::Windows::Forms::Label());
            this->lblGameState = (gcnew System::Windows::Forms::Label());
            this->pnlScore = (gcnew System::Windows::Forms::Panel());
            this->lblScoreText = (gcnew System::Windows::Forms::Label());
            this->lblFinalScore = (gcnew System::Windows::Forms::Label());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->panel5 = (gcnew System::Windows::Forms::Panel());
            this->lblDescription = (gcnew System::Windows::Forms::Label());
            this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
            this->pbxUser = (gcnew System::Windows::Forms::PictureBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->pnlDecryption = (gcnew System::Windows::Forms::Panel());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->btnProceed = (gcnew System::Windows::Forms::Button());
            this->tmrDescription = (gcnew System::Windows::Forms::Timer(this->components));
            this->tmrLabel = (gcnew System::Windows::Forms::Timer(this->components));
            this->tmrDecrypt = (gcnew System::Windows::Forms::Timer(this->components));
            this->tmrGif = (gcnew System::Windows::Forms::Timer(this->components));
            this->tmrViewScores = (gcnew System::Windows::Forms::Timer(this->components));
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->panel4 = (gcnew System::Windows::Forms::Panel());
            this->tmrUnlock = (gcnew System::Windows::Forms::Timer(this->components));
            this->pbxLevel3Unlock = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQuestion))->BeginInit();
            this->pnlOxyback->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQuestions))->BeginInit();
            this->gbxOptions->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxTimer))->BeginInit();
            this->pnlRestart->SuspendLayout();
            this->btnRestart->SuspendLayout();
            this->pnlScore->SuspendLayout();
            this->panel1->SuspendLayout();
            this->panel5->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxUser))->BeginInit();
            this->pnlDecryption->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxLevel3Unlock))->BeginInit();
            this->SuspendLayout();
            // 
            // pictureBox1
            // 
            this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->pictureBox1->Location = System::Drawing::Point(0, 0);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(887, 487);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox1->TabIndex = 0;
            this->pictureBox1->TabStop = false;
            // 
            // pbxQuestion
            // 
            this->pbxQuestion->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbxQuestion.BackgroundImage")));
            this->pbxQuestion->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
            this->pbxQuestion->Dock = System::Windows::Forms::DockStyle::Fill;
            this->pbxQuestion->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbxQuestion.Image")));
            this->pbxQuestion->Location = System::Drawing::Point(0, 0);
            this->pbxQuestion->Name = L"pbxQuestion";
            this->pbxQuestion->Size = System::Drawing::Size(887, 487);
            this->pbxQuestion->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pbxQuestion->TabIndex = 1;
            this->pbxQuestion->TabStop = false;
            this->pbxQuestion->Click += gcnew System::EventHandler(this, &QuestionForm::pbxQuestion_Click);
            // 
            // pnlOxygen
            // 
            this->pnlOxygen->BackColor = System::Drawing::Color::Aqua;
            this->pnlOxygen->Dock = System::Windows::Forms::DockStyle::Left;
            this->pnlOxygen->Location = System::Drawing::Point(0, 0);
            this->pnlOxygen->Name = L"pnlOxygen";
            this->pnlOxygen->Size = System::Drawing::Size(81, 15);
            this->pnlOxygen->TabIndex = 2;
            // 
            // pnlOxyback
            // 
            this->pnlOxyback->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->pnlOxyback->BackColor = System::Drawing::Color::LightGray;
            this->pnlOxyback->Controls->Add(this->pnlOxygen);
            this->pnlOxyback->Location = System::Drawing::Point(661, 16);
            this->pnlOxyback->Name = L"pnlOxyback";
            this->pnlOxyback->Size = System::Drawing::Size(208, 15);
            this->pnlOxyback->TabIndex = 3;
            // 
            // panel2
            // 
            this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->panel2->BackColor = System::Drawing::Color::LightGray;
            this->panel2->Location = System::Drawing::Point(661, 49);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(208, 15);
            this->panel2->TabIndex = 3;
            // 
            // lblQuestion
            // 
            this->lblQuestion->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lblQuestion->BackColor = System::Drawing::Color::Transparent;
            this->lblQuestion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblQuestion->ForeColor = System::Drawing::Color::White;
            this->lblQuestion->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblQuestion.Image")));
            this->lblQuestion->Location = System::Drawing::Point(163, 238);
            this->lblQuestion->Name = L"lblQuestion";
            this->lblQuestion->Size = System::Drawing::Size(579, 83);
            this->lblQuestion->TabIndex = 4;
            this->lblQuestion->Text = L"Question";
            this->lblQuestion->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->lblQuestion->Visible = false;
            // 
            // pbxQuestions
            // 
            this->pbxQuestions->Dock = System::Windows::Forms::DockStyle::Fill;
            this->pbxQuestions->Location = System::Drawing::Point(0, 0);
            this->pbxQuestions->Name = L"pbxQuestions";
            this->pbxQuestions->Size = System::Drawing::Size(887, 487);
            this->pbxQuestions->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pbxQuestions->TabIndex = 5;
            this->pbxQuestions->TabStop = false;
            // 
            // gbxOptions
            // 
            this->gbxOptions->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->gbxOptions->BackColor = System::Drawing::Color::Transparent;
            this->gbxOptions->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gbxOptions.BackgroundImage")));
            this->gbxOptions->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->gbxOptions->Controls->Add(this->rdbOpt4);
            this->gbxOptions->Controls->Add(this->rdbOpt3);
            this->gbxOptions->Controls->Add(this->rdbOpt2);
            this->gbxOptions->Controls->Add(this->rdbOpt1);
            this->gbxOptions->Location = System::Drawing::Point(259, 371);
            this->gbxOptions->Name = L"gbxOptions";
            this->gbxOptions->Size = System::Drawing::Size(387, 151);
            this->gbxOptions->TabIndex = 6;
            this->gbxOptions->Visible = false;
            // 
            // rdbOpt4
            // 
            this->rdbOpt4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->rdbOpt4->AutoSize = true;
            this->rdbOpt4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->rdbOpt4->FlatAppearance->CheckedBackColor = System::Drawing::Color::Red;
            this->rdbOpt4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->rdbOpt4->ForeColor = System::Drawing::Color::White;
            this->rdbOpt4->Location = System::Drawing::Point(33, 95);
            this->rdbOpt4->Name = L"rdbOpt4";
            this->rdbOpt4->Size = System::Drawing::Size(175, 34);
            this->rdbOpt4->TabIndex = 3;
            this->rdbOpt4->TabStop = true;
            this->rdbOpt4->Text = L"radioButton4";
            this->rdbOpt4->UseVisualStyleBackColor = true;
            this->rdbOpt4->Visible = false;
            this->rdbOpt4->Click += gcnew System::EventHandler(this, &QuestionForm::rdbOpt1_CheckedChanged);
            // 
            // rdbOpt3
            // 
            this->rdbOpt3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->rdbOpt3->AutoSize = true;
            this->rdbOpt3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->rdbOpt3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->rdbOpt3->ForeColor = System::Drawing::Color::White;
            this->rdbOpt3->Location = System::Drawing::Point(187, 95);
            this->rdbOpt3->Name = L"rdbOpt3";
            this->rdbOpt3->Size = System::Drawing::Size(175, 34);
            this->rdbOpt3->TabIndex = 2;
            this->rdbOpt3->TabStop = true;
            this->rdbOpt3->Text = L"radioButton3";
            this->rdbOpt3->UseVisualStyleBackColor = true;
            this->rdbOpt3->Visible = false;
            this->rdbOpt3->CheckedChanged += gcnew System::EventHandler(this, &QuestionForm::rdbOpt1_CheckedChanged);
            // 
            // rdbOpt2
            // 
            this->rdbOpt2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->rdbOpt2->AutoSize = true;
            this->rdbOpt2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->rdbOpt2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->rdbOpt2->ForeColor = System::Drawing::Color::White;
            this->rdbOpt2->Location = System::Drawing::Point(187, 29);
            this->rdbOpt2->Name = L"rdbOpt2";
            this->rdbOpt2->Size = System::Drawing::Size(175, 34);
            this->rdbOpt2->TabIndex = 1;
            this->rdbOpt2->TabStop = true;
            this->rdbOpt2->Text = L"radioButton2";
            this->rdbOpt2->UseVisualStyleBackColor = true;
            this->rdbOpt2->Visible = false;
            this->rdbOpt2->CheckedChanged += gcnew System::EventHandler(this, &QuestionForm::rdbOpt1_CheckedChanged);
            // 
            // rdbOpt1
            // 
            this->rdbOpt1->AutoSize = true;
            this->rdbOpt1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->rdbOpt1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->rdbOpt1->ForeColor = System::Drawing::Color::White;
            this->rdbOpt1->Location = System::Drawing::Point(33, 29);
            this->rdbOpt1->Name = L"rdbOpt1";
            this->rdbOpt1->Size = System::Drawing::Size(175, 34);
            this->rdbOpt1->TabIndex = 0;
            this->rdbOpt1->TabStop = true;
            this->rdbOpt1->Text = L"radioButton1";
            this->rdbOpt1->UseVisualStyleBackColor = true;
            this->rdbOpt1->Visible = false;
            this->rdbOpt1->CheckedChanged += gcnew System::EventHandler(this, &QuestionForm::rdbOpt1_CheckedChanged);
            // 
            // tmrQuestion
            // 
            this->tmrQuestion->Enabled = true;
            this->tmrQuestion->Interval = 1200;
            this->tmrQuestion->Tick += gcnew System::EventHandler(this, &QuestionForm::tmrQuestion_Tick);
            // 
            // tmrOptions
            // 
            this->tmrOptions->Enabled = true;
            this->tmrOptions->Interval = 1750;
            this->tmrOptions->Tick += gcnew System::EventHandler(this, &QuestionForm::tmrOptions_Tick);
            // 
            // pbxTimer
            // 
            this->pbxTimer->Anchor = System::Windows::Forms::AnchorStyles::Top;
            this->pbxTimer->BackColor = System::Drawing::Color::Transparent;
            this->pbxTimer->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbxTimer.Image")));
            this->pbxTimer->Location = System::Drawing::Point(426, 16);
            this->pbxTimer->Name = L"pbxTimer";
            this->pbxTimer->Size = System::Drawing::Size(41, 42);
            this->pbxTimer->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pbxTimer->TabIndex = 7;
            this->pbxTimer->TabStop = false;
            // 
            // lbltime
            // 
            this->lbltime->Anchor = System::Windows::Forms::AnchorStyles::Top;
            this->lbltime->AutoSize = true;
            this->lbltime->BackColor = System::Drawing::Color::Transparent;
            this->lbltime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbltime->ForeColor = System::Drawing::Color::White;
            this->lbltime->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lbltime.Image")));
            this->lbltime->Location = System::Drawing::Point(409, 77);
            this->lbltime->Name = L"lbltime";
            this->lbltime->Size = System::Drawing::Size(20, 29);
            this->lbltime->TabIndex = 9;
            this->lbltime->Text = L" ";
            // 
            // tmrDecreTime
            // 
            this->tmrDecreTime->Enabled = true;
            this->tmrDecreTime->Interval = 1000;
            this->tmrDecreTime->Tick += gcnew System::EventHandler(this, &QuestionForm::tmrDecreTime_Tick);
            // 
            // lblProgress
            // 
            this->lblProgress->AutoSize = true;
            this->lblProgress->BackColor = System::Drawing::Color::Transparent;
            this->lblProgress->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
            this->lblProgress->ForeColor = System::Drawing::Color::Cyan;
            this->lblProgress->Location = System::Drawing::Point(20, 20);
            this->lblProgress->Name = L"lblProgress";
            this->lblProgress->Size = System::Drawing::Size(182, 37);
            this->lblProgress->TabIndex = 0;
            this->lblProgress->Text = L"Progress: 0%";
            // 
            // pnlRestart
            // 
            this->pnlRestart->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->pnlRestart->BackColor = System::Drawing::Color::Transparent;
            this->pnlRestart->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlRestart.BackgroundImage")));
            this->pnlRestart->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->pnlRestart->Controls->Add(this->lblLevel2Feedback);
            this->pnlRestart->Controls->Add(this->btnRestart);
            this->pnlRestart->Controls->Add(this->lblLastScore);
            this->pnlRestart->Controls->Add(this->lblGameState);
            this->pnlRestart->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pnlRestart->Location = System::Drawing::Point(170, 67);
            this->pnlRestart->Margin = System::Windows::Forms::Padding(10, 10, 10, 10);
            this->pnlRestart->Name = L"pnlRestart";
            this->pnlRestart->Size = System::Drawing::Size(562, 476);
            this->pnlRestart->TabIndex = 10;
            this->pnlRestart->Visible = false;
            this->pnlRestart->VisibleChanged += gcnew System::EventHandler(this, &QuestionForm::pnlRestart_VisibleChanged);
            this->pnlRestart->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &QuestionForm::pnlRestart_Paint);
            // 
            // lblLevel2Feedback
            // 
            this->lblLevel2Feedback->AutoSize = true;
            this->lblLevel2Feedback->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblLevel2Feedback->ForeColor = System::Drawing::SystemColors::ControlLightLight;
            this->lblLevel2Feedback->Location = System::Drawing::Point(218, 2);
            this->lblLevel2Feedback->Name = L"lblLevel2Feedback";
            this->lblLevel2Feedback->Size = System::Drawing::Size(598, 261);
            this->lblLevel2Feedback->TabIndex = 3;
            this->lblLevel2Feedback->Text = resources->GetString(L"lblLevel2Feedback.Text");
            this->lblLevel2Feedback->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            this->lblLevel2Feedback->Visible = false;
            // 
            // btnRestart
            // 
            this->btnRestart->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
            this->btnRestart->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRestart.BackgroundImage")));
            this->btnRestart->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->btnRestart->Controls->Add(this->lblRestart);
            this->btnRestart->Location = System::Drawing::Point(173, 335);
            this->btnRestart->Name = L"btnRestart";
            this->btnRestart->Size = System::Drawing::Size(196, 98);
            this->btnRestart->TabIndex = 2;
            this->btnRestart->Click += gcnew System::EventHandler(this, &QuestionForm::btnRestart_Click);
            // 
            // lblRestart
            // 
            this->lblRestart->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lblRestart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblRestart->ForeColor = System::Drawing::Color::White;
            this->lblRestart->Location = System::Drawing::Point(25, 23);
            this->lblRestart->Name = L"lblRestart";
            this->lblRestart->Size = System::Drawing::Size(168, 66);
            this->lblRestart->TabIndex = 0;
            this->lblRestart->Text = L"Restart";
            this->lblRestart->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->lblRestart->Click += gcnew System::EventHandler(this, &QuestionForm::btnRestart_Click);
            // 
            // lblLastScore
            // 
            this->lblLastScore->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->lblLastScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblLastScore->ForeColor = System::Drawing::Color::Red;
            this->lblLastScore->Location = System::Drawing::Point(171, 215);
            this->lblLastScore->Name = L"lblLastScore";
            this->lblLastScore->Size = System::Drawing::Size(231, 63);
            this->lblLastScore->TabIndex = 1;
            this->lblLastScore->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // lblGameState
            // 
            this->lblGameState->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lblGameState->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 34, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblGameState->ForeColor = System::Drawing::Color::White;
            this->lblGameState->Location = System::Drawing::Point(16, 83);
            this->lblGameState->Name = L"lblGameState";
            this->lblGameState->Size = System::Drawing::Size(524, 110);
            this->lblGameState->TabIndex = 0;
            this->lblGameState->Text = L"GAME OVER";
            this->lblGameState->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->lblGameState->Click += gcnew System::EventHandler(this, &QuestionForm::lblGameState_Click);
            // 
            // pnlScore
            // 
            this->pnlScore->BackColor = System::Drawing::Color::Transparent;
            this->pnlScore->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->pnlScore->Controls->Add(this->lblScoreText);
            this->pnlScore->Controls->Add(this->lblFinalScore);
            this->pnlScore->Location = System::Drawing::Point(266, 200);
            this->pnlScore->Name = L"pnlScore";
            this->pnlScore->Size = System::Drawing::Size(355, 200);
            this->pnlScore->TabIndex = 12;
            this->pnlScore->Visible = false;
            this->pnlScore->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &QuestionForm::pnlScore_Paint);
            // 
            // lblScoreText
            // 
            this->lblScoreText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
            this->lblScoreText->ForeColor = System::Drawing::Color::White;
            this->lblScoreText->Location = System::Drawing::Point(40, 20);
            this->lblScoreText->Name = L"lblScoreText";
            this->lblScoreText->Size = System::Drawing::Size(275, 40);
            this->lblScoreText->TabIndex = 0;
            this->lblScoreText->Text = L"Final Score : ";
            this->lblScoreText->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // lblFinalScore
            // 
            this->lblFinalScore->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->lblFinalScore->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Bold));
            this->lblFinalScore->Location = System::Drawing::Point(-43, 80);
            this->lblFinalScore->Name = L"lblFinalScore";
            this->lblFinalScore->Size = System::Drawing::Size(441, 65);
            this->lblFinalScore->TabIndex = 1;
            this->lblFinalScore->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::Color::Transparent;
            this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
            this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->panel1->Controls->Add(this->panel5);
            this->panel1->Controls->Add(this->pictureBox3);
            this->panel1->Controls->Add(this->pbxUser);
            this->panel1->Controls->Add(this->button1);
            this->panel1->Cursor = System::Windows::Forms::Cursors::Hand;
            this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->panel1->Location = System::Drawing::Point(0, 0);
            this->panel1->Margin = System::Windows::Forms::Padding(10, 10, 10, 10);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(887, 487);
            this->panel1->TabIndex = 13;
            this->panel1->Visible = false;
            // 
            // panel5
            // 
            this->panel5->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
            this->panel5->AutoSize = true;
            this->panel5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel5.BackgroundImage")));
            this->panel5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->panel5->Controls->Add(this->lblDescription);
            this->panel5->Location = System::Drawing::Point(155, -46);
            this->panel5->Name = L"panel5";
            this->panel5->Size = System::Drawing::Size(347, 253);
            this->panel5->TabIndex = 3;
            // 
            // lblDescription
            // 
            this->lblDescription->AutoSize = true;
            this->lblDescription->BackColor = System::Drawing::Color::Transparent;
            this->lblDescription->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblDescription->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->lblDescription->Location = System::Drawing::Point(22, 63);
            this->lblDescription->Name = L"lblDescription";
            this->lblDescription->Size = System::Drawing::Size(29, 20);
            this->lblDescription->TabIndex = 2;
            this->lblDescription->Text = L".....";
            this->lblDescription->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // pictureBox3
            // 
            this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
            this->pictureBox3->Location = System::Drawing::Point(0, 2);
            this->pictureBox3->Name = L"pictureBox3";
            this->pictureBox3->Size = System::Drawing::Size(357, 278);
            this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox3->TabIndex = 1;
            this->pictureBox3->TabStop = false;
            this->pictureBox3->Visible = false;
            // 
            // pbxUser
            // 
            this->pbxUser->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Right));
            this->pbxUser->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbxUser.Image")));
            this->pbxUser->Location = System::Drawing::Point(244, 167);
            this->pbxUser->Name = L"pbxUser";
            this->pbxUser->Size = System::Drawing::Size(333, 252);
            this->pbxUser->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pbxUser->TabIndex = 0;
            this->pbxUser->TabStop = false;
            // 
            // button1
            // 
            this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
            this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button1->ForeColor = System::Drawing::Color::White;
            this->button1->Location = System::Drawing::Point(610, 97);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(107, 30);
            this->button1->TabIndex = 3;
            this->button1->Text = L"Skip";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &QuestionForm::button1_Click);
            // 
            // pnlDecryption
            // 
            this->pnlDecryption->BackColor = System::Drawing::Color::Transparent;
            this->pnlDecryption->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlDecryption.BackgroundImage")));
            this->pnlDecryption->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->pnlDecryption->Controls->Add(this->label2);
            this->pnlDecryption->Controls->Add(this->label1);
            this->pnlDecryption->Controls->Add(this->btnProceed);
            this->pnlDecryption->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pnlDecryption->Dock = System::Windows::Forms::DockStyle::Fill;
            this->pnlDecryption->Location = System::Drawing::Point(0, 0);
            this->pnlDecryption->Margin = System::Windows::Forms::Padding(10, 10, 10, 10);
            this->pnlDecryption->Name = L"pnlDecryption";
            this->pnlDecryption->Size = System::Drawing::Size(887, 487);
            this->pnlDecryption->TabIndex = 11;
            this->pnlDecryption->Visible = false;
            this->pnlDecryption->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &QuestionForm::pnlDecryption_Paint);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(594, 116);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(181, 384);
            this->label2->TabIndex = 2;
            this->label2->Text = resources->GetString(L"label2.Text");
            this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(68, 116);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(415, 448);
            this->label1->TabIndex = 1;
            this->label1->Text = resources->GetString(L"label1.Text");
            this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            // 
            // btnProceed
            // 
            this->btnProceed->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->btnProceed->BackColor = System::Drawing::Color::Black;
            this->btnProceed->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnProceed.BackgroundImage")));
            this->btnProceed->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->btnProceed->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnProceed->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnProceed->Location = System::Drawing::Point(691, 438);
            this->btnProceed->Name = L"btnProceed";
            this->btnProceed->Size = System::Drawing::Size(117, 37);
            this->btnProceed->TabIndex = 0;
            this->btnProceed->Text = L"Proceed";
            this->btnProceed->UseVisualStyleBackColor = false;
            this->btnProceed->Click += gcnew System::EventHandler(this, &QuestionForm::btnProceed_Click);
            // 
            // tmrDescription
            // 
            this->tmrDescription->Interval = 18000;
            this->tmrDescription->Tick += gcnew System::EventHandler(this, &QuestionForm::tmrDescription_Tick);
            // 
            // tmrLabel
            // 
            this->tmrLabel->Interval = 75;
            this->tmrLabel->Tick += gcnew System::EventHandler(this, &QuestionForm::tmrLabel_Tick);
            // 
            // tmrDecrypt
            // 
            this->tmrDecrypt->Interval = 20000;
            this->tmrDecrypt->Tick += gcnew System::EventHandler(this, &QuestionForm::tmrDecrypt_Tick);
            // 
            // tmrGif
            // 
            this->tmrGif->Interval = 3500;
            this->tmrGif->Tick += gcnew System::EventHandler(this, &QuestionForm::tmrGif_Tick);
            // 
            // tmrViewScores
            // 
            this->tmrViewScores->Interval = 2000;
            this->tmrViewScores->Tick += gcnew System::EventHandler(this, &QuestionForm::tmrViewScores_Tick);
            // 
            // panel3
            // 
            this->panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->panel3->BackColor = System::Drawing::Color::Transparent;
            this->panel3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel3.BackgroundImage")));
            this->panel3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->panel3->Location = System::Drawing::Point(632, 7);
            this->panel3->Name = L"panel3";
            this->panel3->Size = System::Drawing::Size(19, 31);
            this->panel3->TabIndex = 14;
            // 
            // panel4
            // 
            this->panel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->panel4->BackColor = System::Drawing::Color::Transparent;
            this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
            this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->panel4->Location = System::Drawing::Point(631, 46);
            this->panel4->Name = L"panel4";
            this->panel4->Size = System::Drawing::Size(21, 21);
            this->panel4->TabIndex = 15;
            // 
            // tmrUnlock
            // 
            this->tmrUnlock->Interval = 8000;
            this->tmrUnlock->Tick += gcnew System::EventHandler(this, &QuestionForm::tmrUnlock_Tick);
            // 
            // pbxLevel3Unlock
            // 
            this->pbxLevel3Unlock->Dock = System::Windows::Forms::DockStyle::Fill;
            this->pbxLevel3Unlock->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbxLevel3Unlock.Image")));
            this->pbxLevel3Unlock->Location = System::Drawing::Point(0, 0);
            this->pbxLevel3Unlock->Name = L"pbxLevel3Unlock";
            this->pbxLevel3Unlock->Size = System::Drawing::Size(887, 487);
            this->pbxLevel3Unlock->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pbxLevel3Unlock->TabIndex = 14;
            this->pbxLevel3Unlock->TabStop = false;
            this->pbxLevel3Unlock->Visible = false;
            // 
            // QuestionForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(887, 487);
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->panel4);
            this->Controls->Add(this->panel3);
            this->Controls->Add(this->pnlDecryption);
            this->Controls->Add(this->pnlRestart);
            this->Controls->Add(this->lblProgress);
            this->Controls->Add(this->lbltime);
            this->Controls->Add(this->pbxTimer);
            this->Controls->Add(this->gbxOptions);
            this->Controls->Add(this->lblQuestion);
            this->Controls->Add(this->panel2);
            this->Controls->Add(this->pnlOxyback);
            this->Controls->Add(this->pbxQuestion);
            this->Controls->Add(this->pbxQuestions);
            this->Controls->Add(this->pnlScore);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->pbxLevel3Unlock);
            this->DoubleBuffered = true;
            this->KeyPreview = true;
            this->Name = L"QuestionForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Questions";
            this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
            this->Load += gcnew System::EventHandler(this, &QuestionForm::QuestionForm_Load);
            this->Click += gcnew System::EventHandler(this, &QuestionForm::pbxQuestion_Click);
            this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &QuestionForm::QuestionForm_KeyDown);
            this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &QuestionForm::QuestionForm_KeyPress);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQuestion))->EndInit();
            this->pnlOxyback->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQuestions))->EndInit();
            this->gbxOptions->ResumeLayout(false);
            this->gbxOptions->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxTimer))->EndInit();
            this->pnlRestart->ResumeLayout(false);
            this->pnlRestart->PerformLayout();
            this->btnRestart->ResumeLayout(false);
            this->pnlScore->ResumeLayout(false);
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            this->panel5->ResumeLayout(false);
            this->panel5->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxUser))->EndInit();
            this->pnlDecryption->ResumeLayout(false);
            this->pnlDecryption->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxLevel3Unlock))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        // Method to update fuel percentage label
        void UpdateFuelPercentage() {
            if (fuelBar->MaxFuel > 0) {
                double fuelPercentage = (static_cast<double>(fuelBar->CurrentFuel) / fuelBar->MaxFuel) * 100.0;
                lblFuelPercentage->Text = fuelPercentage.ToString("F1") + "%";    // Show 1 decimal place
                lblFuelPercentage->ForeColor = fuelBar->BackColor; // Match fuel bar color
                lblFuelPercentage->BringToFront();
            }
        }


        // Event handler for restart button click
        void OnRestartButtonClick(Object^ sender, EventArgs^ e) {
            restartButton->Visible = false;
            pnlScore->Visible = false;
            fuelBar->CurrentFuel = 0; // Reset fuel to 0%
            fuelBar->UpdateAppearance();
            previousFuel = 0;
            loadQuestion();
            UpdateFuelPercentage();
            lblFuelPercentage->BringToFront();


        }

#pragma endregion

    private: System::Void tmrQuestion_Tick(System::Object^ sender, System::EventArgs^ e) {
        lblQuestion->Visible = true;
        tmrQuestion->Enabled = false;
    }

    private: System::Void tmrOptions_Tick(System::Object^ sender, System::EventArgs^ e) {
        gbxOptions->Visible = true;
        tmrOptions->Enabled = false;
    }

    private: System::Void pbxQuestion_Click(System::Object^ sender, System::EventArgs^ e) {
        if (pnlRestart->Visible == false) {
            int selIndex = 4;
            RadioButton^ rb;
            for each (Control ^ ctrl in gbxOptions->Controls) {
                selIndex--;
                rb = dynamic_cast<RadioButton^>(ctrl);
                if (rb->Checked) {
                    if (chapters[currLevel].getQuestionAt(currQuestion).getOptionAt(selIndex).isCorrectAns()) {
                        wasPreviousAnswerCorrect = true; // Mark as correct
                        System::Media::SoundPlayer^ wrongSound = gcnew System::Media::SoundPlayer("Sound/correctAnswer.wav");
                        wrongSound->Play();
                        // Level 1: Increase fuel for correct answers
                        if (currLevel == 0) {
                            ++(*this->fuelBar);
                            UpdateFuelPercentage();
                        }

                        PlayerScore++;

                        switch (currLevel)
                        {
                        case 0: {
                            LevelOneScore++;
                            break;
                        }
                        case 1: {
                            LevelTwoScore++;
                            break;
                        }
                        case 2: {
                            LevelThreeScore++;
                            break;
                        }
                        default:
                            break;
                        }

                        lblLastScore->Text = "Final Score: " + PlayerScore.ToString() + "/" + TotalScore.ToString();
                    }
                    else {
                        wasPreviousAnswerCorrect = false; // Mark as wrong
                        if (currLevel == 1 && (currQuestion == 8 || currQuestion == 9)) {
                            lblGameState->Text = "GAME OVER\nINCORRECT ANSWER";
                            lblLastScore->Text = "Final Score: " + PlayerScore.ToString() + "/" + TotalScore.ToString();
                            pnlRestart->Visible = true;

                            gameOverSound->Play();
                            break;
                        }

                        System::Media::SoundPlayer^ correctSound = gcnew System::Media::SoundPlayer("Sound/wrongAnswer.wav");
                        correctSound->Play();
                        // Level 1 & 2: Decrease fuel for wrong answers
                        if (currLevel == 0 || currLevel == 1) {
                            --(*this->fuelBar);
                            UpdateFuelPercentage();
                        }

                        if (currLevel == 1) {
                            oxyLevel.decreaseOxygenLevel(25);
                            pnlOxygen->Width = oxyLevel.getOxygenLevel();
                        }
                    }

                    if (oxyLevel.getOxygenLevel() <= 0) {
                        // View restart menu
                        lblGameState->Text = "GAME OVER\nOXYGEN DEPLETED!!";
                        lblLastScore->Text = "Final Score: " + PlayerScore.ToString() + "/" + TotalScore.ToString();
                        pnlRestart->Visible = true;


                        gameOverSound->Play();
                        break;
                    }

                    // If fuel reaches 0, show Restart Button
                    if (fuelBar->CurrentFuel == 0 && currLevel == 1) {
                        lblLastScore->Text = "Final Score: " + PlayerScore.ToString() + "/" + TotalScore.ToString();
                        pnlRestart->Visible = true;
                        this->lblGameState->Text = L"GAME OVER\nFUEL DEPLETED";


                        gameOverSound->Play();
                        break;
                    }

                    rb->Checked = false;
                    // If this is the last question in the level, save fuel and load the next level
                    if (!chapters[currLevel].hasNextQuestion()) {
                        if (currLevel == 0 && fuelBar->CurrentFuel == 0) {
                            lblGameState->Text = "GAME OVER!\nFUEL DEPLETED!!";
                            lblLastScore->Text = "Final Score: " + correctCount.ToString() + "/" + TotalScore.ToString();
                            pnlRestart->Visible = true;
                            gameOverSound->Play();
                            return;  // Stop further processing.
                        }

                        previousFuel = fuelBar->CurrentFuel; // Save current fuel for next level
                        delete selectedOpt;

                        gbxOptions->Visible = false;
                        lblQuestion->Visible = false;
                        tmrDecreTime->Enabled = false;
                        questionCount++;
                        int progress = static_cast<int>((static_cast<double>(questionCount) / totalQuestions) * 100);
                        lblProgress->Text = "Progress: " + progress.ToString() + "%";


                        if (currLevel == 0) {
                            // Instead of showing pnlRestart right away:
                            explosionSound->Play();
                            pictureBox1->Visible = true;
                            pictureBox1->BringToFront();
                            pictureBox1->Image = Image::FromFile("Images/planetblow.gif");
                            pnlRestart->Visible = false;
                            tmrGif->Start();
                            return;

                        }
                        if (currLevel == 1) {
                            pnlRestart->Visible = true;
                            lblGameState->Text = "Level Complete!";
                            lblRestart->Text = "Next Level";
                        }
                        else {
                            pnlRestart->Visible = true;
                            lblGameState->Text = "Level Complete!";
                            lblRestart->Text = "Continue";
                        }
                        lblLastScore->Text = "Final Score: " + PlayerScore.ToString() + "/" + TotalScore.ToString();

                    }
                    else {
                        loadQuestion(); // Load the next question
                        selectedOpt = nullptr;
                    }

                    break;
                }
            }
        }
    }

    private: System::Void rdbOpt1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
        selectedOpt = dynamic_cast<RadioButton^>(sender);
    }

    private: System::Void tmrDecreTime_Tick(System::Object^ sender, System::EventArgs^ e) {

        if (pnlRestart->Visible == false && pnlDecryption->Visible == false && panel1->Visible == false && pbxLevel3Unlock->Visible == false) {
            queTime--;
            if (queTime < 10) {
                lbltime->ForeColor = Color::Red;
                lbltime->Text = gcnew String("00:0" + queTime);
            }
            else {
                lbltime->ForeColor = Color::White;
                lbltime->Text = gcnew String("00:" + queTime);
            }

            if (queTime == 0) {
                tmrDecreTime->Enabled = false;
                if (selectedOpt != nullptr) {
                    pbxQuestion_Click(sender, e);
                }
                else {
                    // Replace code to display restart menu
                    lblGameState->Text = "GAME OVER\nTIME DEPLETED!!";
                    lblLastScore->Text = "Final Score: " + PlayerScore.ToString() + "/" + TotalScore.ToString();
                    pnlRestart->Visible = true;
                    gameOverSound->Play();
                }
            }
        }
    }


    private: System::Void QuestionForm_Load(System::Object^ sender, System::EventArgs^ e) {
        tmrDecreTime->Enabled = false;
        queTime = getTime();
        lbltime->Text = gcnew String("00:" + (queTime < 10 ? "0" : "") + queTime);
        lbltime->ForeColor = Color::White;
        tmrDecreTime->Enabled = true;
        //showing the door unlocking in level 3
        if (currLevel == 2) {

            pbxLevel3Unlock->Visible = true;
            pbxLevel3Unlock->BringToFront();
            tmrUnlock->Start();
            for each (Control ^ ctrl in this->Controls) {
                if (ctrl != pbxLevel3Unlock) {
                    ctrl->Enabled = false;  // Disable everything except the description panel
                }
            }
        }
        // Level 3: Hide the fuel bar
        if (currLevel == 2) {
            this->fuelBar->Visible = false;
            this->panel2->Visible = false;
            this->pnlOxygen->Visible = false;
            this->pnlOxyback->Visible = false;
            this->lblFuelPercentage->Visible = false;
        }
    }
    private: System::Void btnRestart_Click(System::Object^ sender, System::EventArgs^ e) {
        if (lblRestart->Text == "Restart") {
            PlayerScore = 0;
            lblFinalScore->Text = "Score: 0/" + TotalScore.ToString();
            pnlScore->Visible = false;

            oxyLevel.setOxygenLevel(208);
            previousFuel = 0;
            currLevel = -1;
        }

        this->Close();
        loadNextLevel();
    }

    private: System::Void pnlScore_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void lblGameState_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void pnlRestart_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void QuestionForm_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

    }
    private: System::Void QuestionForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
        if (e->KeyCode == Keys::Enter)
        {
            pbxQuestion_Click(sender, e);
            e->SuppressKeyPress = true; // Optional: stops the 'ding' sound
        }
    }

           //timer method that controls how long the description(narration) panel appears before hiding it and continuing with questions
    private: System::Void tmrDescription_Tick(System::Object^ sender, System::EventArgs^ e) {
        panel1->Visible = false;

        tmrDescription->Stop();
        for each (Control ^ ctrl in this->Controls) {
            if (ctrl != panel1) {
                ctrl->Enabled = true;
            }
        }

        tmrDecreTime->Enabled = false;
        queTime = getTime();
        tmrDecreTime->Enabled = true;



    }

           //timer for typing effect
    private: System::Void tmrLabel_Tick(System::Object^ sender, System::EventArgs^ e) {
        if (charIndex < fullText->Length) {
            lblDescription->Text += fullText[charIndex];
            charIndex++;
        }
        else {
        }
    }
           //timer used to alternate between the description(narration) panel and the decryption info panel in level 2
    private: System::Void tmrDecrypt_Tick(System::Object^ sender, System::EventArgs^ e) {
        panel1->Visible = false;
        pnlDecryption->Visible = true;
        decryptionSound->PlayLooping();
        tmrDecrypt->Stop();
        for each (Control ^ ctrl in this->Controls) {
            if (ctrl != panel1) {
                ctrl->Enabled = true;
            }
        }
    }
           //procceed button in the decryption info panel
    private: System::Void btnProceed_Click(System::Object^ sender, System::EventArgs^ e) {
        pnlDecryption->Visible = false;
        decryptionSound->Stop();
        for each (Control ^ ctrl in this->Controls) {
            if (ctrl != pnlDecryption) {
                ctrl->Enabled = true;
            }
        }
        tmrDecreTime->Enabled = false;
        queTime = getTime();
        tmrDecreTime->Enabled = true;

    }
           //timer for stopping the Gif after completing level1
    private: System::Void tmrGif_Tick(System::Object^ sender, System::EventArgs^ e) {
        tmrGif->Stop();
        pictureBox1->Visible = false;
        pictureBox1->SendToBack();
        pnlRestart->Visible = true;
        lblGameState->Visible = false;
        lblLevel2Feedback->Visible = true;
        lblRestart->Text = "Next Level";
    }

    private: System::Void pnlDecryption_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }

           //skip button in panel 1
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        if (tmrDescription->Enabled) {
            panel1->Visible = false;

            tmrDescription->Stop();

            for each (Control ^ ctrl in this->Controls) {
                if (ctrl != panel1) {
                    ctrl->Enabled = true;
                }
            }

            tmrDecreTime->Enabled = false;
            queTime = getTime();
            tmrDecreTime->Enabled = true;
        }

        else if (tmrDecrypt->Enabled) {
            panel1->Visible = false;
            pnlDecryption->Visible = true;
            decryptionSound->PlayLooping();
            tmrDecrypt->Stop();

            for each (Control ^ ctrl in this->Controls) {
                if (ctrl != panel1) {
                    ctrl->Enabled = true;
                }
            }
        }

    }

           //Level3 door
    private: System::Void tmrUnlock_Tick(System::Object^ sender, System::EventArgs^ e) {
        tmrUnlock->Stop();
        pbxLevel3Unlock->Visible = false;
        pbxLevel3Unlock->SendToBack();
        for each (Control ^ ctrl in this->Controls) {
            if (ctrl != pbxLevel3Unlock) {
                ctrl->Enabled = true;
            }
        }
	}
		   // Method to show the highest scores

       private: void ShowHighestScores() {
           // Create the HighestScore form instance
           HighestScore^ scoreForm = gcnew HighestScore();

           // Show the form
           scoreForm->Show();
       }

        private: System::Void pnlRestart_VisibleChanged(System::Object^ sender, System::EventArgs^ e) {
            if (pnlRestart->Visible == true)
                tmrViewScores->Enabled = true;
        }

        private: System::Void tmrViewScores_Tick(System::Object^ sender, System::EventArgs^ e) {
            ShowHighestScores();

            tmrViewScores->Enabled = false;
        }

};
}