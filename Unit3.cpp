//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}


void __fastcall TForm3::FormKeyPress(TObject *Sender, char &Key)
{
	if (Key == char(27)) Close();
}
//---------------------------------------------------------------------------
