#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ args)
{

    Application::EnableVisualStyles();

    Application::SetCompatibleTextRenderingDefault(false);

    CIS376CompareTreesTermProject::MyForm form;

    Application::Run(% form);

}
