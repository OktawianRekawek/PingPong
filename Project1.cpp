//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 AnsiString strMessage = "Witaj w grze PingPong.\n\n"+
                        "Lewy gracz steruje wciskaj¹c klawisze A oraz Z.\n"+
                        "Prawy gracz steruje wciskaj¹c strza³ki do góry i w dó³.\n"+
                        "\nDla urozmaicenia zabawy:\n"+
                        "Odbicie pi³eczki zmienia k¹t w zale¿noœci od miejsca odbicia\n"+
                        "Co 5 odbiæ pi³eczka przyspiesza, a¿ do osi¹gniêcia maksymalnej prêdkoœci\n\n"+
                        "Mi³ej zabawy!";
                 ShowMessage(strMessage);
                 Application->CreateForm(__classid(TForm1), &Form1);
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
