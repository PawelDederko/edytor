//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include <string>  
using namespace std;

#define max_n_znakow 20
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	TDocument *Zakladka = new TDocument(PageControl1);
	Zakladka->RichEdit->OnChange = UaktualnijStatystykiExecute;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OtworzExecute(TObject *Sender)
{
	if(OpenDialog1->Execute()) {
			TDocument *Zakladka;
			Zakladka = new TDocument(PageControl1);
			Zakladka->LoadFromFile(OpenDialog1->FileName);
			PageControl1->ActivePageIndex = (PageControl1->PageCount - 1);
			Zakladka->RichEdit->OnChange = UaktualnijStatystykiExecute;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ZapiszExecute(TObject *Sender)
{
	if(SaveDialog1->Execute()) {
		//TTabSheet *Zakladka1;
		//Zakladka1 = PageControl1->ActivePage;

		//void *Zakladka2 = dynamic_cast<void *>(Zakladka1);



		if(TDocument* Zakladka1 = dynamic_cast<TDocument*>(PageControl1->ActivePage))
		{
			Zakladka1->SaveToFile(SaveDialog1->FileName);
		}

		//void *Zakladka4 = dynamic_cast<void *>(Zakladka3);

	//	TDocument *Zakladka2;
	//	Zakladka2->ActivePage->RichEdit->Lines->SaveToFile(SaveDialog1->FileName);
	//	Zakladka = new TDocument(PageControl1->ActivePage);
	//	Zakladka = dynamic_cast<void *>(PageControl1->ActivePage);
	//	Zakladka->SaveToFile(SaveDialog1->FileName);
    }
//	if(SaveDialog1->Execute()) {
//		RichEdit1->Lines->SaveToFile(SaveDialog1->FileName);
//	}
}
//---------------------------------------------------------------------------

TStringList *Tokenize (String s,String delimiter)
{
 TStringList *StringList;
 int l;
 int start,delimp;
 String sub;
 StringList = new TStringList();
 start=0;
 if (s.Pos(delimiter)>0)
 {
 delimp = s.Pos(delimiter);
 do
 {
 l=s.Length();
 sub=s.SubString(start,delimp-1);
 if (sub != "") StringList->Add(sub);
 s=s.SubString(delimp+1,l-delimp);
 delimp = s.Pos(delimiter);
 } while (delimp != 0);
 StringList->Add(s);
 }
 else StringList->Add(s);
 return StringList;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NowyExecute(TObject *Sender)
{

	TDocument *Zakladka;
	Zakladka = new TDocument(PageControl1);
	Zakladka->RichEdit->OnChange = UaktualnijStatystykiExecute;

	PageControl1->ActivePageIndex = (PageControl1->PageCount - 1);

}
void __fastcall TForm1::ZamknijExecute(TObject *Sender)
{
	delete PageControl1->ActivePage;
	PageControl1->ActivePageIndex = (PageControl1->PageCount - 1);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::UaktualnijStatystykiExecute(TObject *Sender)
{
	if(TDocument* Zakladka1 = dynamic_cast<TDocument*>(PageControl1->ActivePage))
		{
			TStrings *tekst = Zakladka1->RichEdit->Lines;

			std::string napis;
			AnsiString str = Zakladka1->RichEdit->Lines->GetText();
			napis = str.c_str();
			string::size_type pos = 0;
			while ( ( pos = napis.find ("\r\n",pos) ) != string::npos )
			{
				napis.erase ( pos, 2 );
			}
			int liczbaZnakow = napis.length();

			StatusBar1->Panels->Items[0]->Text = "Znaków: " + IntToStr(liczbaZnakow);
			TStringList *wyrazy = Tokenize(tekst->Text," ");
			StatusBar1->Panels->Items[1]->Text = "Wyrazów: " + IntToStr(wyrazy->Count);
			TStringList *zdania = Tokenize(tekst->Text,". ");
			StatusBar1->Panels->Items[2]->Text = "Zdañ: " + IntToStr(zdania->Count);
			TStringList *akapity = Tokenize(tekst->Text,"\n\r\n");
			StatusBar1->Panels->Items[3]->Text = "Akapitów: " + IntToStr(akapity->Count);

		}
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

void __fastcall TForm1::StatystykaWyrazowExecute(TObject *Sender)
{
if(TDocument* Zakladka1 = dynamic_cast<TDocument*>(PageControl1->ActivePage))
		{

			TStrings *tekst = Zakladka1->RichEdit->Lines;

			std::string napis;
			AnsiString str = Zakladka1->RichEdit->Lines->GetText();
			napis = str.c_str();
			string::size_type pos = 0;
			while ( ( pos = napis.find ("\r\n",pos) ) != string::npos )
			{
				napis.replace(napis.find("\r\n"), 2, " ");
			}

		int i, dlugoscSlowa = 0, najdluzszy = 0, elementTablicy = 0;
		int TablicaWynikowa[max_n_znakow+1];
		for (i = 1; i<= max_n_znakow; i++)
				TablicaWynikowa[i] = 0;



		for (i = 0; i < napis.length(); i++) {

			if (napis[i]==' ') {

				if (dlugoscSlowa > max_n_znakow) {
					elementTablicy = max_n_znakow;
				} else {
					elementTablicy = dlugoscSlowa;
				}

				TablicaWynikowa[elementTablicy]++;

				if (najdluzszy < dlugoscSlowa) {
					najdluzszy = dlugoscSlowa;
				}
				dlugoscSlowa = 0;
			} else {
				if (napis[i]!='.' && napis[i]!=',' && napis[i]!=';' && napis[i]!=':') {
					dlugoscSlowa++;
				}

            }

		}

			Form3->Show();
			Form3->StringGrid1->Cells[0][0] = "Liczba znaków";
			Form3->StringGrid1->Cells[1][0] = "Liczba s³ów";

			if (najdluzszy > max_n_znakow) {
				 najdluzszy = max_n_znakow;
			}

			Form3->StringGrid1->RowCount = najdluzszy + 1;

			for (int i = 1; i <= najdluzszy; i++) {
				 Form3->StringGrid1->Cells[0][i] = i;
				 Form3->StringGrid1->Cells[1][i] = TablicaWynikowa[i];
			}

		}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PogrubienieExecute(TObject *Sender)
{
 	if(TDocument* Zakladka1 = dynamic_cast<TDocument*>(PageControl1->ActivePage))
		{
			Zakladka1->RichEdit->SelAttributes->Style = Zakladka1->RichEdit->SelAttributes->Style << fsBold;
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PochylenieExecute(TObject *Sender)
{
 	if(TDocument* Zakladka1 = dynamic_cast<TDocument*>(PageControl1->ActivePage))
		{
			Zakladka1->RichEdit->SelAttributes->Style = Zakladka1->RichEdit->SelAttributes->Style << fsItalic;
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PodkreslenieExecute(TObject *Sender)
{
	if(TDocument* Zakladka1 = dynamic_cast<TDocument*>(PageControl1->ActivePage))
		{
			Zakladka1->RichEdit->SelAttributes->Style = Zakladka1->RichEdit->SelAttributes->Style << fsUnderline;
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CzcionkaExecute(TObject *Sender)
{
	if (FontDialog1->Execute()) {
    	if(TDocument* Zakladka1 = dynamic_cast<TDocument*>(PageControl1->ActivePage))
		{
			Graphics::TFont* theFont = FontDialog1->Font;
			Zakladka1->RichEdit->SelAttributes->Charset = theFont->Charset;
			Zakladka1->RichEdit->SelAttributes->Color = theFont->Color;
			Zakladka1->RichEdit->SelAttributes->Height = theFont->Height;
			Zakladka1->RichEdit->SelAttributes->Name = theFont->Name;
			Zakladka1->RichEdit->SelAttributes->Pitch = theFont->Pitch;
			Zakladka1->RichEdit->SelAttributes->Size = theFont->Size;
			
		}
    }		
}
//---------------------------------------------------------------------------

