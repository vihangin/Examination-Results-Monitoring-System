#include <windows.h>

#include "Forms\LoginForm.h"

#include "Forms\MainForm.h"



using namespace System;

using namespace System::Windows::Forms;

using namespace ExaminationResultsMonitoringSystem::Forms;



[STAThreadAttribute]

int main(array<System::String^>^ args)

{

    Application::EnableVisualStyles();

    Application::SetCompatibleTextRenderingDefault(false);



    while (true)

    {

        LoginForm^ login = gcnew LoginForm();

        if (login->ShowDialog() == DialogResult::OK && login->AuthenticatedSession != nullptr)

        {

            MainForm^ mainForm = gcnew MainForm(login->AuthenticatedSession);

            Application::Run(mainForm);

        }

        else

        {

            break;

        }

    }

    return 0;

}

