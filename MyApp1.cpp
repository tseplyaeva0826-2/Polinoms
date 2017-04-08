// MyApp1.cpp: главный файл проекта.

#include "stdafx.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

	[STAThreadAttribute]
	void main(cli::array<String^ >^ args) {
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		MyApp1::MyForm ^form = gcnew MyApp1::MyForm();
		Application::Run(form);
	}

