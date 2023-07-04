//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("TestWindow.cpp", Form2);
USEFORM("TravelWarrantInputInfoForm.cpp", Form7);
USEFORM("TravelWarrantsForm.cpp", Form9);
USEFORM("LoginForm.cpp", Form1);
USEFORM("CustomPurposeInfoInputForm.cpp", Form11);
USEFORM("Data\AllData.cpp", DataModule1); /* TDataModule: File Type */
USEFORM("CarInfoInputForm.cpp", Form3);
USEFORM("ClientsInfoForm.cpp", Form10);
USEFORM("CompanyCarsForm.cpp", Form12);
USEFORM("EmployeesForm.cpp", Form4);
USEFORM("ExpensesInputInfoForm.cpp", Form8);
USEFORM("DepartmentsForm.cpp", Form5);
USEFORM("EmployeeInfoInputForm.cpp", Form6);
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
		Application->CreateForm(__classid(TForm10), &Form10);
		Application->CreateForm(__classid(TForm11), &Form11);
		Application->CreateForm(__classid(TForm12), &Form12);
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
