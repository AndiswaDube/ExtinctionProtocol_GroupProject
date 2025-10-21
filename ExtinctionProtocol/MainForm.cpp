#include "MainForm.h"
#include "GameInfo.h"



using namespace System;
using namespace System::Windows::Forms;
using namespace ExtinctionProtocol;
using namespace System::IO; // For File Handling

int main()
{
    // Ensure the users.txt file exists
    if (!File::Exists("users.txt")) {
        StreamWriter^ writer = gcnew StreamWriter("users.txt", true);
        writer->Close();
    }

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    ExtinctionProtocol::MainForm form;
    Application::Run(% form); // Start the application

    return 0;
}