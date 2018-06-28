//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ActnList.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <Dialogs.hpp>
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *Plik1;
	TMenuItem *Otw1;
	TPanel *Panel1;
	TImageList *ImageList1;
	TActionList *ActionList1;
	TAction *Otworz;
	TAction *Zapisz;
	TAction *StatystykaWyrazow;
	TMenuItem *Zapisz1;
	TMenuItem *StatystykaWyrazow1;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TPageControl *PageControl1;
	TAction *Nowy;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TMenuItem *Nowy1;
	TPopupMenu *PopupMenu1;
	TMenuItem *Nowy2;
	TMenuItem *Otworz1;
	TMenuItem *Zapisz2;
	TMenuItem *Statystykawyrazow2;
	TAction *Zamknij;
	TToolButton *ToolButton7;
	TMenuItem *Zamknij1;
	TStatusBar *StatusBar1;
	TAction *UaktualnijStatystyki;
	TFontDialog *FontDialog1;
	TToolButton *ToolButton8;
	TAction *Pogrubienie;
	TAction *Pochylenie;
	TAction *Podkreslenie;
	TToolButton *ToolButton9;
	TToolButton *ToolButton10;
	TToolButton *ToolButton11;
	TMenuItem *Format1;
	TMenuItem *Pogrubienie1;
	TMenuItem *Pochylenie1;
	TMenuItem *Podkrelenie1;
	TAction *Czcionka;
	TToolButton *ToolButton12;
	TToolButton *ToolButton13;
	TMenuItem *Czcionka1;
	void __fastcall OtworzExecute(TObject *Sender);
	void __fastcall ZapiszExecute(TObject *Sender);
	void __fastcall NowyExecute(TObject *Sender);
	void __fastcall ZamknijExecute(TObject *Sender);
	void __fastcall UaktualnijStatystykiExecute(TObject *Sender);
	void __fastcall StatystykaWyrazowExecute(TObject *Sender);
	void __fastcall PogrubienieExecute(TObject *Sender);
	void __fastcall PochylenieExecute(TObject *Sender);
	void __fastcall PodkreslenieExecute(TObject *Sender);
	void __fastcall CzcionkaExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);

};
TStringList *Tokenize (String s,String delimiter);

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
