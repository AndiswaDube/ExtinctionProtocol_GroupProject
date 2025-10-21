#include "global.h"
#include "LevelForm.h"

using namespace std;
using namespace ExtinctionProtocol;
using namespace System::Drawing;

int currLevel = -1; // variable to index current level
int currQuestion = -1; // variable to index current question of a level
int PlayerScore = 0;
int TotalScore = 8;
int LevelOneScore = 0;
int LevelTwoScore = 0;
int LevelThreeScore = 0;

Oxygen oxyLevel = Oxygen();

Option opt1 = Option("True", "Images/Lvl1Eng.jpg", true);
Option opt2 = Option("False", "Images/Lvl1Eng.jpg", false);
Question que1 = Question("Liquid hydrogen is the most commonly used fuel for space travel?", "Images/LVL1 Q1.jpg", { opt1, opt2 }, "TF");

Option opt3 = Option("Bandages", "Images/Lvl1Q2.jpg", false);
Option opt4 = Option("Antibiotics", "Images/Lvl1Q2.jpg", false);
Option opt5 = Option("Painkillers", "Images/Lvl1Q2.jpg", false);
Option opt6 = Option("All of the above", "Images/Lvl1Q2.jpg", true);
Question que2 = Question("Which is the most essential in a spaceship's medical kit?", "Images/Lvl1Q2.jpg", { opt3, opt4, opt5, opt6 }, "M");

Option opt7 = Option("Solar power", "Images/Lv1 Question 5 A.png", false);
Option opt8 = Option("Extra fuel tanks", "Images/Lv1 Question 5 B.png", false);
Option opt9 = Option("Manual thrusters", "Images/Lv1 Question 5 A.png", true);
Option opt10 = Option("Wind turbines", "Images/Lv1 Question 5 B.png", false);
Question que3 = Question("What is the best backup system for a spaceship's main engine?", "Images/Lvl1Q3.jpg", { opt7, opt8, opt9, opt10 }, "M");

Option opt11 = Option("Oxygen generation system", "Images/Lv1 Question 5 A.png", true);
Option opt12 = Option("Fuel cells", "Images/Lv1 Question 5 B.png", false);
Option opt13 = Option("Communication system", "Images/Lv1 Question 5 A.png", false);
Option opt14 = Option("Advanced life support equipment", "Images/Lv1 Question 5 B.png", false);
Question que4 = Question("Which critical component should you prioritize for the ship's launch?", "Images/oxygen supplies.jpg", { opt11, opt12, opt13, opt14 }, "M");

Option opt15 = Option("Freeze-dried meals", "Images/Lv1 Question 5 A.png", true);
Option opt16 = Option("Fresh fruits and vegetables", "Images/Lv1 Question 5 B.png", false);
Option opt17 = Option("Protein-rich food packs", "Images/Lv1 Question 5 A.png", false);
Option opt18 = Option("Instant energy bars", "Images/Lv1 Question 5 B.png", false);
Question que5 = Question("What type of food supply is most important for a long-duration space journey?", "Images/foodSup1.jpg", { opt15, opt16, opt17, opt18 }, "M");

Option opt19 = Option("True", "Images/Lv3 Question 5 A.png", true);
Option opt20 = Option("False", "Images/Lv3 Question 5 B.png", false);
Question que6 = Question("Chemical oxygen generators is the best method for providing oxygen to the crew during the journey?", "Images/chemical oxygen.jpg", { opt19, opt20 }, "TF");

Option opt21 = Option("A highly skilled engineer", "Images/Lv1 Question 5 A.png", true);
Option opt22 = Option("A medical doctor", "Images/Lv1 Question 5 B.png", false);
Option opt23 = Option("A biologist", "Images/Lv1 Question 5 A.png", false);
Option opt24 = Option("A security", "Images/Lv1 Question 5 B.png", false);
Question que7 = Question("Which crew member is MOST important for survival in deep space?", "Images/crew.jpg", { opt21, opt22, opt23, opt24 }, "M");

Option opt25 = Option("True", "Images/Lv3 Question 5 A.png", true);
Option opt26 = Option("False", "Images/Lv3 Question 5 B.png", false);
Question que8 = Question("Taking a scientist who can find resources on other planets will be beneficial.", "Images/Scien.jpg", { opt25, opt26 }, "TF");

//level 2 questions

Option opt27 = Option("Fly through at full speed", "Images/Lv1 Question 5 A.png", false);
Option opt28 = Option("Use the ship's shields", "Images/Lv1 Question 5 B.png", false);
Option opt29 = Option("Maneuver at a steady speed", "Images/Lv1 Question 5 A.png", true);
Option opt30 = Option("Look for another route", "Images/Lv1 Question 5 B.png", false);
Question que9 = Question("What is the best way to navigate through an asteroid field?", "Images/Lv2 Q1.jpg", { opt27, opt28, opt29, opt30 }, "M");

Option opt31 = Option("True", "Images/Lv3 Question 5 A.png", true);
Option opt32 = Option("False", "Images/Lv3 Question 5 B.png", false);
Question que10 = Question("Sealing off affected areas and rerouting oxygen can temporary stabilize the situation", "Images/Lv2 oxygenLeak.png", { opt31, opt32 }, "TF");

Option opt33 = Option("Outrun it", "Images/Lv1 Question 5 A.png", false);
Option opt34 = Option("Use gravity slingshot maneuvers", "Images/Lv1 Question 5 B.png", true);
Option opt35 = Option("Drift through silently", "Images/Lv1 Question 5 A.png", false);
Option opt36 = Option("Fire the ships weapons", "Images/Lv1 Question 5 B.png", false);
Question que11 = Question("How should the crew handle the gravitational anomaly?", "Images/gravitational.jpg", { opt33, opt34, opt35, opt36 }, "M");

Option opt37 = Option("Prioritize essential crew members", "Images/Lv1 Question 5 A.png", true);
Option opt38 = Option("Divide food equally", "Images/Lv1 Question 5 B.png", true);
Option opt39 = Option("Eat only emergency rations", "Images/Lv1 Question 5 A.png", false);
Option opt40 = Option("Food chosen by luck", "Images/Lv1 Question 5 B.png", false);
Question que12 = Question("How should the food be distributed?", "Images/food lvl2.jpg", { opt37, opt38, opt39, opt40 }, "M");

Option opt41 = Option("Maximizing communication range", "Images/Lv1 Question 5 A.png", false);
Option opt42 = Option("Maximizing speed", "Images/Lv1 Question 5 B.png", false);
Option opt43 = Option("Avoiding space debris", "Images/Lv1 Question 5 A.png", false);
Option opt44 = Option("Minimizing fuel consumption", "Images/Lv1 Question 5 B.png", true);
Question que13 = Question("What should be the primary consideration when selecting a route for deep space exploration?", "Images/Lv2 DeepSpace.png", { opt41, opt42, opt43, opt44 }, "M");

Option opt45 = Option("True", "Images/Lv3 Question 5 A.png", true);
Option opt46 = Option("False", "Images/Lv3 Question 5 B.png", false);
Question que14 = Question("Quarantining crew member and administrating broad-spectrum antibiotics is teh safest approach", "Images/quarantine.jpg", { opt45, opt46 }, "TF");

Option opt51 = Option("Shut down non-essential systems", "Images/Lv1 Question 6 A.png", true);
Option opt52 = Option("Keep all systems running", "Images/Lv1 Question 6 B.png", false);
Option opt53 = Option("Use emergency power", "Images/Lv1 Question 6 A.png", false);
Option opt54 = Option("Broadcast distress signals", "Images/Lv1 Question 6 B.png", false);
Question que16 = Question("What is the best way to conserve power when stranded in deep space?", "Images/Lv2 PowerSaving.png", { opt51, opt52, opt53, opt54 }, "M");

Option opt47 = Option("You Captain", "Images/Lv1 Question 5 A.png", false);
Option opt48 = Option("The last remaining crew members", "Images/Lv1 Question 5 B.png", true);
Option opt49 = Option("Everyone", "Images/Lv1 Question 5 A.png", false);
Option opt50 = Option("Nobody", "Images/Lv1 Question 5 B.png", false);
Question que15 = Question("Who should be the last survivor to reach the planet?", "Images/last survivor.jpg", { opt47, opt48, opt49, opt50 }, "M");


//decryption questions
Option opt55 = Option("Time", "Images/Lv1 Question 5 A.png", true);
Option opt56 = Option("Code", "Images/Lv1 Question 5 B.png", false);
Option opt57 = Option("Star", "Images/Lv1 Question 5 A.png", false);
Option opt58 = Option("Safe", "Images/Lv1 Question 5 B.png", false);
Question que17 = Question("Encrypted Code: \"87 76 80 72\" \n Key: 3", "Images/lv2 Q9 & 10.png", { opt58, opt57, opt56, opt55 }, "M");

Option opt59 = Option("Reck", "Images/Lv1 Question 5 A.png", true);
Option opt60 = Option("Pass", "Images/Lv1 Question 5 B.png", false);
Option opt61 = Option("Open", "Images/Lv1 Question 5 A.png", false);
Option opt62 = Option("Lock", "Images/Lv1 Question 5 B.png", false);
Question que18 = Question("Encrypted Code: \"83 70 68 76\" \n Key: 1", "Images/lv2 Q9 & 10.png", { opt62, opt61, opt60, opt59 }, "M");



//level 3

Option opt63 = Option("True", "Images/lvl3Q1.jpg", true);
Option opt64 = Option("False", "Images/lvl3Q1.jpg", false);
Question que19 = Question("A logical inconsistency:If all humans need oxygen to survive,and Captain doesn’t need oxygen,then Captain is not human.", "Images/lvl3Q1.jpg", { opt63,opt64 }, "M");

Option opt67 = Option("17", "Images/lvl3Q2.jpg", false);
Option opt68 = Option("19", "Images/lvl3Q2.jpg", false);
Option opt69 = Option("21", "Images/lvl3Q2.jpg", true);
Option opt70 = Option("23", "Images/lvl3Q2.jpg", false);
Question que20 = Question("You have to cross a path of tiles in a 4x4 grid. Every tile marked with a prime number is stable. Which of these tile numbers should you avoid?", "Images/lvl3Q2.jpg", { opt67, opt68, opt69, opt70 }, "M");

Option opt71 = Option("2 energy, 2 fuel ,1 coolant ", "Images/Lv13Q3.jpg", false);
Option opt72 = Option("3 energy, 2 fuel , 1 coolant", "Images/Lv13Q3.jpg", true);
Option opt73 = Option("3 energy, 1 fuel ,2 coolant", "Images/Lv13Q3.jpg", false);
Option opt74 = Option("3 energy, 3 fuel , 0 coolant", "Images/Lv13Q3.jpg", false);
Question que21 = Question("you need 3 units of energy ,2 of fuel ,and 1 of coolant , which configuration works?", "Images/Lvl3Q3.jpg", { opt71, opt72, opt73, opt74 }, "M");

Option opt75 = Option("True", "Images/Lvl3Q4.jpg", true);
Option opt76 = Option("False", "Images/Lvl3Q4.jpg", false);
Question que22 = Question("If a sequence follows the pattern 2,4,8,16,32 then the next number is 32 ?", "Images/lvl3Q4.jpg", { opt75, opt76 }, "M");


Option opt77 = Option("AND", "Images/Lv1 Question 5 A.png", false);
Option opt78 = Option("OR", "Images/Lv1 Question 5 B.png", false);
Option opt79 = Option("XOR", "Images/Lv1 Question 5 A.png", true);
Option opt80 = Option("NOT", "Images/Lv1 Question 5 B.png", false);
Question que23 = Question("Which component completes the circuit ,if A=1 and B=0, and Output must be 1 ", "Images/Lvl3Q5.jpg", { opt77, opt78, opt79, opt80 }, "M");


Option opt81 = Option("True", "Images/Lvl3Q6.jpg", true);
Option opt82 = Option("False", "Images/Lv13Q6.jpg", false);
Question que24 = Question("If an object moves 10m in 2s then 30m in 3s , it has the same average speed", "Images/Lvl3Q6.jpg", { opt81, opt82 }, "M");

Option opt85 = Option("Hexagon", "Images/Lvl3Q7.jpg", false);
Option opt86 = Option("Circle", "Images/Lv13Q7.jpg", false);
Option opt87 = Option("Square", "Images/Lv3Q7.jpg", true);
Option opt88 = Option("Pentagon", "Images/Lv3Q7.jpg", false);
Question que25 = Question("Which shape comes next : Circle,Triangle,Square,Circle,Triangle,? ", "Images/Lvl3Q71.jpg", { opt85, opt86,opt87,opt88 }, "M");

Option opt93 = Option("True", "Images/Lvl3Q8.jpg", true);
Option opt94 = Option("False", "Images/Lvl3Q8.jpg", false);
Question que26 = Question("You are given an hourglass that measures 7min and one 4min.You can measure exactly 9min using both", "Images/Lvl3Q8.jpg", { opt93, opt94 }, "M");

Option opt89 = Option("XOR-64-CIRCLE-9", "Images/Lvl3Q9.jpg", false);
Option opt90 = Option("CIRCLE-XOR-64-9", "Images/Lvl3Q9.jpg", false);
Option opt91 = Option("64-CIRCLE-9-XOR", "Images/Lvl3Q9.jpg", true);
Option opt92 = Option("9-64-XOR-CIRCLE", "Images/Lvl3Q9.jpg", false);
Question que27 = Question("Choose the correct sequence based on previous logic steps: ", "Images/Lvl3Q9.jpg", { opt89, opt90, opt91, opt92 }, "M");



Level lev1 = Level("MISSION 1: OPERATION ESCAPE\n"
    "It's the year 2098 and Earth is dying. The skies are red, the oceans are boiling, and the cities are in ruins. The last survivors rush towards the EX-7 Arkship, humanity's only chance of survival. Alert, Alert! \"Captain, we have a problem! The spaceship is not ready! The fuel reserves are unstable, the oxygen supply is low, and we don't have enough space for everyone!\" You, Captain, are the only person skilled enough to pilot the EX-7 Arkship and must make quick life-or-death decisions.\n\n"
    "Your Mission is to Collect essential resources for the journey by answering critical questions.\n\n"
    "Gameplay:\n"
    "- Answer questions correctly to gain fuel.\n"
    "- Incorrect answers will deplete fuel.\n"
    "- If you did not gain any fuel till the end, you'll have to restart the Mission.\n"
    "Time is running out, and every decision counts!\n", { que1, que2, que3, que4, que5, que6, que7, que8 });

Level lev2 = Level("MISSION 2: SECURITY BREACH NEW PLANET\n"
    "The EX-7 Arkship is navigating through the vast expanse of space in search of a new habitable planet. However, the journey is fraught with peril. Crew members must confront catastrophic events, make critical decisions, and confront the harsh reality that survival is not guaranteed.\n\n"
    "To proceed, you must decipher the encryption code to gain access to the new planet. The planetary security systems are armed, and time is of the essence.\n\n"
    " Incorrect answers will decrease fuel and oxygen.\n"
    "Remember Time is running out, and every decision counts!",
    { que9, que10, que11, que12, que13, que14, que16, que15, que17, que18 });

Level lev3 = Level(" You have landed on planet Zuplidon with your crew. The decrypted signal is more than a passcode, it’s a key, and it has just unlocked something far older than your journey.\n\n"
    "From the heart of the platform, an orb of swirling energy lifts into the air.Supremis, the Sentinel of Zuplidon, now awakened from centuries of stasis.\n\n"
    "A trial has begun, one last challenge to determine humanity’s fate on this new world.\n"
    "THERE IS NO TURNING BACK...\n\n", { que19, que20, que21, que22, que23, que24, que25,que26, que27 });


Level Conclusion = Level("The Trial is complete.\n"
    "You have proven the clarity of your mind and the strength of your unity.\n"
    "Welcome to Zuplidon.\n", {});
Level chapters[4] = { lev1, lev2, lev3, Conclusion }; // Initializers levels into an array


void loadNextLevel() {
    if (currLevel < 3) {
        if (currLevel < 0) {
            LevelOneScore = 0;
            LevelTwoScore = 0;
            LevelThreeScore = 0;
        }

        currLevel++;
        currQuestion = -1;

        TotalScore = 0;
        for (int i = 0; i <= currLevel; i++) {
            TotalScore += chapters[i].getNumOfQuestions();
        }

        LevelForm^ secondForm = gcnew LevelForm();
        string scurlevel = "Level " + std::to_string(currLevel + 1);
        if (currLevel == 3) {

			scurlevel = "END!";  

        }
  
        secondForm->BackgroundImage = Image::FromFile("Images/Level " + (currLevel + 1) + ".png");
        secondForm->pbxLevel->Image = Image::FromFile("Images/Level " + (currLevel + 1) + ".png"); // Changes levelform background image to correspond to levels theme image
        secondForm->lblLevel->Text = gcnew System::String(scurlevel.c_str());
        secondForm->lblStoryline->Text = gcnew System::String(chapters[currLevel].getStoryLine().c_str()); // Changes text to correspond with level's story line

        secondForm->Show();
    }
    else {
        // Add Code to display players final score/results
    }
}