//---------------------------------------------------------------------------

#ifndef DepartmentsFormH
#define DepartmentsFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <map>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Title;
	TDBGrid *DepartmentsGrid;
	TDBNavigator *DBNavigator1;
private:	// User declarations
public:		// User declarations
	__fastcall TForm5(TComponent* Owner);
    std::map<String, std::map<String, String>> translation;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
