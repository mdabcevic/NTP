//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("LoginForm.cpp", Form1);
USEFORM("TravelWarrantInputInfoForm.cpp", Form7);
USEFORM("TestWindow.cpp", Form2);
USEFORM("EmployeeInfoInputForm.cpp", Form6);
USEFORM("DepartmentsForm.cpp", Form5);
USEFORM("Data\AllData.cpp", DataModule1); /* TDataModule: File Type */
USEFORM("CarInfoInputForm.cpp", Form3);
USEFORM("ExpensesInputInfoForm.cpp", Form8);
USEFORM("EmployeesForm.cpp", Form4);
USEFORM("TravelWarrantsForm.cpp", Form9);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TForm2), &Form2);
		Application->CreateForm(__classid(TDataModule1), &DataModule1);
		Application->CreateForm(__classid(TForm3), &Form3);
		Application->CreateForm(__classid(TForm4), &Form4);
		Application->CreateForm(__classid(TForm5), &Form5);
		Application->CreateForm(__classid(TForm6), &Form6);
		Application->CreateForm(__classid(TForm7), &Form7);
		Application->CreateForm(__classid(TForm8), &Form8);
		Application->CreateForm(__classid(TForm9), &Form9);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
