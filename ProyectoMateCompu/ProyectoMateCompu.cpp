#include "ProyectoMateCompu.h"

using namespace System;
using namespace System::Windows::Forms; [STAThread]
void main(array<String^>^ arg)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew ProyectoMateCompu::ProyectoMateCompu()); //Nombre del proyecto
}